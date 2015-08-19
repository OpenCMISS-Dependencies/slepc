#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* pepsolve.c */
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
#define pepsolve_ PEPSOLVE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepsolve_ pepsolve
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepgetiterationnumber_ PEPGETITERATIONNUMBER
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepgetiterationnumber_ pepgetiterationnumber
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepgetconverged_ PEPGETCONVERGED
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepgetconverged_ pepgetconverged
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepgetconvergedreason_ PEPGETCONVERGEDREASON
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepgetconvergedreason_ pepgetconvergedreason
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepgeteigenpair_ PEPGETEIGENPAIR
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepgeteigenpair_ pepgeteigenpair
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepgeterrorestimate_ PEPGETERRORESTIMATE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepgeterrorestimate_ pepgeterrorestimate
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepcomputeerror_ PEPCOMPUTEERROR
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepcomputeerror_ pepcomputeerror
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  pepsolve_(PEP *pep, int *__ierr ){
*__ierr = PEPSolve(*pep);
}
PETSC_EXTERN void PETSC_STDCALL  pepgetiterationnumber_(PEP *pep,PetscInt *its, int *__ierr ){
*__ierr = PEPGetIterationNumber(*pep,its);
}
PETSC_EXTERN void PETSC_STDCALL  pepgetconverged_(PEP *pep,PetscInt *nconv, int *__ierr ){
*__ierr = PEPGetConverged(*pep,nconv);
}
PETSC_EXTERN void PETSC_STDCALL  pepgetconvergedreason_(PEP *pep,PEPConvergedReason *reason, int *__ierr ){
*__ierr = PEPGetConvergedReason(*pep,
	(PEPConvergedReason* )PetscToPointer((reason) ));
}
PETSC_EXTERN void PETSC_STDCALL  pepgeteigenpair_(PEP *pep,PetscInt *i,PetscScalar *eigr,PetscScalar *eigi,Vec Vr,Vec Vi, int *__ierr ){
*__ierr = PEPGetEigenpair(*pep,*i,eigr,eigi,
	(Vec)PetscToPointer((Vr) ),
	(Vec)PetscToPointer((Vi) ));
}
PETSC_EXTERN void PETSC_STDCALL  pepgeterrorestimate_(PEP *pep,PetscInt *i,PetscReal *errest, int *__ierr ){
*__ierr = PEPGetErrorEstimate(*pep,*i,errest);
}
PETSC_EXTERN void PETSC_STDCALL  pepcomputeerror_(PEP *pep,PetscInt *i,PEPErrorType *type,PetscReal *error, int *__ierr ){
*__ierr = PEPComputeError(*pep,*i,*type,error);
}
#if defined(__cplusplus)
}
#endif
