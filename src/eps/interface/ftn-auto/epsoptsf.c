#include "petscsys.h"
#include "petscfix.h"
#include "petsc/private/fortranimpl.h"
/* epsopts.c */
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
#define epssetfromoptions_ EPSSETFROMOPTIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epssetfromoptions_ epssetfromoptions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epsgettolerances_ EPSGETTOLERANCES
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsgettolerances_ epsgettolerances
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epssettolerances_ EPSSETTOLERANCES
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epssettolerances_ epssettolerances
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epsgetdimensions_ EPSGETDIMENSIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsgetdimensions_ epsgetdimensions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epssetdimensions_ EPSSETDIMENSIONS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epssetdimensions_ epssetdimensions
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epssetwhicheigenpairs_ EPSSETWHICHEIGENPAIRS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epssetwhicheigenpairs_ epssetwhicheigenpairs
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epsgetwhicheigenpairs_ EPSGETWHICHEIGENPAIRS
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsgetwhicheigenpairs_ epsgetwhicheigenpairs
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epssetconvergencetest_ EPSSETCONVERGENCETEST
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epssetconvergencetest_ epssetconvergencetest
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epsgetconvergencetest_ EPSGETCONVERGENCETEST
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsgetconvergencetest_ epsgetconvergencetest
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epssetproblemtype_ EPSSETPROBLEMTYPE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epssetproblemtype_ epssetproblemtype
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epsgetproblemtype_ EPSGETPROBLEMTYPE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsgetproblemtype_ epsgetproblemtype
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epssetextraction_ EPSSETEXTRACTION
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epssetextraction_ epssetextraction
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epsgetextraction_ EPSGETEXTRACTION
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsgetextraction_ epsgetextraction
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epssetbalance_ EPSSETBALANCE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epssetbalance_ epssetbalance
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epsgetbalance_ EPSGETBALANCE
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsgetbalance_ epsgetbalance
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epssettrueresidual_ EPSSETTRUERESIDUAL
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epssettrueresidual_ epssettrueresidual
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epsgettrueresidual_ EPSGETTRUERESIDUAL
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsgettrueresidual_ epsgettrueresidual
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epssettrackall_ EPSSETTRACKALL
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epssettrackall_ epssettrackall
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epsgettrackall_ EPSGETTRACKALL
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsgettrackall_ epsgettrackall
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epssetpurify_ EPSSETPURIFY
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epssetpurify_ epssetpurify
#endif
#ifdef PETSC_HAVE_FORTRAN_CAPS
#define epsgetpurify_ EPSGETPURIFY
#elif !defined(PETSC_HAVE_FORTRAN_UNDERSCORE) && !defined(FORTRANDOUBLEUNDERSCORE)
#define epsgetpurify_ epsgetpurify
#endif


/* Definitions of Fortran Wrapper routines */
#if defined(__cplusplus)
extern "C" {
#endif
PETSC_EXTERN void PETSC_STDCALL  epssetfromoptions_(EPS *eps, int *__ierr ){
*__ierr = EPSSetFromOptions(*eps);
}
PETSC_EXTERN void PETSC_STDCALL  epsgettolerances_(EPS *eps,PetscReal *tol,PetscInt *maxits, int *__ierr ){
*__ierr = EPSGetTolerances(*eps,tol,maxits);
}
PETSC_EXTERN void PETSC_STDCALL  epssettolerances_(EPS *eps,PetscReal *tol,PetscInt *maxits, int *__ierr ){
*__ierr = EPSSetTolerances(*eps,*tol,*maxits);
}
PETSC_EXTERN void PETSC_STDCALL  epsgetdimensions_(EPS *eps,PetscInt *nev,PetscInt *ncv,PetscInt *mpd, int *__ierr ){
*__ierr = EPSGetDimensions(*eps,nev,ncv,mpd);
}
PETSC_EXTERN void PETSC_STDCALL  epssetdimensions_(EPS *eps,PetscInt *nev,PetscInt *ncv,PetscInt *mpd, int *__ierr ){
*__ierr = EPSSetDimensions(*eps,*nev,*ncv,*mpd);
}
PETSC_EXTERN void PETSC_STDCALL  epssetwhicheigenpairs_(EPS *eps,EPSWhich *which, int *__ierr ){
*__ierr = EPSSetWhichEigenpairs(*eps,*which);
}
PETSC_EXTERN void PETSC_STDCALL  epsgetwhicheigenpairs_(EPS *eps,EPSWhich *which, int *__ierr ){
*__ierr = EPSGetWhichEigenpairs(*eps,
	(EPSWhich* )PetscToPointer((which) ));
}
PETSC_EXTERN void PETSC_STDCALL  epssetconvergencetest_(EPS *eps,EPSConv *conv, int *__ierr ){
*__ierr = EPSSetConvergenceTest(*eps,*conv);
}
PETSC_EXTERN void PETSC_STDCALL  epsgetconvergencetest_(EPS *eps,EPSConv *conv, int *__ierr ){
*__ierr = EPSGetConvergenceTest(*eps,
	(EPSConv* )PetscToPointer((conv) ));
}
PETSC_EXTERN void PETSC_STDCALL  epssetproblemtype_(EPS *eps,EPSProblemType *type, int *__ierr ){
*__ierr = EPSSetProblemType(*eps,*type);
}
PETSC_EXTERN void PETSC_STDCALL  epsgetproblemtype_(EPS *eps,EPSProblemType *type, int *__ierr ){
*__ierr = EPSGetProblemType(*eps,
	(EPSProblemType* )PetscToPointer((type) ));
}
PETSC_EXTERN void PETSC_STDCALL  epssetextraction_(EPS *eps,EPSExtraction *extr, int *__ierr ){
*__ierr = EPSSetExtraction(*eps,*extr);
}
PETSC_EXTERN void PETSC_STDCALL  epsgetextraction_(EPS *eps,EPSExtraction *extr, int *__ierr ){
*__ierr = EPSGetExtraction(*eps,
	(EPSExtraction* )PetscToPointer((extr) ));
}
PETSC_EXTERN void PETSC_STDCALL  epssetbalance_(EPS *eps,EPSBalance *bal,PetscInt *its,PetscReal *cutoff, int *__ierr ){
*__ierr = EPSSetBalance(*eps,*bal,*its,*cutoff);
}
PETSC_EXTERN void PETSC_STDCALL  epsgetbalance_(EPS *eps,EPSBalance *bal,PetscInt *its,PetscReal *cutoff, int *__ierr ){
*__ierr = EPSGetBalance(*eps,
	(EPSBalance* )PetscToPointer((bal) ),its,cutoff);
}
PETSC_EXTERN void PETSC_STDCALL  epssettrueresidual_(EPS *eps,PetscBool *trueres, int *__ierr ){
*__ierr = EPSSetTrueResidual(*eps,*trueres);
}
PETSC_EXTERN void PETSC_STDCALL  epsgettrueresidual_(EPS *eps,PetscBool *trueres, int *__ierr ){
*__ierr = EPSGetTrueResidual(*eps,trueres);
}
PETSC_EXTERN void PETSC_STDCALL  epssettrackall_(EPS *eps,PetscBool *trackall, int *__ierr ){
*__ierr = EPSSetTrackAll(*eps,*trackall);
}
PETSC_EXTERN void PETSC_STDCALL  epsgettrackall_(EPS *eps,PetscBool *trackall, int *__ierr ){
*__ierr = EPSGetTrackAll(*eps,trackall);
}
PETSC_EXTERN void PETSC_STDCALL  epssetpurify_(EPS *eps,PetscBool *purify, int *__ierr ){
*__ierr = EPSSetPurify(*eps,*purify);
}
PETSC_EXTERN void PETSC_STDCALL  epsgetpurify_(EPS *eps,PetscBool *purify, int *__ierr ){
*__ierr = EPSGetPurify(*eps,purify);
}
#if defined(__cplusplus)
}
#endif
