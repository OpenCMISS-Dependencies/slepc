#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* krylovschur.c */
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

#include "slepceps.h"
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epskrylovschursetrestart_ EPSKRYLOVSCHURSETRESTART
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epskrylovschursetrestart_ epskrylovschursetrestart
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epskrylovschurgetrestart_ EPSKRYLOVSCHURGETRESTART
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epskrylovschurgetrestart_ epskrylovschurgetrestart
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epskrylovschursetlocking_ EPSKRYLOVSCHURSETLOCKING
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epskrylovschursetlocking_ epskrylovschursetlocking
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epskrylovschurgetlocking_ EPSKRYLOVSCHURGETLOCKING
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epskrylovschurgetlocking_ epskrylovschurgetlocking
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epskrylovschursetpartitions_ EPSKRYLOVSCHURSETPARTITIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epskrylovschursetpartitions_ epskrylovschursetpartitions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epskrylovschurgetpartitions_ EPSKRYLOVSCHURGETPARTITIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epskrylovschurgetpartitions_ epskrylovschurgetpartitions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epskrylovschursetdetectzeros_ EPSKRYLOVSCHURSETDETECTZEROS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epskrylovschursetdetectzeros_ epskrylovschursetdetectzeros
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epskrylovschurgetdetectzeros_ EPSKRYLOVSCHURGETDETECTZEROS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epskrylovschurgetdetectzeros_ epskrylovschurgetdetectzeros
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epskrylovschursetdimensions_ EPSKRYLOVSCHURSETDIMENSIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epskrylovschursetdimensions_ epskrylovschursetdimensions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epskrylovschurgetdimensions_ EPSKRYLOVSCHURGETDIMENSIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epskrylovschurgetdimensions_ epskrylovschurgetdimensions
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  epskrylovschursetrestart_(EPS *eps,PetscReal *keep, int *__ierr ){
*__ierr = EPSKrylovSchurSetRestart(*eps,*keep);
}
PETSC_EXTERN void PETSC_STDCALL  epskrylovschurgetrestart_(EPS *eps,PetscReal *keep, int *__ierr ){
*__ierr = EPSKrylovSchurGetRestart(*eps,keep);
}
PETSC_EXTERN void PETSC_STDCALL  epskrylovschursetlocking_(EPS *eps,PetscBool *lock, int *__ierr ){
*__ierr = EPSKrylovSchurSetLocking(*eps,*lock);
}
PETSC_EXTERN void PETSC_STDCALL  epskrylovschurgetlocking_(EPS *eps,PetscBool *lock, int *__ierr ){
*__ierr = EPSKrylovSchurGetLocking(*eps,lock);
}
PETSC_EXTERN void PETSC_STDCALL  epskrylovschursetpartitions_(EPS *eps,PetscInt *npart, int *__ierr ){
*__ierr = EPSKrylovSchurSetPartitions(*eps,*npart);
}
PETSC_EXTERN void PETSC_STDCALL  epskrylovschurgetpartitions_(EPS *eps,PetscInt *npart, int *__ierr ){
*__ierr = EPSKrylovSchurGetPartitions(*eps,npart);
}
PETSC_EXTERN void PETSC_STDCALL  epskrylovschursetdetectzeros_(EPS *eps,PetscBool *detect, int *__ierr ){
*__ierr = EPSKrylovSchurSetDetectZeros(*eps,*detect);
}
PETSC_EXTERN void PETSC_STDCALL  epskrylovschurgetdetectzeros_(EPS *eps,PetscBool *detect, int *__ierr ){
*__ierr = EPSKrylovSchurGetDetectZeros(*eps,detect);
}
PETSC_EXTERN void PETSC_STDCALL  epskrylovschursetdimensions_(EPS *eps,PetscInt *nev,PetscInt *ncv,PetscInt *mpd, int *__ierr ){
*__ierr = EPSKrylovSchurSetDimensions(*eps,*nev,*ncv,*mpd);
}
PETSC_EXTERN void PETSC_STDCALL  epskrylovschurgetdimensions_(EPS *eps,PetscInt *nev,PetscInt *ncv,PetscInt *mpd, int *__ierr ){
*__ierr = EPSKrylovSchurGetDimensions(*eps,nev,ncv,mpd);
}
#if defined(__cplusplus)
}
#endif
