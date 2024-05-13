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
# Installation of Library and Executable
#-------------------------------------------------------------------------------


# helper
function(convert_filenames_to_full_paths NAMES)
  unset(tmp_names)
  foreach(name ${${NAMES}})
    list(APPEND tmp_names ${CMAKE_CURRENT_SOURCE_DIR}/${name})
  endforeach()
  set(${NAMES} ${tmp_names} PARENT_SCOPE)
endfunction()

set(SOURCES "")
set(HEADERS "")
add_subdirectory(src)

set(MASTER_HEADER ${PROJECT_SOURCE_DIR}/src/ditalini.hpp)

set(INSTALL_INCLUDE_DIR include)
set(INSTALL_BIN_DIR bin)
set(INSTALL_LIB_DIR lib)

add_library(libditalini SHARED ${SOURCES} ${HEADERS} ${MASTER_HEADER})

add_executable(ditalini ${SOURCES})

target_link_libraries(ditalini libditalini) 


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

#set(INSTALL_INCLUDE_DIR include
#  CACHE PATH "Relative path for installing header files.")
#set(INSTALL_BIN_DIR bin
#  CACHE PATH "Relative path for installing the binaries.")
#set(INSTALL_LIB_DIR lib
#  CACHE PATH "Relative path for installing the library.")

#target_include_directories(ditalini BEFORE
#  PUBLIC
#    $<INSTALL_INTERFACE:${INSTALL_INCLUDE_DIR}>)

# Install the library
#install(TARGETS ${PROJECT_NAME}
#  EXPORT ${PROJECT_NAME}Targets
#  RUNTIME DESTINATION ${INSTALL_BIN_DIR}
#  LIBRARY DESTINATION ${INSTALL_LIB_DIR}
#  ARCHIVE DESTINATION ${INSTALL_LIB_DIR})

# Install the master header
#install(FILES ${MASTER_HEADERS} DESTINATION ${INSTALL_INCLUDE_DIR}/ditalini)

# Install the headers
#install(DIRECTORY ${PROJECT_SOURCE_DIR}/src
#  DESTINATION ${INSTALL_INCLUDE_DIR}/ditalini
#  FILES_MATCHING PATTERN "*.hpp")
