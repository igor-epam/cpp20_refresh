set(TARGET tests)
add_executable(${TARGET} tests.cpp)
target_link_libraries(${TARGET} PRIVATE lib)
add_test(NAME ${TARGET} COMMAND ${TARGET})
