add_project(monkey-comment "Code Commenting Utility" monkeylib )

file(GLOB MONKEY_COMMENT_SRC "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

include_directories(${CMAKE_SOURCE_DIR}/monkeylib/include)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(monkey-comment ${MONKEY_COMMENT_SRC} )
target_link_libraries(monkey-comment monkeylib  ${Boost_LIBRARIES} )
