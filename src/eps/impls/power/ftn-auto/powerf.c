#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* power.c */
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
#define epspowersetshifttype_ EPSPOWERSETSHIFTTYPE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epspowersetshifttype_ epspowersetshifttype
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epspowergetshifttype_ EPSPOWERGETSHIFTTYPE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epspowergetshifttype_ epspowergetshifttype
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  epspowersetshifttype_(EPS *eps,EPSPowerShiftType *shift, int *__ierr ){
*__ierr = EPSPowerSetShiftType(*eps,*shift);
}
PETSC_EXTERN void PETSC_STDCALL  epspowergetshifttype_(EPS *eps,EPSPowerShiftType *shift, int *__ierr ){
*__ierr = EPSPowerGetShiftType(*eps,
	(EPSPowerShiftType* )PetscToPointer((shift) ));
}
#if defined(__cplusplus)
}
#endif
