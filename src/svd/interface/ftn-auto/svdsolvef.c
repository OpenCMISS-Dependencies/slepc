#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* svdsolve.c */
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

#include "slepcsvd.h"
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define svdsolve_ SVDSOLVE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svdsolve_ svdsolve
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define svdgetiterationnumber_ SVDGETITERATIONNUMBER
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svdgetiterationnumber_ svdgetiterationnumber
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define svdgetconvergedreason_ SVDGETCONVERGEDREASON
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svdgetconvergedreason_ svdgetconvergedreason
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define svdgetconverged_ SVDGETCONVERGED
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svdgetconverged_ svdgetconverged
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define svdgetsingulartriplet_ SVDGETSINGULARTRIPLET
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svdgetsingulartriplet_ svdgetsingulartriplet
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define svdcomputeerror_ SVDCOMPUTEERROR
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svdcomputeerror_ svdcomputeerror
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  svdsolve_(SVD *svd, int *__ierr ){
*__ierr = SVDSolve(*svd);
}
PETSC_EXTERN void PETSC_STDCALL  svdgetiterationnumber_(SVD *svd,PetscInt *its, int *__ierr ){
*__ierr = SVDGetIterationNumber(*svd,its);
}
PETSC_EXTERN void PETSC_STDCALL  svdgetconvergedreason_(SVD *svd,SVDConvergedReason *reason, int *__ierr ){
*__ierr = SVDGetConvergedReason(*svd,
	(SVDConvergedReason* )PetscToPointer((reason) ));
}
PETSC_EXTERN void PETSC_STDCALL  svdgetconverged_(SVD *svd,PetscInt *nconv, int *__ierr ){
*__ierr = SVDGetConverged(*svd,nconv);
}
PETSC_EXTERN void PETSC_STDCALL  svdgetsingulartriplet_(SVD *svd,PetscInt *i,PetscReal *sigma,Vec u,Vec v, int *__ierr ){
*__ierr = SVDGetSingularTriplet(*svd,*i,sigma,
	(Vec)PetscToPointer((u) ),
	(Vec)PetscToPointer((v) ));
}
PETSC_EXTERN void PETSC_STDCALL  svdcomputeerror_(SVD *svd,PetscInt *i,SVDErrorType *type,PetscReal *error, int *__ierr ){
*__ierr = SVDComputeError(*svd,*i,*type,error);
}
#if defined(__cplusplus)
}
#endif
