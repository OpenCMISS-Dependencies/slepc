/*
   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   SLEPc - Scalable Library for Eigenvalue Problem Computations
   Copyright (c) 2002-2014, Universitat Politecnica de Valencia, Spain

   This file is part of SLEPc.

   SLEPc is free software: you can redistribute it and/or modify it under  the
   terms of version 3 of the GNU Lesser General Public License as published by
   the Free Software Foundation.

   SLEPc  is  distributed in the hope that it will be useful, but WITHOUT  ANY
   WARRANTY;  without even the implied warranty of MERCHANTABILITY or  FITNESS
   FOR  A  PARTICULAR PURPOSE. See the GNU Lesser General Public  License  for
   more details.

   You  should have received a copy of the GNU Lesser General  Public  License
   along with SLEPc. If not, see <http://www.gnu.org/licenses/>.
   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

static char help[] = "Delay differential equation.\n\n"
  "The command line options are:\n"
  "  -n <n>, where <n> = number of grid subdivisions.\n"
  "  -tau <tau>, where <tau> is the delay parameter.\n\n";

/*
   Solve parabolic partial differential equation with time delay tau

            u_t = u_xx + a*u(t) + b*u(t-tau)
            u(0,t) = u(pi,t) = 0

   with a = 20 and b(x) = -4.1+x*(1-exp(x-pi)).

   Discretization leads to a DDE of dimension n

            -u' = A*u(t) + B*u(t-tau)

   which results in the nonlinear eigenproblem

            (-lambda*I + A + exp(-tau*lambda)*B)*u = 0
*/

#include <slepcnep.h>

#undef __FUNCT__
#define __FUNCT__ "main"
int main(int argc,char **argv)
{
  NEP            nep;             /* nonlinear eigensolver context */
  PetscScalar    kr,ki;           /* eigenvalue */
  Mat            Id,A,B;          /* problem matrices */
  FN             f1,f2,f3;        /* functions to define the nonlinear operator */
  Mat            mats[3];
  FN             funs[3];
  NEPType        type;
  PetscScalar    value[3],coeffs[2],b;
  PetscInt       n=128,nev,Istart,Iend,col[3],i,its,nconv;
  PetscReal      tau=0.001,h,a=20,xi,re,im,norm;
  PetscBool      FirstBlock=PETSC_FALSE,LastBlock=PETSC_FALSE;
  PetscErrorCode ierr;

  SlepcInitialize(&argc,&argv,(char*)0,help);
  ierr = PetscOptionsGetInt(NULL,"-n",&n,NULL);CHKERRQ(ierr);
  ierr = PetscOptionsGetReal(NULL,"-tau",&tau,NULL);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD,"\n1-D Delay Eigenproblem, n=%D, tau=%g\n\n",n,(double)tau);CHKERRQ(ierr);
  h = PETSC_PI/(PetscReal)(n+1);

  /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
     Create nonlinear eigensolver context
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

  ierr = NEPCreate(PETSC_COMM_WORLD,&nep);CHKERRQ(ierr);

  /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
     Create problem matrices and coefficient functions. Pass them to NEP
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

  /*
     Identity matrix
  */
  ierr = MatCreate(PETSC_COMM_WORLD,&Id);CHKERRQ(ierr);
  ierr = MatSetSizes(Id,PETSC_DECIDE,PETSC_DECIDE,n,n);CHKERRQ(ierr);
  ierr = MatSetFromOptions(Id);CHKERRQ(ierr);
  ierr = MatSetUp(Id);CHKERRQ(ierr);
  ierr = MatAssemblyBegin(Id,MAT_FINAL_ASSEMBLY);CHKERRQ(ierr);
  ierr = MatAssemblyEnd(Id,MAT_FINAL_ASSEMBLY);CHKERRQ(ierr);
  ierr = MatShift(Id,1.0);CHKERRQ(ierr);
  ierr = MatSetOption(Id,MAT_HERMITIAN,PETSC_TRUE);CHKERRQ(ierr);

  /*
     A = 1/h^2*tridiag(1,-2,1) + a*I
  */
  ierr = MatCreate(PETSC_COMM_WORLD,&A);CHKERRQ(ierr);
  ierr = MatSetSizes(A,PETSC_DECIDE,PETSC_DECIDE,n,n);CHKERRQ(ierr);
  ierr = MatSetFromOptions(A);CHKERRQ(ierr);
  ierr = MatSetUp(A);CHKERRQ(ierr);
  ierr = MatGetOwnershipRange(A,&Istart,&Iend);CHKERRQ(ierr);
  if (Istart==0) FirstBlock=PETSC_TRUE;
  if (Iend==n) LastBlock=PETSC_TRUE;
  value[0]=1.0/(h*h); value[1]=-2.0/(h*h)+a; value[2]=1.0/(h*h);
  for (i=(FirstBlock? Istart+1: Istart); i<(LastBlock? Iend-1: Iend); i++) {
    col[0]=i-1; col[1]=i; col[2]=i+1;
    ierr = MatSetValues(A,1,&i,3,col,value,INSERT_VALUES);CHKERRQ(ierr);
  }
  if (LastBlock) {
    i=n-1; col[0]=n-2; col[1]=n-1;
    ierr = MatSetValues(A,1,&i,2,col,value,INSERT_VALUES);CHKERRQ(ierr);
  }
  if (FirstBlock) {
    i=0; col[0]=0; col[1]=1; value[0]=-2.0/(h*h)+a; value[1]=1.0/(h*h);
    ierr = MatSetValues(A,1,&i,2,col,value,INSERT_VALUES);CHKERRQ(ierr);
  }
  ierr = MatAssemblyBegin(A,MAT_FINAL_ASSEMBLY);CHKERRQ(ierr);
  ierr = MatAssemblyEnd(A,MAT_FINAL_ASSEMBLY);CHKERRQ(ierr);
  ierr = MatSetOption(A,MAT_HERMITIAN,PETSC_TRUE);CHKERRQ(ierr);

  /*
     B = diag(b(xi))
  */
  ierr = MatCreate(PETSC_COMM_WORLD,&B);CHKERRQ(ierr);
  ierr = MatSetSizes(B,PETSC_DECIDE,PETSC_DECIDE,n,n);CHKERRQ(ierr);
  ierr = MatSetFromOptions(B);CHKERRQ(ierr);
  ierr = MatSetUp(B);CHKERRQ(ierr);
  ierr = MatGetOwnershipRange(B,&Istart,&Iend);CHKERRQ(ierr);
  for (i=Istart;i<Iend;i++) {
    xi = (i+1)*h;
    b = -4.1+xi*(1.0-PetscExpReal(xi-PETSC_PI));
    ierr = MatSetValues(B,1,&i,1,&i,&b,INSERT_VALUES);CHKERRQ(ierr);
  }
  ierr = MatAssemblyBegin(B,MAT_FINAL_ASSEMBLY);CHKERRQ(ierr);
  ierr = MatAssemblyEnd(B,MAT_FINAL_ASSEMBLY);CHKERRQ(ierr);
  ierr = MatSetOption(B,MAT_HERMITIAN,PETSC_TRUE);CHKERRQ(ierr);

  /*
     Functions: f1=-lambda, f2=1.0, f3=exp(-tau*lambda)
  */
  ierr = FNCreate(PETSC_COMM_WORLD,&f1);CHKERRQ(ierr);
  ierr = FNSetType(f1,FNRATIONAL);CHKERRQ(ierr);
  coeffs[0] = -1.0; coeffs[1] = 0.0;
  ierr = FNSetParameters(f1,2,coeffs,0,NULL);CHKERRQ(ierr);

  ierr = FNCreate(PETSC_COMM_WORLD,&f2);CHKERRQ(ierr);
  ierr = FNSetType(f2,FNRATIONAL);CHKERRQ(ierr);
  coeffs[0] = 1.0;
  ierr = FNSetParameters(f2,1,coeffs,0,NULL);CHKERRQ(ierr);

  ierr = FNCreate(PETSC_COMM_WORLD,&f3);CHKERRQ(ierr);
  ierr = FNSetType(f3,FNEXP);CHKERRQ(ierr);
  coeffs[0] = -tau;
  ierr = FNSetParameters(f3,1,coeffs,0,NULL);CHKERRQ(ierr);

  /*
     Set the split operator. Note that A is passed first so that
     SUBSET_NONZERO_PATTERN can be used
  */
  mats[0] = A;  funs[0] = f2;
  mats[1] = Id; funs[1] = f1;
  mats[2] = B;  funs[2] = f3;
  ierr = NEPSetSplitOperator(nep,3,mats,funs,SUBSET_NONZERO_PATTERN);CHKERRQ(ierr);

  /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
             Customize nonlinear solver; set runtime options
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

  ierr = NEPSetTolerances(nep,PETSC_DEFAULT,1e-9,PETSC_DEFAULT,PETSC_DEFAULT,PETSC_DEFAULT);CHKERRQ(ierr);
  ierr = NEPSetDimensions(nep,1,PETSC_DEFAULT,PETSC_DEFAULT);CHKERRQ(ierr);
  ierr = NEPSetLagPreconditioner(nep,0);CHKERRQ(ierr);

  /*
     Set solver parameters at runtime
  */
  ierr = NEPSetFromOptions(nep);CHKERRQ(ierr);

  /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                      Solve the eigensystem
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

  ierr = NEPSolve(nep);CHKERRQ(ierr);
  ierr = NEPGetIterationNumber(nep,&its);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD," Number of NEP iterations = %D\n\n",its);CHKERRQ(ierr);

  /*
     Optional: Get some information from the solver and display it
  */
  ierr = NEPGetType(nep,&type);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD," Solution method: %s\n",type);CHKERRQ(ierr);
  ierr = NEPGetDimensions(nep,&nev,NULL,NULL);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD," Number of requested eigenvalues: %D\n",nev);CHKERRQ(ierr);

  /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
                    Display solution and clean up
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

  /*
     Get number of converged approximate eigenpairs
  */
  ierr = NEPGetConverged(nep,&nconv);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD," Number of converged approximate eigenpairs: %D\n\n",nconv);CHKERRQ(ierr);

  if (nconv>0) {
    /*
       Display eigenvalues and relative errors
    */
    ierr = PetscPrintf(PETSC_COMM_WORLD,
         "           k              ||T(k)x||\n"
         "   ----------------- ------------------\n");CHKERRQ(ierr);
    for (i=0;i<nconv;i++) {
      ierr = NEPGetEigenpair(nep,i,&kr,&ki,NULL,NULL);CHKERRQ(ierr);
      ierr = NEPComputeRelativeError(nep,i,&norm);CHKERRQ(ierr);
#if defined(PETSC_USE_COMPLEX)
      re = PetscRealPart(kr);
      im = PetscImaginaryPart(kr);
#else
      re = kr;
      im = ki;
#endif
      if (im!=0.0) {
        ierr = PetscPrintf(PETSC_COMM_WORLD," %9f%+9f j %12g\n",(double)re,(double)im,(double)norm);CHKERRQ(ierr);
      } else {
        ierr = PetscPrintf(PETSC_COMM_WORLD,"   %12f         %12g\n",(double)re,(double)norm);CHKERRQ(ierr);
      }
    }
    ierr = PetscPrintf(PETSC_COMM_WORLD,"\n");CHKERRQ(ierr);
  }

  ierr = NEPDestroy(&nep);CHKERRQ(ierr);
  ierr = MatDestroy(&Id);CHKERRQ(ierr);
  ierr = MatDestroy(&A);CHKERRQ(ierr);
  ierr = MatDestroy(&B);CHKERRQ(ierr);
  ierr = FNDestroy(&f1);CHKERRQ(ierr);
  ierr = FNDestroy(&f2);CHKERRQ(ierr);
  ierr = FNDestroy(&f3);CHKERRQ(ierr);
  ierr = SlepcFinalize();
  return 0;
}

