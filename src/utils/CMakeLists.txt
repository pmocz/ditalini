cmake_minimum_required(VERSION 3.8)
project(utils)

set(SOURCE_FILES
  square.hpp
  square.cpp
)

add_library(utils SHARED STATIC ${SOURCE_FILES})

install(TARGETS utils DESTINATION ${DITALINI_INSTALL_LIB_DIR})
install(FILES utils.hpp DESTINATION ${DITALINI_INSTALL_INCLUDE_DIR})