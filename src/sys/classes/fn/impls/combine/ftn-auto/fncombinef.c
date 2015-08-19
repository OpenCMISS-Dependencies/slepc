#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* fncombine.c */
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
#define fncombinesetchildren_ FNCOMBINESETCHILDREN
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fncombinesetchildren_ fncombinesetchildren
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define fncombinegetchildren_ FNCOMBINEGETCHILDREN
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define fncombinegetchildren_ fncombinegetchildren
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  fncombinesetchildren_(FN *fn,FNCombineType *comb,FN *f1,FN *f2, int *__ierr ){
*__ierr = FNCombineSetChildren(*fn,*comb,*f1,*f2);
}
PETSC_EXTERN void PETSC_STDCALL  fncombinegetchildren_(FN *fn,FNCombineType *comb,FN *f1,FN *f2, int *__ierr ){
*__ierr = FNCombineGetChildren(*fn,
	(FNCombineType* )PetscToPointer((comb) ),
	(FN* )PetscToPointer((f1) ),
	(FN* )PetscToPointer((f2) ));
}
#if defined(__cplusplus)
}
#endif
