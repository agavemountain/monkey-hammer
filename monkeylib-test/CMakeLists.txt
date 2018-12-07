add_project(monkeylib-test 
    "Tests for the Monkey Library"
    monkeylib )

file(GLOB MONKEY_CORE_TESTS_SRC
  "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
  )
  
if (AUTORUN_UNIT_TESTS)
    enable_testing()
endif()

# enable ctest
enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/monkeylib/include)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(monkeylib-test ${MONKEY_CORE_TESTS_SRC} )
target_link_libraries(monkeylib-test monkeylib cppunit)
add_test(NAME core_test COMMAND monkeylib-test)
