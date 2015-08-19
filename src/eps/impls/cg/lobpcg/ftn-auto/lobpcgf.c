#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* lobpcg.c */
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
#include "slepcds.h"
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epslobpcgsetblocksize_ EPSLOBPCGSETBLOCKSIZE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epslobpcgsetblocksize_ epslobpcgsetblocksize
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epslobpcggetblocksize_ EPSLOBPCGGETBLOCKSIZE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epslobpcggetblocksize_ epslobpcggetblocksize
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epslobpcgsetlocking_ EPSLOBPCGSETLOCKING
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epslobpcgsetlocking_ epslobpcgsetlocking
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epslobpcggetlocking_ EPSLOBPCGGETLOCKING
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epslobpcggetlocking_ epslobpcggetlocking
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  epslobpcgsetblocksize_(EPS *eps,PetscInt *bs, int *__ierr ){
*__ierr = EPSLOBPCGSetBlockSize(*eps,*bs);
}
PETSC_EXTERN void PETSC_STDCALL  epslobpcggetblocksize_(EPS *eps,PetscInt *bs, int *__ierr ){
*__ierr = EPSLOBPCGGetBlockSize(*eps,bs);
}
PETSC_EXTERN void PETSC_STDCALL  epslobpcgsetlocking_(EPS *eps,PetscBool *lock, int *__ierr ){
*__ierr = EPSLOBPCGSetLocking(*eps,*lock);
}
PETSC_EXTERN void PETSC_STDCALL  epslobpcggetlocking_(EPS *eps,PetscBool *lock, int *__ierr ){
*__ierr = EPSLOBPCGGetLocking(*eps,lock);
}
#if defined(__cplusplus)
}
#endif
