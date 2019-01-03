cmake_minimum_required (VERSION 3.1)

# 3.0 or higher is strongly suggested; build settings (target_compile_options/etc...) sometimes 
# do not get propagated properly under certain conditions prior to this version
# Making this a hard requirement is potentially disruptive to existing customers who 
# aren't affected by the bad behavior though, so just warn for now
if(CMAKE_MAJOR_VERSION LESS 3)
    message(WARNING "Building with CMake 3.0 or higher is strongly suggested; current version is ${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}.${CMAKE_PATCH_VERSION}")
endif()

get_filename_component(MONKEY_ROOT "${CMAKE_CURRENT_SOURCE_DIR}" ABSOLUTE)

option(BUILD_SHARED_LIBS "If enabled, all libraries will be build as shared objects; otherwise all libraries will be built as static objects" ON)

##############################################################################
# Check to see if this is an out-of-source build or not
##############################################################################
IF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
	MESSAGE("Something is wrong... It looks like you are attempting to build")
	MESSAGE("in the root directory.  Please don't.")
    MESSAGE("Source directory = ${CMAKE_SOURCE_DIR}")
    MESSAGE("Binary directory = ${CMAKE_BINARY_DIR}")
    MESSAGE(FATAL_ERROR "Prevented in-tree build. This is bad practice.")   
ENDIF(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})

# build the sdk targets
project("monkey-hammer" VERSION "${PROJECT_VERSION}" LANGUAGES CXX)

# CMAKE_MODULE_PATH is a CMAKE variable. It contains a list of paths 
# which could be used to search CMAKE modules by "include()" or "find_package()", but the default value is empty.
# Add cmake dir to search list
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")


# Add doxygen make target for source documentation
include(doxygen)
# Figure out what platform we are building for
include(resolve_platform)

include(CMakePackageConfigHelpers)

# set package version (detection is broken for the moment)
set(PACKAGE_VERSION "0.0.0")

# Try to figure out what project version we are building
include(initialize_project_version)

include(external_dependencies)

include(compiler_settings)

include( CTest )
include(CPack)

add_subdirectory(monkeylib)
add_subdirectory(monkeylib-test)
add_subdirectory(monkey-comment)
add_subdirectory(monkey-text2array)
add_subdirectory(codemonkey)

# setup user specified installation directory if any, regardless previous platform default settings
if (CMAKE_INSTALL_BINDIR)
    set(BINARY_DIRECTORY "${CMAKE_INSTALL_BINDIR}")
endif()

if (CMAKE_INSTALL_LIBDIR)
    set(LIBRARY_DIRECTORY "${CMAKE_INSTALL_LIBDIR}")
endif()

if (CMAKE_INSTALL_INCLUDEDIR)
    set(INCLUDE_DIRECTORY "${CMAKE_INSTALL_INCLUDEDIR}")
endif()

if(BUILD_SHARED_LIBS)
    set(ARCHIVE_DIRECTORY "${BINARY_DIRECTORY}")
else()
    set(ARCHIVE_DIRECTORY "${LIBRARY_DIRECTORY}")
endif()

if (ENABLE_ADDRESS_SANITIZER)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -fno-omit-frame-pointer")
endif()


# for generating make uninstall target
if (NOT TARGET uninstall)
    ADD_CUSTOM_TARGET(uninstall "${CMAKE_COMMAND}" -P "${MONKEY_ROOT}/cmake/make_uninstall.cmake")
else()
    ADD_CUSTOM_TARGET(uninstall-monkeylib "${CMAKE_COMMAND}" -P "${MONKEY_ROOT}/cmake/make_uninstall.cmake")
endif()


