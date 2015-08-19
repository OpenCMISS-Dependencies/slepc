#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* pepbasic.c */
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
#define pepcreate_ PEPCREATE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepcreate_ pepcreate
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepreset_ PEPRESET
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepreset_ pepreset
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepdestroy_ PEPDESTROY
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepdestroy_ pepdestroy
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepsetbv_ PEPSETBV
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepsetbv_ pepsetbv
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepgetbv_ PEPGETBV
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepgetbv_ pepgetbv
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepsetrg_ PEPSETRG
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepsetrg_ pepsetrg
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepgetrg_ PEPGETRG
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepgetrg_ pepgetrg
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepsetds_ PEPSETDS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepsetds_ pepsetds
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepgetds_ PEPGETDS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepgetds_ pepgetds
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepsetst_ PEPSETST
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepsetst_ pepsetst
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepgetst_ PEPGETST
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepgetst_ pepgetst
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define peprefinegetksp_ PEPREFINEGETKSP
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define peprefinegetksp_ peprefinegetksp
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepsettarget_ PEPSETTARGET
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepsettarget_ pepsettarget
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepgettarget_ PEPGETTARGET
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepgettarget_ pepgettarget
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  pepcreate_(MPI_Fint * comm,PEP *outpep, int *__ierr ){
*__ierr = PEPCreate(
	MPI_Comm_f2c( *(comm) ),
	(PEP* )PetscToPointer((outpep) ));
}
PETSC_EXTERN void PETSC_STDCALL  pepreset_(PEP *pep, int *__ierr ){
*__ierr = PEPReset(*pep);
}
PETSC_EXTERN void PETSC_STDCALL  pepdestroy_(PEP *pep, int *__ierr ){
*__ierr = PEPDestroy(
	(PEP* )PetscToPointer((pep) ));
}
PETSC_EXTERN void PETSC_STDCALL  pepsetbv_(PEP *pep,BV *bv, int *__ierr ){
*__ierr = PEPSetBV(*pep,*bv);
}
PETSC_EXTERN void PETSC_STDCALL  pepgetbv_(PEP *pep,BV *bv, int *__ierr ){
*__ierr = PEPGetBV(*pep,
	(BV* )PetscToPointer((bv) ));
}
PETSC_EXTERN void PETSC_STDCALL  pepsetrg_(PEP *pep,RG *rg, int *__ierr ){
*__ierr = PEPSetRG(*pep,*rg);
}
PETSC_EXTERN void PETSC_STDCALL  pepgetrg_(PEP *pep,RG *rg, int *__ierr ){
*__ierr = PEPGetRG(*pep,
	(RG* )PetscToPointer((rg) ));
}
PETSC_EXTERN void PETSC_STDCALL  pepsetds_(PEP *pep,DS *ds, int *__ierr ){
*__ierr = PEPSetDS(*pep,*ds);
}
PETSC_EXTERN void PETSC_STDCALL  pepgetds_(PEP *pep,DS *ds, int *__ierr ){
*__ierr = PEPGetDS(*pep,
	(DS* )PetscToPointer((ds) ));
}
PETSC_EXTERN void PETSC_STDCALL  pepsetst_(PEP *pep,ST *st, int *__ierr ){
*__ierr = PEPSetST(*pep,*st);
}
PETSC_EXTERN void PETSC_STDCALL  pepgetst_(PEP *pep,ST *st, int *__ierr ){
*__ierr = PEPGetST(*pep,
	(ST* )PetscToPointer((st) ));
}
PETSC_EXTERN void PETSC_STDCALL  peprefinegetksp_(PEP *pep,KSP *ksp, int *__ierr ){
*__ierr = PEPRefineGetKSP(*pep,ksp);
}
PETSC_EXTERN void PETSC_STDCALL  pepsettarget_(PEP *pep,PetscScalar *target, int *__ierr ){
*__ierr = PEPSetTarget(*pep,*target);
}
PETSC_EXTERN void PETSC_STDCALL  pepgettarget_(PEP *pep,PetscScalar* target, int *__ierr ){
*__ierr = PEPGetTarget(*pep,target);
}
#if defined(__cplusplus)
}
#endif
