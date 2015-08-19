#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* dsbasic.c */
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

#include "slepcds.h"
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dscreate_ DSCREATE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dscreate_ dscreate
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dssetmethod_ DSSETMETHOD
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dssetmethod_ dssetmethod
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dsgetmethod_ DSGETMETHOD
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dsgetmethod_ dsgetmethod
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dssetcompact_ DSSETCOMPACT
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dssetcompact_ dssetcompact
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dsgetcompact_ DSGETCOMPACT
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dsgetcompact_ dsgetcompact
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dssetextrarow_ DSSETEXTRAROW
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dssetextrarow_ dssetextrarow
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dsgetextrarow_ DSGETEXTRAROW
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dsgetextrarow_ dsgetextrarow
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dssetrefined_ DSSETREFINED
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dssetrefined_ dssetrefined
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dsgetrefined_ DSGETREFINED
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dsgetrefined_ dsgetrefined
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dssetblocksize_ DSSETBLOCKSIZE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dssetblocksize_ dssetblocksize
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dsgetblocksize_ DSGETBLOCKSIZE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dsgetblocksize_ dsgetblocksize
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dssetfromoptions_ DSSETFROMOPTIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dssetfromoptions_ dssetfromoptions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dsallocate_ DSALLOCATE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dsallocate_ dsallocate
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dsreset_ DSRESET
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dsreset_ dsreset
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define dsdestroy_ DSDESTROY
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define dsdestroy_ dsdestroy
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  dscreate_(MPI_Fint * comm,DS *newds, int *__ierr ){
*__ierr = DSCreate(
	MPI_Comm_f2c( *(comm) ),
	(DS* )PetscToPointer((newds) ));
}
PETSC_EXTERN void PETSC_STDCALL  dssetmethod_(DS *ds,PetscInt *meth, int *__ierr ){
*__ierr = DSSetMethod(*ds,*meth);
}
PETSC_EXTERN void PETSC_STDCALL  dsgetmethod_(DS *ds,PetscInt *meth, int *__ierr ){
*__ierr = DSGetMethod(*ds,meth);
}
PETSC_EXTERN void PETSC_STDCALL  dssetcompact_(DS *ds,PetscBool *comp, int *__ierr ){
*__ierr = DSSetCompact(*ds,*comp);
}
PETSC_EXTERN void PETSC_STDCALL  dsgetcompact_(DS *ds,PetscBool *comp, int *__ierr ){
*__ierr = DSGetCompact(*ds,comp);
}
PETSC_EXTERN void PETSC_STDCALL  dssetextrarow_(DS *ds,PetscBool *ext, int *__ierr ){
*__ierr = DSSetExtraRow(*ds,*ext);
}
PETSC_EXTERN void PETSC_STDCALL  dsgetextrarow_(DS *ds,PetscBool *ext, int *__ierr ){
*__ierr = DSGetExtraRow(*ds,ext);
}
PETSC_EXTERN void PETSC_STDCALL  dssetrefined_(DS *ds,PetscBool *ref, int *__ierr ){
*__ierr = DSSetRefined(*ds,*ref);
}
PETSC_EXTERN void PETSC_STDCALL  dsgetrefined_(DS *ds,PetscBool *ref, int *__ierr ){
*__ierr = DSGetRefined(*ds,ref);
}
PETSC_EXTERN void PETSC_STDCALL  dssetblocksize_(DS *ds,PetscInt *bs, int *__ierr ){
*__ierr = DSSetBlockSize(*ds,*bs);
}
PETSC_EXTERN void PETSC_STDCALL  dsgetblocksize_(DS *ds,PetscInt *bs, int *__ierr ){
*__ierr = DSGetBlockSize(*ds,bs);
}
PETSC_EXTERN void PETSC_STDCALL  dssetfromoptions_(DS *ds, int *__ierr ){
*__ierr = DSSetFromOptions(*ds);
}
PETSC_EXTERN void PETSC_STDCALL  dsallocate_(DS *ds,PetscInt *ld, int *__ierr ){
*__ierr = DSAllocate(*ds,*ld);
}
PETSC_EXTERN void PETSC_STDCALL  dsreset_(DS *ds, int *__ierr ){
*__ierr = DSReset(*ds);
}
PETSC_EXTERN void PETSC_STDCALL  dsdestroy_(DS *ds, int *__ierr ){
*__ierr = DSDestroy(
	(DS* )PetscToPointer((ds) ));
}
#if defined(__cplusplus)
}
#endif
