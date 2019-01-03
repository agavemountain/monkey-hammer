add_project(codemonkey "Code Monkey Utility" monkeylib )

file(GLOB CODEMONKEY_SRC "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

include_directories(${CMAKE_SOURCE_DIR}/monkeylib/include)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(codemonkey ${CODEMONKEY_SRC} )
target_link_libraries(codemonkey monkeylib  ${Boost_LIBRARIES} )
