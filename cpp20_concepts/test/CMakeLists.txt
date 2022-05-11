set(TARGET concept_tests)

add_executable(${TARGET})
target_sources(${TARGET} PRIVATE tests.cpp)
target_link_libraries(${TARGET} PRIVATE concept_lib GTest::gtest
                                        GTest::gtest_main)
add_test(NAME ${TARGET} COMMAND ${TARGET})
