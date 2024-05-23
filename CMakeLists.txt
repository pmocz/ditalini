cmake_minimum_required(VERSION 3.8)

# Get ${VERSION} from git tag
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
include(VersionFromGit)
version_from_git()

project(
  ditalini
  VERSION ${VERSION}
  DESCRIPTION "a modern C++ project template"
  LANGUAGES CXX)

# Options: Things you can set via commandline options to cmake 
# (e.g. -DENABLE_LTO=[ON|OFF])
option(
  ENABLE_WARNINGS_SETTINGS
  "Allow target_set_warnings to add flags and defines.
  Set this to OFF if you want to provide your own warning parameters."
  ON)
option(ENABLE_LTO "Enable link time optimization" ON)

# Include cmake files
include(ConfigSafeGuards)
include(Colors)
include(CTest)
include(Doctest)
include(Documentation)
include(LTO)
include(Misc)
include(Warnings)
include(FindClangFormat)

# Check for LTO support
find_lto(CXX)

# --------------------------------------------------------------------------------
# Files
# --------------------------------------------------------------------------------
set(SOURCE_FILES
    src/ditalini.cpp)
set(HEADER_FILES
    include/ditalini.h)

set(APP_NAME ditalini_app) # The main executable
set(LIBRARY_NAME ditalini) # Default name for the library built from src/*.cpp

# --------------------------------------------------------------------------------
# Build
# --------------------------------------------------------------------------------
# Compile all sources into a library
add_library(${LIBRARY_NAME} OBJECT ${SOURCE_FILES})

# Lib needs its header files, and users of the library must also see these
# (PUBLIC)
target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Set the compile options you want
target_set_warnings(
  ${LIBRARY_NAME}
  ENABLE
  ALL
  AS_ERROR
  ALL
  DISABLE
  Annoying)
# target_compile_options(${LIBRARY_NAME} ... )  # For setting manually

# Add an executable for the file app/main.cpp.
add_executable(${APP_NAME} app/main.cpp) # Name of exec. and location of file.
target_link_libraries(
  ${APP_NAME} PRIVATE ${LIBRARY_NAME}) # Link the executable to library.
target_set_warnings(
  ${APP_NAME}
  ENABLE
  ALL
  AS_ERROR
  ALL
  DISABLE
  Annoying) # Set warnings (if needed).
target_enable_lto(
  ${APP_NAME} optimized) # enable link-time-optimization if available for
                         # non-debug configurations

# Set the properties you require, e.g. what C++ standard to use. Here applied to
# library and main (change as needed).
set_target_properties(
  ${LIBRARY_NAME} ${APP_NAME}
  PROPERTIES CXX_STANDARD 17
             CXX_STANDARD_REQUIRED YES
             CXX_EXTENSIONS NO)

# rename main app
#XXXset_target_properties(${APP_NAME} PROPERTIES OUTPUT_NAME ${LIBRARY_NAME})

# Set up tests (see test/CMakeLists.txt).
add_subdirectory(test)


# --------------------------------------------------------------------------------
# Build Python Library
# --------------------------------------------------------------------------------
set(PYTHON_FILES
    python/ditalini/ditalini_ext.cpp)

set(PYTHON_EXT_NAME ditalini_ext)

# Try to import all Python components potentially needed by nanobind
find_package(Python 3.11 EXACT REQUIRED
  REQUIRED COMPONENTS Interpreter Development.Module
  OPTIONAL_COMPONENTS Development.SABIModule)

# Detect the installed nanobind package and import it into CMake
execute_process(
  COMMAND "${Python_EXECUTABLE}" -m nanobind --cmake_dir
  OUTPUT_STRIP_TRAILING_WHITESPACE OUTPUT_VARIABLE NB_DIR)
list(APPEND CMAKE_PREFIX_PATH "${NB_DIR}")
find_package(nanobind CONFIG REQUIRED)

nanobind_add_module(${PYTHON_EXT_NAME} ${SOURCE_FILES} ${HEADER_FILES} ${PYTHON_FILES})

target_link_libraries(${PYTHON_EXT_NAME} PUBLIC)

install(TARGETS ${PYTHON_EXT_NAME} 
  LIBRARY DESTINATION ${LIBRARY_NAME})

# rename python package
set_target_properties(${PYTHON_EXT_NAME} PROPERTIES OUTPUT_NAME ${LIBRARY_NAME})
