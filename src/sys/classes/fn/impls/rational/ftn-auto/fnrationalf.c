#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* fnrational.c */
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
#define fnrationalsetnumerator_ FNRATIONALSETNUMERATOR
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fnrationalsetnumerator_ fnrationalsetnumerator
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fnrationalgetnumerator_ FNRATIONALGETNUMERATOR
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fnrationalgetnumerator_ fnrationalgetnumerator
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fnrationalsetdenominator_ FNRATIONALSETDENOMINATOR
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fnrationalsetdenominator_ fnrationalsetdenominator
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fnrationalgetdenominator_ FNRATIONALGETDENOMINATOR
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fnrationalgetdenominator_ fnrationalgetdenominator
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  fnrationalsetnumerator_(FN *fn,PetscInt *np,PetscScalar *pcoeff, int *__ierr ){
*__ierr = FNRationalSetNumerator(*fn,*np,pcoeff);
}
PETSC_EXTERN void PETSC_STDCALL  fnrationalgetnumerator_(FN *fn,PetscInt *np,PetscScalar *pcoeff[], int *__ierr ){
*__ierr = FNRationalGetNumerator(*fn,np,pcoeff);
}
PETSC_EXTERN void PETSC_STDCALL  fnrationalsetdenominator_(FN *fn,PetscInt *nq,PetscScalar *qcoeff, int *__ierr ){
*__ierr = FNRationalSetDenominator(*fn,*nq,qcoeff);
}
PETSC_EXTERN void PETSC_STDCALL  fnrationalgetdenominator_(FN *fn,PetscInt *nq,PetscScalar *qcoeff[], int *__ierr ){
*__ierr = FNRationalGetDenominator(*fn,nq,qcoeff);
}
#if defined(__cplusplus)
}
#endif
