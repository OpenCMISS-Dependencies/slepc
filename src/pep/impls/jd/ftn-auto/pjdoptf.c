#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* pjdopt.c */
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
#define pepjdsettolerances_ PEPJDSETTOLERANCES
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepjdsettolerances_ pepjdsettolerances
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepjdgettolerances_ PEPJDGETTOLERANCES
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepjdgettolerances_ pepjdgettolerances
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepjdsetrestart_ PEPJDSETRESTART
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepjdsetrestart_ pepjdsetrestart
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepjdgetrestart_ PEPJDGETRESTART
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepjdgetrestart_ pepjdgetrestart
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  pepjdsettolerances_(PEP *pep,PetscReal *mtol,PetscReal *htol,PetscReal *stol, int *__ierr ){
*__ierr = PEPJDSetTolerances(*pep,*mtol,*htol,*stol);
}
PETSC_EXTERN void PETSC_STDCALL  pepjdgettolerances_(PEP *pep,PetscReal *mtol,PetscReal *htol,PetscReal *stol, int *__ierr ){
*__ierr = PEPJDGetTolerances(*pep,mtol,htol,stol);
}
PETSC_EXTERN void PETSC_STDCALL  pepjdsetrestart_(PEP *pep,PetscReal *keep, int *__ierr ){
*__ierr = PEPJDSetRestart(*pep,*keep);
}
PETSC_EXTERN void PETSC_STDCALL  pepjdgetrestart_(PEP *pep,PetscReal *keep, int *__ierr ){
*__ierr = PEPJDGetRestart(*pep,keep);
}
#if defined(__cplusplus)
}
#endif
