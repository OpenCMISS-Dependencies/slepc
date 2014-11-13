set (SLEPC_PACKAGE_LIBS "${ARPACK_LIB}" "${BLZPACK_LIB}" "${TRLAN_LIB}" "${PRIMME_LIB}" "${FEAST_LIB}" "${BLOPEX_LIB}" )
set (SLEPC_PACKAGE_INCLUDES "${PRIMME_INCLUDE}")
find_library (PETSC_LIB petsc HINTS ${PETSc_BINARY_DIR}/lib )

if (NOT PETSC_LIB) # Interpret missing libpetsc to mean that PETSc was built --with-single-library=0
  set (PETSC_LIB "")
  foreach (pkg sys vec mat dm ksp snes ts tao)
    string (TOUPPER ${pkg} PKG)
    find_library (PETSC${PKG}_LIB "petsc${pkg}" HINTS ${PETSc_BINARY_DIR}/lib)
    list (APPEND PETSC_LIB "${PETSC${PKG}_LIB}")
  endforeach ()
endif ()
