#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* svdbasic.c */
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
#define svdcreate_ SVDCREATE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svdcreate_ svdcreate
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define svdreset_ SVDRESET
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svdreset_ svdreset
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define svddestroy_ SVDDESTROY
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svddestroy_ svddestroy
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define svdsetbv_ SVDSETBV
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svdsetbv_ svdsetbv
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define svdgetbv_ SVDGETBV
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svdgetbv_ svdgetbv
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define svdsetds_ SVDSETDS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svdsetds_ svdsetds
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define svdgetds_ SVDGETDS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define svdgetds_ svdgetds
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  svdcreate_(MPI_Fint * comm,SVD *outsvd, int *__ierr ){
*__ierr = SVDCreate(
	MPI_Comm_f2c( *(comm) ),
	(SVD* )PetscToPointer((outsvd) ));
}
PETSC_EXTERN void PETSC_STDCALL  svdreset_(SVD *svd, int *__ierr ){
*__ierr = SVDReset(*svd);
}
PETSC_EXTERN void PETSC_STDCALL  svddestroy_(SVD *svd, int *__ierr ){
*__ierr = SVDDestroy(
	(SVD* )PetscToPointer((svd) ));
}
PETSC_EXTERN void PETSC_STDCALL  svdsetbv_(SVD *svd,BV *V,BV *U, int *__ierr ){
*__ierr = SVDSetBV(*svd,*V,*U);
}
PETSC_EXTERN void PETSC_STDCALL  svdgetbv_(SVD *svd,BV *V,BV *U, int *__ierr ){
*__ierr = SVDGetBV(*svd,
	(BV* )PetscToPointer((V) ),
	(BV* )PetscToPointer((U) ));
}
PETSC_EXTERN void PETSC_STDCALL  svdsetds_(SVD *svd,DS *ds, int *__ierr ){
*__ierr = SVDSetDS(*svd,*ds);
}
PETSC_EXTERN void PETSC_STDCALL  svdgetds_(SVD *svd,DS *ds, int *__ierr ){
*__ierr = SVDGetDS(*svd,
	(DS* )PetscToPointer((ds) ));
}
#if defined(__cplusplus)
}
#endif
