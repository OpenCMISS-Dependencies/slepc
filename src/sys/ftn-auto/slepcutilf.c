#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* slepcutil.c */
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

#include "slepcsys.h"
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define slepcmattile_ SLEPCMATTILE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define slepcmattile_ slepcmattile
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  slepcmattile_(PetscScalar *a,Mat A,PetscScalar *b,Mat B,PetscScalar *c,Mat C,PetscScalar *d,Mat D,Mat *G, int *__ierr ){
*__ierr = SlepcMatTile(*a,
	(Mat)PetscToPointer((A) ),*b,
	(Mat)PetscToPointer((B) ),*c,
	(Mat)PetscToPointer((C) ),*d,
	(Mat)PetscToPointer((D) ),G);
}
#if defined(__cplusplus)
}
#endif
