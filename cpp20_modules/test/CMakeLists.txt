set(TARGET tests)
add_custom_target(
  std_modules ALL
  COMMAND ${CMAKE_COMMAND} -E echo "Building standard library modules"
  COMMAND g++ -fmodules-ts -std=c++20 -c -x c++-system-header iostream
  COMMAND g++ -fmodules-ts -std=c++20 -c -x c++-system-header cmath)

add_executable(${TARGET})
target_sources(${TARGET} PRIVATE math.cpp tests.cpp)
target_link_libraries(${TARGET} PRIVATE lib GTest::gtest GTest::gtest_main)
add_dependencies(${TARGET} std_modules)
add_test(NAME ${TARGET} COMMAND ${TARGET})
