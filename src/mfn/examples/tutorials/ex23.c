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

static char help[] = "Computes exp(A)*v for a matrix associated with a Markov model.\n\n"
  "The command line options are:\n"
  "  -m <m>, where <m> = number of grid subdivisions in each dimension.\n\n";

#include <slepcmfn.h>

/*
   User-defined routines
*/
PetscErrorCode MatMarkovModel(PetscInt m,Mat A);

#undef __FUNCT__
#define __FUNCT__ "main"
int main(int argc,char **argv)
{
  Mat                A;           /* problem matrix */
  MFN                mfn;
  PetscReal          tol,norm;
  PetscScalar        t;
  Vec                v,y;
  PetscInt           N,m=15,ncv,maxit,its;
  PetscErrorCode     ierr;
  PetscBool          draw_sol;
  MFNConvergedReason reason;

  SlepcInitialize(&argc,&argv,(char*)0,help);

  ierr = PetscOptionsGetInt(NULL,"-m",&m,NULL);CHKERRQ(ierr);
  N = m*(m+1)/2;
  ierr = PetscPrintf(PETSC_COMM_WORLD,"\nMarkov y=exp(t*A)*e_1, N=%D (m=%D)\n\n",N,m);CHKERRQ(ierr);

  ierr = PetscOptionsHasName(PETSC_NULL,"-draw_sol",&draw_sol);CHKERRQ(ierr);

  /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
            Compute the transition probability matrix, A
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

  ierr = MatCreate(PETSC_COMM_WORLD,&A);CHKERRQ(ierr);
  ierr = MatSetSizes(A,PETSC_DECIDE,PETSC_DECIDE,N,N);CHKERRQ(ierr);
  ierr = MatSetFromOptions(A);CHKERRQ(ierr);
  ierr = MatSetUp(A);CHKERRQ(ierr);
  ierr = MatMarkovModel(m,A);CHKERRQ(ierr);

  /* set v = e_1 */
  ierr = MatGetVecs(A,PETSC_NULL,&y);CHKERRQ(ierr);
  ierr = MatGetVecs(A,PETSC_NULL,&v);CHKERRQ(ierr);
  ierr = VecSetValue(v,1,1.0,INSERT_VALUES);CHKERRQ(ierr);
  ierr = VecAssemblyBegin(v);CHKERRQ(ierr);
  ierr = VecAssemblyEnd(v);CHKERRQ(ierr);

  /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
                Create the solver and set various options
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
  /* 
     Create matrix function solver context
  */
  ierr = MFNCreate(PETSC_COMM_WORLD,&mfn);CHKERRQ(ierr);

  /* 
     Set operator matrix, the function to compute, and other options
  */
  ierr = MFNSetOperator(mfn,A);CHKERRQ(ierr);
  ierr = MFNSetFunction(mfn,SLEPC_FUNCTION_EXP);CHKERRQ(ierr);
  ierr = MFNSetTolerances(mfn,1e-07,PETSC_DEFAULT);CHKERRQ(ierr);

  /*
     Set solver parameters at runtime
  */
  ierr = MFNSetFromOptions(mfn);CHKERRQ(ierr);

  /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
                      Solve the problem, y=exp(A)*v
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

  ierr = MFNSolve(mfn,v,y);CHKERRQ(ierr);
  ierr = MFNGetConvergedReason(mfn,&reason);CHKERRQ(ierr);
  if (reason!=MFN_CONVERGED_TOL) SETERRQ(PETSC_COMM_WORLD,1,"Solver did not converge");
  ierr = VecNorm(y,NORM_2,&norm);CHKERRQ(ierr);
  
  /*
     Optional: Get some information from the solver and display it
  */
  ierr = MFNGetIterationNumber(mfn,&its);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD," Number of iterations of the method: %D\n",its);CHKERRQ(ierr);
  ierr = MFNGetDimensions(mfn,&ncv);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD," Subspace dimension: %D\n",ncv);CHKERRQ(ierr);
  ierr = MFNGetTolerances(mfn,&tol,&maxit);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD," Stopping condition: tol=%.4g, maxit=%D\n",(double)tol,maxit);CHKERRQ(ierr);

  /* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 
                    Display solution and clean up
     - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
  ierr = MFNGetScaleFactor(mfn,&t);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD," Computed vector at time t=%.4g has norm %g\n\n",(double)PetscRealPart(t),(double)norm);CHKERRQ(ierr);
  if (draw_sol) {
    ierr = PetscViewerDrawSetPause(PETSC_VIEWER_DRAW_WORLD,-1);CHKERRQ(ierr);
    ierr = VecView(y,PETSC_VIEWER_DRAW_WORLD);CHKERRQ(ierr);
  }

  /* 
     Free work space
  */
  ierr = MFNDestroy(&mfn);CHKERRQ(ierr);
  ierr = MatDestroy(&A);CHKERRQ(ierr);
  ierr = VecDestroy(&v);CHKERRQ(ierr);
  ierr = VecDestroy(&y);CHKERRQ(ierr);
  ierr = SlepcFinalize();CHKERRQ(ierr);
  return 0;
}

#undef __FUNCT__
#define __FUNCT__ "MatMarkovModel"
/*
    Matrix generator for a Markov model of a random walk on a triangular grid.
    See ex5.c for additional details.
*/
PetscErrorCode MatMarkovModel(PetscInt m,Mat A)
{
  const PetscReal cst = 0.5/(PetscReal)(m-1);
  PetscReal       pd,pu;
  PetscInt        Istart,Iend,i,j,jmax,ix=0;
  PetscErrorCode  ierr;

  PetscFunctionBeginUser;
  ierr = MatGetOwnershipRange(A,&Istart,&Iend);CHKERRQ(ierr);
  for (i=1;i<=m;i++) {
    jmax = m-i+1;
    for (j=1;j<=jmax;j++) {
      ix = ix + 1;
      if (ix-1<Istart || ix>Iend) continue;  /* compute only owned rows */
      if (j!=jmax) {
        pd = cst*(PetscReal)(i+j-1);
        /* north */
        if (i==1) {
          ierr = MatSetValue(A,ix-1,ix,2*pd,INSERT_VALUES);CHKERRQ(ierr);
        } else {
          ierr = MatSetValue(A,ix-1,ix,pd,INSERT_VALUES);CHKERRQ(ierr);
        }
        /* east */
        if (j==1) {
          ierr = MatSetValue(A,ix-1,ix+jmax-1,2*pd,INSERT_VALUES);CHKERRQ(ierr);
        } else {
          ierr = MatSetValue(A,ix-1,ix+jmax-1,pd,INSERT_VALUES);CHKERRQ(ierr);
        }
      }
      /* south */
      pu = 0.5 - cst*(PetscReal)(i+j-3);
      if (j>1) {
        ierr = MatSetValue(A,ix-1,ix-2,pu,INSERT_VALUES);CHKERRQ(ierr);
      }
      /* west */
      if (i>1) {
        ierr = MatSetValue(A,ix-1,ix-jmax-2,pu,INSERT_VALUES);CHKERRQ(ierr);
      }
    }
  }
  ierr = MatAssemblyBegin(A,MAT_FINAL_ASSEMBLY);CHKERRQ(ierr);
  ierr = MatAssemblyEnd(A,MAT_FINAL_ASSEMBLY);CHKERRQ(ierr);
  PetscFunctionReturn(0);
}

