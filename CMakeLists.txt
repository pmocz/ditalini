cmake_minimum_required(VERSION 3.8)
project(
  ditalini 
  VERSION 0.1.0
  DESCRIPTION "a modern C++ project template"
  LANGUAGES CXX 
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O3")


#-------------------------------------------------------------------------------
# Define and configure the Project library
#-------------------------------------------------------------------------------

set(SOURCES "")
set(HEADERS "")
add_subdirectory(src)

set(MASTER_HEADER ${PROJECT_SOURCE_DIR}/src/ditalini.hpp)

include_directories(${DITALINI_INSTALL_INCLUDE_DIR})

add_library(ditalini ${SOURCES} ${HEADERS} ${MASTER_HEADER})


#-------------------------------------------------------------------------------
# Testing
#-------------------------------------------------------------------------------

# TODO: add_subdirectory(test)


#-------------------------------------------------------------------------------
# Documentation
#-------------------------------------------------------------------------------

# TODO: add_subdirectory(doc)


#-------------------------------------------------------------------------------
# Installation
#-------------------------------------------------------------------------------

set(INSTALL_INCLUDE_DIR include
  CACHE PATH "Relative path for installing header files.")
set(INSTALL_BIN_DIR bin
  CACHE PATH "Relative path for installing the binaries.")
set(INSTALL_LIB_DIR lib
  CACHE PATH "Relative path for installing the library.")

target_include_directories(ditalini BEFORE
  PUBLIC
    $<INSTALL_INTERFACE:${INSTALL_INCLUDE_DIR}>)

# Install the library
install(TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}Targets
  RUNTIME DESTINATION ${INSTALL_BIN_DIR}
  LIBRARY DESTINATION ${INSTALL_LIB_DIR}
  ARCHIVE DESTINATION ${INSTALL_LIB_DIR})

# Install the master header
install(FILES ${MASTER_HEADERS} DESTINATION ${INSTALL_INCLUDE_DIR}/ditalini)

# Install the headers
#install(DIRECTORY ${PROJECT_SOURCE_DIR}/src
#  DESTINATION ${INSTALL_INCLUDE_DIR}/ditalini
#  FILES_MATCHING PATTERN "*.hpp")
