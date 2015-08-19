#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* dsnep.c */
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

#include "slepcds.h"
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dsnepsetfn_ DSNEPSETFN
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dsnepsetfn_ dsnepsetfn
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dsnepgetfn_ DSNEPGETFN
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dsnepgetfn_ dsnepgetfn
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dsnepgetnumfn_ DSNEPGETNUMFN
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dsnepgetnumfn_ dsnepgetnumfn
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  dsnepsetfn_(DS *ds,PetscInt *n,FN fn[], int *__ierr ){
*__ierr = DSNEPSetFN(*ds,*n,
	(FN* )PetscToPointer((fn) ));
}
PETSC_EXTERN void PETSC_STDCALL  dsnepgetfn_(DS *ds,PetscInt *k,FN *fn, int *__ierr ){
*__ierr = DSNEPGetFN(*ds,*k,
	(FN* )PetscToPointer((fn) ));
}
PETSC_EXTERN void PETSC_STDCALL  dsnepgetnumfn_(DS *ds,PetscInt *n, int *__ierr ){
*__ierr = DSNEPGetNumFN(*ds,n);
}
#if defined(__cplusplus)
}
#endif
