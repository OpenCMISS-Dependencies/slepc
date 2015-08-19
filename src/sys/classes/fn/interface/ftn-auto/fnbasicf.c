#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* fnbasic.c */
/* Fortran interface file */

/*
* This file was generated automatically by bfort from the C source
* file.  
 */

#ifdef PETSC_USE_POINTER_CONVERSION
#if defined(__cplusplus)
extern "C" { 
#endif 
extern void *PetscToPointer(void*);
extern int PetscFromPointer(void *);
extern void PetscRmPointer(void*);
#if defined(__cplusplus)
} 
#endif 

#else

#define PetscToPointer(a) (*(PetscFortranAddr *)(a))
#define PetscFromPointer(a) (PetscFortranAddr)(a)
#define PetscRmPointer(a)
#endif

#include "slepcfn.h"
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fncreate_ FNCREATE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fncreate_ fncreate
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fnsetscale_ FNSETSCALE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fnsetscale_ fnsetscale
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fngetscale_ FNGETSCALE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fngetscale_ fngetscale
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fnevaluatefunction_ FNEVALUATEFUNCTION
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fnevaluatefunction_ fnevaluatefunction
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fnevaluatederivative_ FNEVALUATEDERIVATIVE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fnevaluatederivative_ fnevaluatederivative
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fnevaluatefunctionmat_ FNEVALUATEFUNCTIONMAT
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fnevaluatefunctionmat_ fnevaluatefunctionmat
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fnsetfromoptions_ FNSETFROMOPTIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fnsetfromoptions_ fnsetfromoptions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fnduplicate_ FNDUPLICATE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fnduplicate_ fnduplicate
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fndestroy_ FNDESTROY
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fndestroy_ fndestroy
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  fncreate_(MPI_Fint * comm,FN *newfn, int *__ierr ){
*__ierr = FNCreate(
	MPI_Comm_f2c( *(comm) ),
	(FN* )PetscToPointer((newfn) ));
}
PETSC_EXTERN void PETSC_STDCALL  fnsetscale_(FN *fn,PetscScalar *alpha,PetscScalar *beta, int *__ierr ){
*__ierr = FNSetScale(*fn,*alpha,*beta);
}
PETSC_EXTERN void PETSC_STDCALL  fngetscale_(FN *fn,PetscScalar *alpha,PetscScalar *beta, int *__ierr ){
*__ierr = FNGetScale(*fn,alpha,beta);
}
PETSC_EXTERN void PETSC_STDCALL  fnevaluatefunction_(FN *fn,PetscScalar *x,PetscScalar *y, int *__ierr ){
*__ierr = FNEvaluateFunction(*fn,*x,y);
}
PETSC_EXTERN void PETSC_STDCALL  fnevaluatederivative_(FN *fn,PetscScalar *x,PetscScalar *y, int *__ierr ){
*__ierr = FNEvaluateDerivative(*fn,*x,y);
}
PETSC_EXTERN void PETSC_STDCALL  fnevaluatefunctionmat_(FN *fn,Mat A,Mat B, int *__ierr ){
*__ierr = FNEvaluateFunctionMat(*fn,
	(Mat)PetscToPointer((A) ),
	(Mat)PetscToPointer((B) ));
}
PETSC_EXTERN void PETSC_STDCALL  fnsetfromoptions_(FN *fn, int *__ierr ){
*__ierr = FNSetFromOptions(*fn);
}
PETSC_EXTERN void PETSC_STDCALL  fnduplicate_(FN *fn,MPI_Fint * comm,FN *newfn, int *__ierr ){
*__ierr = FNDuplicate(*fn,
	MPI_Comm_f2c( *(comm) ),
	(FN* )PetscToPointer((newfn) ));
}
PETSC_EXTERN void PETSC_STDCALL  fndestroy_(FN *fn, int *__ierr ){
*__ierr = FNDestroy(
	(FN* )PetscToPointer((fn) ));
}
#if defined(__cplusplus)
}
#endif
