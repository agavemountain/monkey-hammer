add_project(monkeylib "Core library for the Monkey Hammer project")

set(CORE_INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/monkeylib/core)

if(VERSION_STRING)
    set(MONKEY_VERSION_STRING ${VERSION_STRING})
    message(STATUS "Updating version info to ${VERSION_STRING}")
    if(EXISTS ${SDK_CORE_INC_DIR}/VersionConfig.h})
        FILE(REMOVE ${SDK_CORE_INC_DIR/VersionConfig.h})
    endif()
    string(REPLACE "." ";" VERSION_LIST ${VERSION_STRING})
    list(GET VERSION_LIST 0 MONKEY_VERSION_MAJOR)
    list(GET VERSION_LIST 1 MONKEY_VERSION_MINOR)
    list(GET VERSION_LIST 2 MONKEY_VERSION_PATCH)

    configure_file(
        "${CORE_INC_DIR}/VersionConfig.h.in"
        "${CORE_INC_DIR}/VersionConfig.h"
        NEWLINE_STYLE LF)
else()
    message("Not able to compute versioning string, not updating.")
endif()

file(GLOB MONKEY_HEADERS "include/monkeylib/core/*.h")
file(GLOB MONKEY_PATTERN_HEADERS "include/monkeylib/core/patterns/*.h")
file(GLOB MONKEY_CONFIG_HEADERS "include/monkeylib/core/configuration/*.h")
file(GLOB MONKEY_FORMATTERS_HEADERS "include/monkeylib/core/formatters/*.h")
file(GLOB MONKEY_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")
file(GLOB MONKEY_CONFIG_SRC "${CMAKE_CURRENT_SOURCE_DIR}/source/configuration/*.cpp")
file(GLOB MONKEY_FORMATTERS_SRC "${CMAKE_CURRENT_SOURCE_DIR}/source/formatters/*.cpp")

file(GLOB MONKEY_COMMON_SRC
	${MONKEY_SOURCE}
    ${MONKEY_CONFIG_SRC}
    ${MONKEY_FORMATTERS_SRC}
)

file(GLOB MONKEY_COMMON_HEADERS
	${MONKEY_HEADERS}
	${MONKEY_PATTERN_HEADERS}
    ${MONKEY_CONFIG_HEADERS}
    ${MONKEY_FORMATTERS_HEADERS}
)

message("PROJECT_NAME = ${PROJECT_NAME}")

add_library(${PROJECT_NAME} ${LIBTYPE} ${MONKEY_COMMON_SRC})
add_library(MONKEY::${PROJECT_NAME} ALIAS ${PROJECT_NAME})
#target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})

# FIXME: until automatic versioning is fixed, we hard code:
#set(MONKEY_VERSION_MAJOR 0)
#set(MONKEY_VERSION_MINOR 0)
#set(MONKEY_VERSION_PATCH 0)

message("MONKEY_VERSION_MAJOR=${MONKEY_VERSION_MAJOR}")
message("MONKEY_VERSION_MINOR=${MONKEY_VERSION_MINOR}")
message("MONKEY_VERSION_PATCH=${MONKEY_VERSION_PATCH}")

target_compile_definitions(${PROJECT_NAME} PUBLIC "MONKEY_VERSION_MAJOR=${MONKEY_VERSION_MAJOR}")
target_compile_definitions(${PROJECT_NAME} PUBLIC "MONKEY_VERSION_MINOR=${MONKEY_VERSION_MINOR}")
target_compile_definitions(${PROJECT_NAME} PUBLIC "MONKEY_VERSION_PATCH=${MONKEY_VERSION_PATCH}")

set(Core_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include/")

if(USE_WINDOWS_DLL_SEMANTICS)
    target_compile_definitions(${PROJECT_NAME} PUBLIC "USE_WINDOWS_DLL_SEMANTICS")

    if(BUILD_SHARED_LIBS)
        target_compile_definitions(${PROJECT_NAME} PUBLIC "USE_IMPORT_EXPORT=1")
        target_compile_definitions(${PROJECT_NAME} PRIVATE "MONKEY_CORE_EXPORTS=1")
    endif()
endif()

set_compiler_flags(${PROJECT_NAME})
set_compiler_warnings(${PROJECT_NAME})

target_include_directories(${PROJECT_NAME} PRIVATE "${Core_INCLUDES}")

install (FILES ${MONKEY_COMMON_HEADERS} DESTINATION ${INCLUDE_DIRECTORY}/monkeylib/core)

