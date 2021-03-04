INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_ALBERTASAT albertasat)

FIND_PATH(
    ALBERTASAT_INCLUDE_DIRS
    NAMES albertasat/api.h
    HINTS $ENV{ALBERTASAT_DIR}/include
        ${PC_ALBERTASAT_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    ALBERTASAT_LIBRARIES
    NAMES gnuradio-albertasat
    HINTS $ENV{ALBERTASAT_DIR}/lib
        ${PC_ALBERTASAT_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/albertasatTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(ALBERTASAT DEFAULT_MSG ALBERTASAT_LIBRARIES ALBERTASAT_INCLUDE_DIRS)
MARK_AS_ADVANCED(ALBERTASAT_LIBRARIES ALBERTASAT_INCLUDE_DIRS)
