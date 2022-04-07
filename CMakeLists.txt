cmake_minimum_required(VERSION 3.8)

project("cpp20_refresh")
set(CMAKE_CXX_STANDARD 20)
add_compile_options(-std=c++2a)
add_compile_options(-fmodules-ts)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_program(CONAN_PROGRAM "conan")

if(NOT CONAN_PROGRAM)
  execute_process(COMMAND pip install conan)
endif()
# Setup conan
list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
  file(
    DOWNLOAD
    "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
    "${CMAKE_BINARY_DIR}/conan.cmake")
endif()
include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(CONANFILE conanfile.txt BASIC_SETUP CMAKE_TARGETS BUILD missing)
set(CMAKE_MAP_IMPORTED_CONFIG_RELEASE "Release;RelWithDebInfo;")
set(CMAKE_MAP_IMPORTED_CONFIG_RELWITHDEBINFO "RelWithDebInfo;Release;")
set(CMAKE_MAP_IMPORTED_CONFIG_MINSIZEREL "MinSizeRel;Release;RelWithDebInfo;")

enable_testing()
# change to gtest if use docker (lowercase)
find_package(GTest REQUIRED)

add_subdirectory(cpp20_modules)
