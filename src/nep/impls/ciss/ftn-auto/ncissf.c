#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* nciss.c */
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

#include "slepcnep.h"
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define nepcisssetsizes_ NEPCISSSETSIZES
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define nepcisssetsizes_ nepcisssetsizes
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define nepcissgetsizes_ NEPCISSGETSIZES
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define nepcissgetsizes_ nepcissgetsizes
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define nepcisssetthreshold_ NEPCISSSETTHRESHOLD
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define nepcisssetthreshold_ nepcisssetthreshold
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define nepcissgetthreshold_ NEPCISSGETTHRESHOLD
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define nepcissgetthreshold_ nepcissgetthreshold
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define nepcisssetrefinement_ NEPCISSSETREFINEMENT
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define nepcisssetrefinement_ nepcisssetrefinement
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define nepcissgetrefinement_ NEPCISSGETREFINEMENT
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define nepcissgetrefinement_ nepcissgetrefinement
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  nepcisssetsizes_(NEP *nep,PetscInt *ip,PetscInt *bs,PetscInt *ms,PetscInt *npart,PetscInt *bsmax,PetscBool *isreal, int *__ierr ){
*__ierr = NEPCISSSetSizes(*nep,*ip,*bs,*ms,*npart,*bsmax,*isreal);
}
PETSC_EXTERN void PETSC_STDCALL  nepcissgetsizes_(NEP *nep,PetscInt *ip,PetscInt *bs,PetscInt *ms,PetscInt *npart,PetscInt *bsmax,PetscBool *isreal, int *__ierr ){
*__ierr = NEPCISSGetSizes(*nep,ip,bs,ms,npart,bsmax,isreal);
}
PETSC_EXTERN void PETSC_STDCALL  nepcisssetthreshold_(NEP *nep,PetscReal *delta,PetscReal *spur, int *__ierr ){
*__ierr = NEPCISSSetThreshold(*nep,*delta,*spur);
}
PETSC_EXTERN void PETSC_STDCALL  nepcissgetthreshold_(NEP *nep,PetscReal *delta,PetscReal *spur, int *__ierr ){
*__ierr = NEPCISSGetThreshold(*nep,delta,spur);
}
PETSC_EXTERN void PETSC_STDCALL  nepcisssetrefinement_(NEP *nep,PetscInt *inner,PetscInt *outer,PetscInt *blsize, int *__ierr ){
*__ierr = NEPCISSSetRefinement(*nep,*inner,*outer,*blsize);
}
PETSC_EXTERN void PETSC_STDCALL  nepcissgetrefinement_(NEP *nep,PetscInt *inner,PetscInt *outer,PetscInt *blsize, int *__ierr ){
*__ierr = NEPCISSGetRefinement(*nep,inner,outer,blsize);
}
#if defined(__cplusplus)
}
#endif
