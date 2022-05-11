set(TARGET concept_lib)
add_library(${TARGET})
set_target_properties(${TARGET} PROPERTIES LINKER_LANGUAGE CXX)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/include/hashable.h)

target_sources(${TARGET} PUBLIC ${SOURCES})
target_include_directories(${TARGET} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
