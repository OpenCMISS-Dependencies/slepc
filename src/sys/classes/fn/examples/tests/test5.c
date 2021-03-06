/*
   - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
   SLEPc - Scalable Library for Eigenvalue Problem Computations
   Copyright (c) 2002-2015, Universitat Politecnica de Valencia, Spain

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

static char help[] = "Test matrix rational function.\n\n";

#include <slepcfn.h>

#undef __FUNCT__
#define __FUNCT__ "main"
int main(int argc,char **argv)
{
  PetscErrorCode ierr;
  FN             fn;
  Mat            A,B;
  PetscInt       i,j,n=10,np,nq;
  PetscReal      nrm;
  PetscScalar    *As,p[10],q[10];
  PetscViewer    viewer;
  PetscBool      verbose;

  SlepcInitialize(&argc,&argv,(char*)0,help);
  ierr = PetscOptionsGetInt(NULL,"-n",&n,NULL);CHKERRQ(ierr);
  ierr = PetscOptionsHasName(NULL,"-verbose",&verbose);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD,"Matrix rational function, n=%D.\n",n);CHKERRQ(ierr);

  /* Create rational function r(x)=p(x)/q(x) */
  ierr = FNCreate(PETSC_COMM_WORLD,&fn);CHKERRQ(ierr);
  ierr = FNSetType(fn,FNRATIONAL);CHKERRQ(ierr);
  np = 2; nq = 3;
  p[0] = -3.1; p[1] = 1.1;
  q[0] = 1.0; q[1] = -2.0; q[2] = 3.5;
  ierr = FNRationalSetNumerator(fn,np,p);CHKERRQ(ierr);
  ierr = FNRationalSetDenominator(fn,nq,q);CHKERRQ(ierr);
  ierr = FNSetFromOptions(fn);CHKERRQ(ierr);

  /* Set up viewer */
  ierr = PetscViewerASCIIGetStdout(PETSC_COMM_WORLD,&viewer);CHKERRQ(ierr);
  ierr = FNView(fn,viewer);CHKERRQ(ierr);
  if (verbose) {
    ierr = PetscViewerPushFormat(viewer,PETSC_VIEWER_ASCII_MATLAB);CHKERRQ(ierr);
  }

  /* Create matrices */
  ierr = MatCreateSeqDense(PETSC_COMM_SELF,n,n,NULL,&A);CHKERRQ(ierr);
  ierr = PetscObjectSetName((PetscObject)A,"A");CHKERRQ(ierr);
  ierr = MatCreateSeqDense(PETSC_COMM_SELF,n,n,NULL,&B);CHKERRQ(ierr);
  ierr = PetscObjectSetName((PetscObject)B,"B");CHKERRQ(ierr);

  /* Fill A with a symmetric Toeplitz matrix */
  ierr = MatDenseGetArray(A,&As);CHKERRQ(ierr);
  for (i=0;i<n;i++) As[i+i*n]=2.0;
  for (j=1;j<3;j++) {
    for (i=0;i<n-j;i++) { As[i+(i+j)*n]=1.0; As[(i+j)+i*n]=1.0; }
  }
  ierr = MatDenseRestoreArray(A,&As);CHKERRQ(ierr);
  ierr = MatSetOption(A,MAT_HERMITIAN,PETSC_TRUE);CHKERRQ(ierr);
  if (verbose) {
    ierr = PetscPrintf(PETSC_COMM_WORLD,"Matrix A - - - - - - - -\n");CHKERRQ(ierr);
    ierr = MatView(A,viewer);CHKERRQ(ierr);
  }

  /* Evaluate matrix function */
  ierr = FNEvaluateFunctionMat(fn,A,B);CHKERRQ(ierr);
  if (verbose) {
    ierr = PetscPrintf(PETSC_COMM_WORLD,"Computed f(A) - - - - - - -\n");CHKERRQ(ierr);
    ierr = MatView(B,viewer);CHKERRQ(ierr);
  }
  ierr = MatNorm(B,NORM_1,&nrm);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD,"The 1-norm of f(A) is %g\n",(double)nrm);CHKERRQ(ierr);

  /* Repeat with same matrix as non-symmetric */
  ierr = MatSetOption(A,MAT_HERMITIAN,PETSC_FALSE);CHKERRQ(ierr);

  /* Evaluate matrix function */
  ierr = FNEvaluateFunctionMat(fn,A,B);CHKERRQ(ierr);
  if (verbose) {
    ierr = PetscPrintf(PETSC_COMM_WORLD,"Computed f(A) - - - - - - -\n");CHKERRQ(ierr);
    ierr = MatView(B,viewer);CHKERRQ(ierr);
  }
  ierr = MatNorm(B,NORM_1,&nrm);CHKERRQ(ierr);
  ierr = PetscPrintf(PETSC_COMM_WORLD,"The 1-norm of f(A) is %g\n",(double)nrm);CHKERRQ(ierr);

  ierr = MatDestroy(&A);CHKERRQ(ierr);
  ierr = MatDestroy(&B);CHKERRQ(ierr);
  ierr = FNDestroy(&fn);CHKERRQ(ierr);
  ierr = SlepcFinalize();
  return 0;
}
