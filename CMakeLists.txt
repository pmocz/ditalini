cmake_minimum_required(VERSION 3.8)
project(ditalini VERSION 0.1 LANGUAGES CXX DESCRIPTION "ditalini is a modern C++ project template")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(DITALINI_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(DITALINI_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(DITALINI_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

include_directories(${DITALINI_INSTALL_INCLUDE_DIR})

add_subdirectory(src)
add_subdirectory(test)