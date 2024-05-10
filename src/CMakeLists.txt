cmake_minimum_required(VERSION 3.8)
project(ditalini)

add_subdirectory(utils)

set(SOURCE_FILES main.cpp)

add_executable(ditalini ${SOURCE_FILES})
target_link_libraries(ditalini utils)
install(TARGETS ditalini DESTINATION ${DITALINI_INSTALL_BIN_DIR})