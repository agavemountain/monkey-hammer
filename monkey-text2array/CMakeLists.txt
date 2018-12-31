add_project(monkey-text2array "Text to code utility" monkeylib )

file(GLOB MONKEY_TEXT2ARRAY_SRC "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

include_directories(${CMAKE_SOURCE_DIR}/monkeylib/include)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(monkey-text2array ${MONKEY_TEXT2ARRAY_SRC} )
target_link_libraries(monkey-text2array monkeylib  ${Boost_LIBRARIES} )
