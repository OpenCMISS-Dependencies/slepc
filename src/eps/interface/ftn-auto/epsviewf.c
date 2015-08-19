#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* epsview.c */
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
#define epsreasonviewfromoptions_ EPSREASONVIEWFROMOPTIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsreasonviewfromoptions_ epsreasonviewfromoptions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epserrorviewfromoptions_ EPSERRORVIEWFROMOPTIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epserrorviewfromoptions_ epserrorviewfromoptions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epsvaluesviewfromoptions_ EPSVALUESVIEWFROMOPTIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsvaluesviewfromoptions_ epsvaluesviewfromoptions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epsvectorsviewfromoptions_ EPSVECTORSVIEWFROMOPTIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsvectorsviewfromoptions_ epsvectorsviewfromoptions
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  epsreasonviewfromoptions_(EPS *eps, int *__ierr ){
*__ierr = EPSReasonViewFromOptions(*eps);
}
PETSC_EXTERN void PETSC_STDCALL  epserrorviewfromoptions_(EPS *eps, int *__ierr ){
*__ierr = EPSErrorViewFromOptions(*eps);
}
PETSC_EXTERN void PETSC_STDCALL  epsvaluesviewfromoptions_(EPS *eps, int *__ierr ){
*__ierr = EPSValuesViewFromOptions(*eps);
}
PETSC_EXTERN void PETSC_STDCALL  epsvectorsviewfromoptions_(EPS *eps, int *__ierr ){
*__ierr = EPSVectorsViewFromOptions(*eps);
}
#if defined(__cplusplus)
}
#endif
