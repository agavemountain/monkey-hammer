# Add external project dependencies here

##############################################################################
# Find CppUnit
##############################################################################
INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(CPPUNIT "cppunit")
IF(NOT CPPUNIT_FOUND)
    FIND_PATH(CPPUNIT_INCLUDE_DIRS cppunit/TestCase.h
      /usr/local/include
      /usr/include
    )

    FIND_LIBRARY(CPPUNIT_LIBRARIES cppunit
               ${CPPUNIT_INCLUDE_DIRS}/../lib
               /usr/local/lib
               /usr/lib)

    IF(CPPUNIT_INCLUDE_DIRS)
      IF(CPPUNIT_LIBRARIES)
        SET(CPPUNIT_FOUND "YES")
        SET(CPPUNIT_LIBRARIES ${CPPUNIT_LIBRARIES} ${CMAKE_DL_LIBS})
      ENDIF(CPPUNIT_LIBRARIES)
    ENDIF(CPPUNIT_INCLUDE_DIRS)

    INCLUDE(FindPackageHandleStandardArgs)
    FIND_PACKAGE_HANDLE_STANDARD_ARGS(CPPUNIT DEFAULT_MSG CPPUNIT_LIBRARIES CPPUNIT_INCLUDE_DIRS)
ENDIF(NOT CPPUNIT_FOUND)

IF(CPPUNIT_FOUND)
    MESSAGE("FOUND cppunit.")
ELSE()
    MESSAGE("CPPUNIT NOT FOUND.")
ENDIF(CPPUNIT_FOUND)


##############################################################################
# find boost libraries and headers.
##############################################################################
#SET (Boost_USE_STATIC_LIBS        ON) # only find static libs
SET (Boost_USE_MULTITHREADED      ON)

FIND_PACKAGE( Boost 1.65.0 COMPONENTS program_options filesystem system thread REQUIRED )
#FIND_PACKAGE (Boost 1.65.0 COMPONENTS chrono timer test_exec_monitor system)
FIND_PACKAGE (Threads)
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
LINK_DIRECTORIES(${Boost_LIBRARY_DIRS})
message( "BOOST: ${Boost_LIBRARY_DIRS}")

# Mustache {{}}
add_subdirectory(external/mstch)
include_directories(${mstch_INCLUDE_DIR})
#target_link_libraries(your_project mstch)
