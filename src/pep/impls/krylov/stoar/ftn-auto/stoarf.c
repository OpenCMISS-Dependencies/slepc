#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* stoar.c */
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

#include "slepcpep.h"
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepstoarsetlocking_ PEPSTOARSETLOCKING
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepstoarsetlocking_ pepstoarsetlocking
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepstoargetlocking_ PEPSTOARGETLOCKING
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepstoargetlocking_ pepstoargetlocking
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  pepstoarsetlocking_(PEP *pep,PetscBool *lock, int *__ierr ){
*__ierr = PEPSTOARSetLocking(*pep,*lock);
}
PETSC_EXTERN void PETSC_STDCALL  pepstoargetlocking_(PEP *pep,PetscBool *lock, int *__ierr ){
*__ierr = PEPSTOARGetLocking(*pep,lock);
}
#if defined(__cplusplus)
}
#endif
