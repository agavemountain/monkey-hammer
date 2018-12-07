#
# Figure out the software version.  By automating this, it frees 
# us from having to maintain version files.  The version string will
# be passed defines to it is visible to the compiled applications and
# libraries.
#

# Version will be last release tag.
if(GIT_FOUND)
    execute_process(COMMAND ${GIT_EXECUTABLE} --git-dir=${CMAKE_CURRENT_SOURCE_DIR}/.git describe --abbrev=0 --tags
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    OUTPUT_VARIABLE VERSION_STRING
    OUTPUT_STRIP_TRAILING_WHITESPACE)
endif()

if(NOT VERSION_STRING)
    if(PACKAGE_VERSION) 
        set(VERSION_STRING "${PACKAGE_VERSION}")
    else()
        # extract it from the existing generated header file
        file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/monkeylib/include/monkeylib/core/VersionConfig.h" __SDK_VERSION_LINE LIMIT_COUNT 1 REGEX "MONKEY_VERSION_STRING.*[0-9]+\\.[0-9]+\\.[0-9]+" )
        string( REGEX MATCH "([0-9]+\\.[0-9]+\\.[0-9]+)" VERSION_STRING "${__SDK_VERSION_LINE}" )
    endif(PACKAGE_VERSION)
endif()

message( "PACKAGE VERSION = ${PACKAGE_VERSION}")
macro(add_project name description)
    set(PROJECT_NAME "${name}")
    set(PROJECT_STRING    "${name}_${PROJECT_VERSION}")
    set(PROJECT_TARNAME   "${name}-${PROJECT_VERSION}")
    set(PROJECT_BUGREPORT "https://github.com/agavemountain/monkey-hammer/issues/")
    set(PROJECT_DESCRIPTION "${description}")
    set(PROJECT_LIBS "")
    set(PROJECT_LIBS_STRING "")
    foreach(library_var ${ARGN})
        list(APPEND PROJECT_LIBS "${library_var}")
        set(PROJECT_LIBS_STRING "${PROJECT_LIBS_STRING} ${library_var}")
    endforeach()

    project(${name} VERSION "${PROJECT_VERSION}" LANGUAGES CXX C)

endmacro()