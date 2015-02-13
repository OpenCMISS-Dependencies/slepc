cmake_minimum_required (VERSION 3.0)
project (SLEPc VERSION 3.5 LANGUAGES C Fortran CXX)

option(BUILD_TESTS "${PROJECT_NAME} - Build tests" ON)
option(PACKAGE_CONFIG_DIR "Directory for package config files (relative to CMAKE_INSTALL_PREFIX)" "lib/cmake")
SET(CMAKE_NO_SYSTEM_FROM_IMPORTED YES)
find_package(PETSC ${PETSC_VERSION} REQUIRED)
if(NOT PETSC_SOURCE_DIR)
    set(PETSC_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../petsc)
endif()

include (${PETSC_SOURCE_DIR}/OpenCMISSPETScConfig.cmake)
include (./SLEPcConfig.cmake)

configure_file(${SLEPc_SOURCE_DIR}/include/slepcconf.h.in ${SLEPc_BINARY_DIR}/include/slepcconf.h)
#if (PETSC_HAVE_FORTRAN)
#  enable_language (Fortran)
#endif ()
#if (PETSC_CLANGUAGE_Cxx OR PETSC_HAVE_CXX)
#  enable_language (CXX)
#endif ()

if (APPLE)
  SET(CMAKE_C_ARCHIVE_FINISH "<CMAKE_RANLIB> -c <TARGET> ")
  SET(CMAKE_CXX_ARCHIVE_FINISH "<CMAKE_RANLIB> -c <TARGET> ")
  SET(CMAKE_Fortran_ARCHIVE_FINISH "<CMAKE_RANLIB> -c <TARGET> ")
endif ()

if (PETSC_HAVE_CUDA)
  find_package (CUDA REQUIRED)
  set (CUDA_PROPAGATE_HOST_FLAGS OFF)
  set (CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS} --compiler-options ${PETSC_CUDA_HOST_FLAGS})
endif ()

include_directories ("${SLEPc_SOURCE_DIR}/include" "${SLEPc_BINARY_DIR}/include")

#set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${SLEPc_BINARY_DIR}/lib" CACHE PATH "Output directory for SLEPc archives")
#set (CMAKE_LIBRARY_OUTPUT_DIRECTORY "${SLEPc_BINARY_DIR}/lib" CACHE PATH "Output directory for SLEPc libraries")
set (CMAKE_Fortran_MODULE_DIRECTORY "${SLEPc_BINARY_DIR}/include")
#mark_as_advanced (CMAKE_ARCHIVE_OUTPUT_DIRECTORY CMAKE_LIBRARY_OUTPUT_DIRECTORY CMAKE_Fortran_MODULE_DIRECTORY)
#set (CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
#set (CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

###################  The following describes the build  ####################

include_directories (${PETSC_PACKAGE_INCLUDES} ${SLEPC_PACKAGE_INCLUDES})
if (PETSC_HAVE_FORTRAN)
  list (APPEND SLEPCSYS_SRCS
    src/sys/ftn-auto/slepcscf.c
    src/sys/ftn-auto/slepcutilf.c
    src/sys/ftn-auto/slepcinitf.c
    src/sys/ftn-custom/zslepc_start.c
    src/sys/ftn-custom/zslepc_startf.c
    src/sys/classes/bv/interface/ftn-auto/bvopsf.c
    src/sys/classes/bv/interface/ftn-auto/bvorthogf.c
    src/sys/classes/bv/interface/ftn-auto/bvfuncf.c
    src/sys/classes/bv/interface/ftn-auto/bvbasicf.c
    src/sys/classes/bv/interface/ftn-auto/bvglobalf.c
    src/sys/classes/rg/ftn-auto/rgbasicf.c
    src/sys/classes/rg/ftn-auto/rgellipsef.c
    src/sys/classes/rg/ftn-auto/rgintervalf.c
    src/sys/classes/ds/interface/ftn-auto/dsopsf.c
    src/sys/classes/ds/interface/ftn-auto/dsbasicf.c
    src/sys/classes/ds/interface/ftn-custom/zdsf.c
    src/sys/classes/fn/ftn-auto/fnbasicf.c
    src/sys/classes/st/impls/shell/ftn-auto/shellf.c
    src/sys/classes/st/impls/shell/ftn-custom/zshell.c
    src/sys/classes/st/impls/precond/ftn-auto/precondf.c
    src/sys/classes/st/impls/cayley/ftn-auto/cayleyf.c
    src/sys/classes/st/interface/ftn-auto/stfuncf.c
    src/sys/classes/st/interface/ftn-auto/stsetf.c
    src/sys/classes/st/interface/ftn-auto/stslesf.c
    src/sys/classes/st/interface/ftn-auto/stsolvef.c
    src/sys/classes/st/interface/ftn-custom/zstf.c
    )
endif ()
if (NOT PETSC_USE_COMPLEX)
  list (APPEND SLEPCSYS_SRCS
    src/sys/classes/ds/impls/hep/bdc/dibtdc.c
    src/sys/classes/ds/impls/hep/bdc/dlaed3m.c
    src/sys/classes/ds/impls/hep/bdc/dmerg2.c
    src/sys/classes/ds/impls/hep/bdc/dsbtdc.c
    src/sys/classes/ds/impls/hep/bdc/dsrtdf.c
    )
endif ()
if (PETSC_USING_F90)
  list (APPEND SLEPCSYS_SRCS
    src/sys/f90-mod/slepcsysmod.F
    )
endif ()
list (APPEND SLEPCSYS_SRCS
  src/sys/slepcinit.c
  src/sys/slepcutil.c
  src/sys/slepcsc.c
  src/sys/dlregisslepc.c
  src/sys/classes/bv/impls/contiguous/contig.c
  src/sys/classes/bv/impls/svec/svec.c
  src/sys/classes/bv/impls/vecs/vecs.c
  src/sys/classes/bv/impls/mat/bvmat.c
  src/sys/classes/bv/interface/bvbasic.c
  src/sys/classes/bv/interface/bvfunc.c
  src/sys/classes/bv/interface/bvops.c
  src/sys/classes/bv/interface/bvglobal.c
  src/sys/classes/bv/interface/bvblas.c
  src/sys/classes/bv/interface/bvorthog.c
  src/sys/classes/bv/interface/bvregis.c
  src/sys/classes/rg/rgbasic.c
  src/sys/classes/rg/rginterval.c
  src/sys/classes/rg/rgpolygon.c
  src/sys/classes/rg/rgellipse.c
  src/sys/classes/ds/impls/ghep/dsghep.c
  src/sys/classes/ds/impls/hep/dshep.c
  src/sys/classes/ds/impls/ghiep/dsghiep_ivit.c
  src/sys/classes/ds/impls/ghiep/dsghiep.c
  src/sys/classes/ds/impls/ghiep/dsghiep_hz.c
  src/sys/classes/ds/impls/ghiep/dsghiep_dqds.c
  src/sys/classes/ds/impls/svd/dssvd.c
  src/sys/classes/ds/impls/nhep/dsnhep.c
  src/sys/classes/ds/impls/nep/dsnep.c
  src/sys/classes/ds/impls/gnhep/dsgnhep.c
  src/sys/classes/ds/interface/dsbasic.c
  src/sys/classes/ds/interface/dsops.c
  src/sys/classes/ds/interface/dspriv.c
  src/sys/classes/fn/fnbasic.c
  src/sys/classes/fn/fnrational.c
  src/sys/classes/fn/fnexp.c
  src/sys/classes/st/impls/sinvert/sinvert.c
  src/sys/classes/st/impls/shift/shift.c
  src/sys/classes/st/impls/shell/shell.c
  src/sys/classes/st/impls/precond/precond.c
  src/sys/classes/st/impls/cayley/cayley.c
  src/sys/classes/st/interface/stfunc.c
  src/sys/classes/st/interface/stset.c
  src/sys/classes/st/interface/stsolve.c
  src/sys/classes/st/interface/stsles.c
  src/sys/classes/st/interface/stregis.c
  src/sys/classes/st/interface/stshellmat.c
  src/sys/vec/veccomp.c
  src/sys/vec/pool.c
  )

if (NOT PETSC_USE_SINGLE_LIBRARY)
  if (PETSC_HAVE_CUDA)
    cuda_add_library (slepcsys ${SLEPCSYS_SRCS})
  else ()
    add_library (slepcsys ${SLEPCSYS_SRCS})
  endif ()
  target_link_libraries (slepcsys  ${PETSC_LIB} ${SLEPC_PACKAGE_LIBS} ${PETSC_PACKAGE_LIBS})
  if (PETSC_WIN32FE)
    set_target_properties (slepcsys PROPERTIES RULE_LAUNCH_COMPILE "${PETSC_WIN32FE}")
    set_target_properties (slepcsys PROPERTIES RULE_LAUNCH_LINK "${PETSC_WIN32FE}")
  endif ()
endif ()
if (SLEPC_HAVE_ARPACK)
  list (APPEND SLEPCEPS_SRCS
    src/eps/impls/external/arpack/arpack.c
    )
endif ()
if (PETSC_HAVE_FORTRAN)
  list (APPEND SLEPCEPS_SRCS
    src/eps/impls/power/ftn-auto/powerf.c
    src/eps/impls/cg/rqcg/ftn-auto/rqcgf.c
    src/eps/impls/krylov/krylovschur/ftn-auto/krylovschurf.c
    src/eps/impls/krylov/arnoldi/ftn-auto/arnoldif.c
    src/eps/impls/krylov/lanczos/ftn-auto/lanczosf.c
    src/eps/impls/davidson/jd/ftn-auto/jdf.c
    src/eps/impls/davidson/gd/ftn-auto/gdf.c
    src/eps/interface/ftn-auto/epsdefaultf.c
    src/eps/interface/ftn-auto/epssetupf.c
    src/eps/interface/ftn-auto/epsoptsf.c
    src/eps/interface/ftn-auto/epsmonf.c
    src/eps/interface/ftn-auto/epsbasicf.c
    src/eps/interface/ftn-auto/epssolvef.c
    src/eps/interface/ftn-custom/zepsf.c
    )
endif ()
if (PETSC_HAVE_FORTRAN AND PETSC_USE_COMPLEX)
  list (APPEND SLEPCEPS_SRCS
    src/eps/impls/ciss/ftn-auto/cissf.c
    )
endif ()
if (PETSC_HAVE_FORTRAN AND SLEPC_HAVE_FEAST AND PETSC_USE_COMPLEX)
  list (APPEND SLEPCEPS_SRCS
    src/eps/impls/external/feast/ftn-auto/feastf.c
    )
endif ()
list (APPEND SLEPCEPS_SRCS
  src/eps/impls/power/power.c
  src/eps/impls/lapack/lapack.c
  src/eps/impls/subspace/subspace.c
  src/eps/impls/cg/rqcg/rqcg.c
  src/eps/impls/krylov/krylov.c
  src/eps/impls/krylov/krylovschur/krylovschur.c
  src/eps/impls/krylov/krylovschur/ks-symm.c
  src/eps/impls/krylov/krylovschur/ks-slice.c
  src/eps/impls/krylov/krylovschur/ks-indef.c
  src/eps/impls/krylov/arnoldi/arnoldi.c
  src/eps/impls/krylov/lanczos/lanczos.c
  src/eps/impls/davidson/jd/jd.c
  src/eps/impls/davidson/gd/gd.c
  src/eps/impls/davidson/common/davidson.c
  src/eps/impls/davidson/common/dvd_calcpairs.c
  src/eps/impls/davidson/common/dvd_improvex.c
  src/eps/impls/davidson/common/dvd_initv.c
  src/eps/impls/davidson/common/dvd_schm.c
  src/eps/impls/davidson/common/dvd_testconv.c
  src/eps/impls/davidson/common/dvd_updatev.c
  src/eps/impls/davidson/common/dvd_utils.c
  src/eps/impls/davidson/common/dvd_gd2.c
  src/eps/impls/davidson/common/dvd_orth.c
  src/eps/interface/epsmon.c
  src/eps/interface/epsbasic.c
  src/eps/interface/epsdefault.c
  src/eps/interface/epsregis.c
  src/eps/interface/epsopts.c
  src/eps/interface/epssetup.c
  src/eps/interface/epssolve.c
  src/eps/interface/dlregiseps.c
  )
if (PETSC_HAVE_FORTRAN AND SLEPC_HAVE_BLZPACK AND NOT PETSC_USE_COMPLEX)
  list (APPEND SLEPCEPS_SRCS
    src/eps/impls/external/blzpack/ftn-auto/blzpackf.c
    )
endif ()
if (PETSC_HAVE_FORTRAN AND SLEPC_HAVE_PRIMME)
  list (APPEND SLEPCEPS_SRCS
    src/eps/impls/external/primme/ftn-auto/primmef.c
    src/eps/impls/external/primme/ftn-custom/zprimmef.c
    )
endif ()
if (SLEPC_HAVE_FEAST AND PETSC_USE_COMPLEX)
  list (APPEND SLEPCEPS_SRCS
    src/eps/impls/external/feast/feast.c
    )
endif ()
if (SLEPC_HAVE_BLZPACK AND NOT PETSC_USE_COMPLEX)
  list (APPEND SLEPCEPS_SRCS
    src/eps/impls/external/blzpack/blzpack.c
    )
endif ()
if (PETSC_USE_COMPLEX)
  list (APPEND SLEPCEPS_SRCS
    src/eps/impls/ciss/ciss.c
    )
endif ()
if (SLEPC_HAVE_BLOPEX AND PETSC_USE_REAL_DOUBLE)
  list (APPEND SLEPCEPS_SRCS
    src/eps/impls/external/blopex/blopex.c
    src/eps/impls/external/blopex/slepc-interface.c
    src/eps/impls/external/blopex/petsc-interface.c
    )
endif ()
if (PETSC_USING_F90)
  list (APPEND SLEPCEPS_SRCS
    src/eps/f90-mod/slepcepsmod.F
    )
endif ()
if (SLEPC_HAVE_PRIMME)
  list (APPEND SLEPCEPS_SRCS
    src/eps/impls/external/primme/primme.c
    )
endif ()
if (SLEPC_HAVE_TRLAN AND NOT PETSC_USE_COMPLEX)
  list (APPEND SLEPCEPS_SRCS
    src/eps/impls/external/trlan/trlan.c
    )
endif ()

if (NOT PETSC_USE_SINGLE_LIBRARY)
  if (PETSC_HAVE_CUDA)
    cuda_add_library (slepceps ${SLEPCEPS_SRCS})
  else ()
    add_library (slepceps ${SLEPCEPS_SRCS})
  endif ()
  target_link_libraries (slepceps slepcsys ${PETSC_LIB} ${SLEPC_PACKAGE_LIBS} ${PETSC_PACKAGE_LIBS})
  if (PETSC_WIN32FE)
    set_target_properties (slepceps PROPERTIES RULE_LAUNCH_COMPILE "${PETSC_WIN32FE}")
    set_target_properties (slepceps PROPERTIES RULE_LAUNCH_LINK "${PETSC_WIN32FE}")
  endif ()
endif ()
if (PETSC_HAVE_FORTRAN)
  list (APPEND SLEPCSVD_SRCS
    src/svd/impls/trlanczos/ftn-auto/trlanczosf.c
    src/svd/impls/cyclic/ftn-auto/cyclicf.c
    src/svd/impls/cross/ftn-auto/crossf.c
    src/svd/impls/lanczos/ftn-auto/gklanczosf.c
    src/svd/interface/ftn-auto/svdmonf.c
    src/svd/interface/ftn-auto/svdsetupf.c
    src/svd/interface/ftn-auto/svdbasicf.c
    src/svd/interface/ftn-auto/svdsolvef.c
    src/svd/interface/ftn-auto/svdoptsf.c
    src/svd/interface/ftn-custom/zsvdf.c
    )
endif ()
if (PETSC_USING_F90)
  list (APPEND SLEPCSVD_SRCS
    src/svd/f90-mod/slepcsvdmod.F
    )
endif ()
list (APPEND SLEPCSVD_SRCS
  src/svd/impls/lapack/svdlapack.c
  src/svd/impls/trlanczos/trlanczos.c
  src/svd/impls/cyclic/cyclic.c
  src/svd/impls/cross/cross.c
  src/svd/impls/lanczos/gklanczos.c
  src/svd/interface/svdregis.c
  src/svd/interface/svdbasic.c
  src/svd/interface/svdopts.c
  src/svd/interface/svdsetup.c
  src/svd/interface/svdsolve.c
  src/svd/interface/svdmon.c
  src/svd/interface/dlregissvd.c
  )

if (NOT PETSC_USE_SINGLE_LIBRARY)
  if (PETSC_HAVE_CUDA)
    cuda_add_library (slepcsvd ${SLEPCSVD_SRCS})
  else ()
    add_library (slepcsvd ${SLEPCSVD_SRCS})
  endif ()
  target_link_libraries (slepcsvd slepceps slepcsys ${PETSC_LIB} ${SLEPC_PACKAGE_LIBS} ${PETSC_PACKAGE_LIBS})
  if (PETSC_WIN32FE)
    set_target_properties (slepcsvd PROPERTIES RULE_LAUNCH_COMPILE "${PETSC_WIN32FE}")
    set_target_properties (slepcsvd PROPERTIES RULE_LAUNCH_LINK "${PETSC_WIN32FE}")
  endif ()
endif ()
if (PETSC_HAVE_FORTRAN)
  list (APPEND SLEPCPEP_SRCS
    src/pep/impls/qarnoldi/ftn-auto/qarnoldif.c
    src/pep/impls/linear/ftn-auto/linearf.c
    src/pep/impls/toar/ftn-auto/ptoarf.c
    src/pep/interface/ftn-auto/pepdefaultf.c
    src/pep/interface/ftn-auto/pepmonf.c
    src/pep/interface/ftn-auto/pepsetupf.c
    src/pep/interface/ftn-auto/pepsolvef.c
    src/pep/interface/ftn-auto/pepoptsf.c
    src/pep/interface/ftn-auto/pepbasicf.c
    src/pep/interface/ftn-custom/zpepf.c
    )
endif ()
if (PETSC_USING_F90)
  list (APPEND SLEPCPEP_SRCS
    src/pep/f90-mod/slepcpepmod.F
    )
endif ()
list (APPEND SLEPCPEP_SRCS
  src/pep/impls/qarnoldi/qarnoldi.c
  src/pep/impls/linear/linear.c
  src/pep/impls/linear/qeplin.c
  src/pep/impls/toar/ptoar.c
  src/pep/impls/toar/nrefinement.c
  src/pep/interface/pepmon.c
  src/pep/interface/pepbasic.c
  src/pep/interface/pepdefault.c
  src/pep/interface/pepregis.c
  src/pep/interface/pepopts.c
  src/pep/interface/pepsetup.c
  src/pep/interface/pepsolve.c
  src/pep/interface/peprefine.c
  src/pep/interface/dlregispep.c
  )

if (NOT PETSC_USE_SINGLE_LIBRARY)
  if (PETSC_HAVE_CUDA)
    cuda_add_library (slepcpep ${SLEPCPEP_SRCS})
  else ()
    add_library (slepcpep ${SLEPCPEP_SRCS})
  endif ()
  target_link_libraries (slepcpep slepceps slepcsys ${PETSC_LIB} ${SLEPC_PACKAGE_LIBS} ${PETSC_PACKAGE_LIBS})
  if (PETSC_WIN32FE)
    set_target_properties (slepcpep PROPERTIES RULE_LAUNCH_COMPILE "${PETSC_WIN32FE}")
    set_target_properties (slepcpep PROPERTIES RULE_LAUNCH_LINK "${PETSC_WIN32FE}")
  endif ()
endif ()
if (PETSC_HAVE_FORTRAN)
  list (APPEND SLEPCNEP_SRCS
    src/nep/impls/interpol/ftn-auto/interpolf.c
    src/nep/impls/slp/ftn-auto/slpf.c
    src/nep/interface/ftn-auto/nepoptsf.c
    src/nep/interface/ftn-auto/nepmonf.c
    src/nep/interface/ftn-auto/nepsolvef.c
    src/nep/interface/ftn-auto/nepbasicf.c
    src/nep/interface/ftn-auto/nepsetupf.c
    src/nep/interface/ftn-auto/nepdefaultf.c
    src/nep/interface/ftn-custom/znepf.c
    )
endif ()
if (PETSC_USING_F90)
  list (APPEND SLEPCNEP_SRCS
    src/nep/f90-mod/slepcnepmod.F
    )
endif ()
list (APPEND SLEPCNEP_SRCS
  src/nep/impls/interpol/interpol.c
  src/nep/impls/slp/slp.c
  src/nep/impls/narnoldi/narnoldi.c
  src/nep/impls/rii/rii.c
  src/nep/interface/nepmon.c
  src/nep/interface/nepbasic.c
  src/nep/interface/nepdefault.c
  src/nep/interface/nepregis.c
  src/nep/interface/nepopts.c
  src/nep/interface/nepsetup.c
  src/nep/interface/nepsolve.c
  src/nep/interface/neprefine.c
  src/nep/interface/dlregisnep.c
  )

if (NOT PETSC_USE_SINGLE_LIBRARY)
  if (PETSC_HAVE_CUDA)
    cuda_add_library (slepcnep ${SLEPCNEP_SRCS})
  else ()
    add_library (slepcnep ${SLEPCNEP_SRCS})
  endif ()
  target_link_libraries (slepcnep slepcpep slepceps slepcsys ${PETSC_LIB} ${SLEPC_PACKAGE_LIBS} ${PETSC_PACKAGE_LIBS})
  if (PETSC_WIN32FE)
    set_target_properties (slepcnep PROPERTIES RULE_LAUNCH_COMPILE "${PETSC_WIN32FE}")
    set_target_properties (slepcnep PROPERTIES RULE_LAUNCH_LINK "${PETSC_WIN32FE}")
  endif ()
endif ()
if (PETSC_HAVE_FORTRAN)
  list (APPEND SLEPCMFN_SRCS
    src/mfn/interface/ftn-auto/mfnbasicf.c
    src/mfn/interface/ftn-auto/mfnsolvef.c
    src/mfn/interface/ftn-auto/mfnoptsf.c
    src/mfn/interface/ftn-auto/mfnsetupf.c
    src/mfn/interface/ftn-auto/mfnmonf.c
    src/mfn/interface/ftn-custom/zmfnf.c
    )
endif ()
if (PETSC_USING_F90)
  list (APPEND SLEPCMFN_SRCS
    src/mfn/f90-mod/slepcmfnmod.F
    )
endif ()
list (APPEND SLEPCMFN_SRCS
  src/mfn/impls/krylov/mfnkrylov.c
  src/mfn/interface/mfnmon.c
  src/mfn/interface/mfnbasic.c
  src/mfn/interface/mfnregis.c
  src/mfn/interface/mfnopts.c
  src/mfn/interface/mfnsetup.c
  src/mfn/interface/mfnsolve.c
  src/mfn/interface/dlregismfn.c
  )

if (NOT PETSC_USE_SINGLE_LIBRARY)
  if (PETSC_HAVE_CUDA)
    cuda_add_library (slepcmfn ${SLEPCMFN_SRCS})
  else ()
    add_library (slepcmfn ${SLEPCMFN_SRCS})
  endif ()
  target_link_libraries (slepcmfn slepcsys ${PETSC_LIB} ${SLEPC_PACKAGE_LIBS} ${PETSC_PACKAGE_LIBS})
  if (PETSC_WIN32FE)
    set_target_properties (slepcmfn PROPERTIES RULE_LAUNCH_COMPILE "${PETSC_WIN32FE}")
    set_target_properties (slepcmfn PROPERTIES RULE_LAUNCH_LINK "${PETSC_WIN32FE}")
  endif ()
endif ()

if (PETSC_USE_SINGLE_LIBRARY)
  if (PETSC_HAVE_CUDA)
    cuda_add_library (slepc ${SLEPCSYS_SRCS} ${SLEPCEPS_SRCS} ${SLEPCSVD_SRCS} ${SLEPCPEP_SRCS} ${SLEPCNEP_SRCS} ${SLEPCMFN_SRCS})
  else ()
    add_library (slepc ${SLEPCSYS_SRCS} ${SLEPCEPS_SRCS}
        ${SLEPCSVD_SRCS} ${SLEPCPEP_SRCS} ${SLEPCNEP_SRCS}
        ${SLEPCMFN_SRCS})
  endif ()
  target_link_libraries (slepc petsc
      ${SLEPC_PACKAGE_LIBS}) #${PETSC_PACKAGE_LIBS}
  if (PETSC_WIN32FE)
    set_target_properties (slepc PROPERTIES RULE_LAUNCH_COMPILE "${PETSC_WIN32FE}")
    set_target_properties (slepc PROPERTIES RULE_LAUNCH_LINK "${PETSC_WIN32FE}")
  endif ()
  install(TARGETS slepc EXPORT slepc-config
      DESTINATION lib
      INCLUDES DESTINATION include/slepc)

endif ()

if (PETSC_CLANGUAGE_Cxx)
  foreach (file IN LISTS SLEPCSYS_SRCS
  SLEPCEPS_SRCS
  SLEPCSVD_SRCS
  SLEPCPEP_SRCS
  SLEPCNEP_SRCS
  SLEPCMFN_SRCS)
    if (file MATCHES "^.*\\.c$")
      set_source_files_properties(${file} PROPERTIES LANGUAGE CXX)
    endif ()
  endforeach ()
endif()

# (Some) test routines
if (BUILD_TESTS)
    #enable_testing()
    #add_subdirectory(src/snes/examples/tests)
endif()

# Install Fortran modules
install(DIRECTORY "${SLEPc_BINARY_DIR}/include/" DESTINATION include/slepc
    FILES_MATCHING PATTERN "*.mod")
# Install common headers    
install(DIRECTORY include/ DESTINATION include/slepc
    FILES_MATCHING PATTERN "*.h"
    PATTERN "slepc-private/*.h" EXCLUDE)
# Install custom headers    
install(DIRECTORY ${SLEPc_BINARY_DIR}/include/
    DESTINATION include/slepc
    FILES_MATCHING PATTERN "*.h")   
install(EXPORT slepc-config DESTINATION ${PACKAGE_CONFIG_DIR})
include(CMakePackageConfigHelpers)
WRITE_BASIC_PACKAGE_VERSION_FILE(${CMAKE_CURRENT_BINARY_DIR}/slepc-config-version.cmake COMPATIBILITY AnyNewerVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/slepc-config-version.cmake
    DESTINATION ${PACKAGE_CONFIG_DIR})