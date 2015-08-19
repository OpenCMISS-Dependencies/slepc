#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* pepview.c */
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
#define pepreasonviewfromoptions_ PEPREASONVIEWFROMOPTIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepreasonviewfromoptions_ pepreasonviewfromoptions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define peperrorviewfromoptions_ PEPERRORVIEWFROMOPTIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define peperrorviewfromoptions_ peperrorviewfromoptions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepvaluesviewfromoptions_ PEPVALUESVIEWFROMOPTIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepvaluesviewfromoptions_ pepvaluesviewfromoptions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define pepvectorsviewfromoptions_ PEPVECTORSVIEWFROMOPTIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define pepvectorsviewfromoptions_ pepvectorsviewfromoptions
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  pepreasonviewfromoptions_(PEP *pep, int *__ierr ){
*__ierr = PEPReasonViewFromOptions(*pep);
}
PETSC_EXTERN void PETSC_STDCALL  peperrorviewfromoptions_(PEP *pep, int *__ierr ){
*__ierr = PEPErrorViewFromOptions(*pep);
}
PETSC_EXTERN void PETSC_STDCALL  pepvaluesviewfromoptions_(PEP *pep, int *__ierr ){
*__ierr = PEPValuesViewFromOptions(*pep);
}
PETSC_EXTERN void PETSC_STDCALL  pepvectorsviewfromoptions_(PEP *pep, int *__ierr ){
*__ierr = PEPVectorsViewFromOptions(*pep);
}
#if defined(__cplusplus)
}
#endif
