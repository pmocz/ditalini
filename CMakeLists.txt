cmake_minimum_required(VERSION 3.8)
project(
  ditalini 
  VERSION 0.1.0
  DESCRIPTION "a modern C++ project template"
  LANGUAGES CXX 
)

# Options: Things you can set via commandline options to cmake (e.g. -DENABLE_LTO=[ON|OFF])
option(ENABLE_WARNINGS_SETTINGS "Allow target_set_warnings to add flags and defines.
                                 Set this to OFF if you want to provide your own warning parameters." ON)
option(ENABLE_LTO "Enable link time optimization" ON)
option(ENABLE_DOCTESTS "Include tests in the library. Setting this to OFF will remove all doctest related code.
                        Tests in test/*.cpp will still be enabled." ON)

# Include cmake files
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
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
#                         Files
# --------------------------------------------------------------------------------
set(SOURCES          # All .cpp files in src/
  src/ditalini.cpp
)
set(TESTFILES        # Just include here the main .cpp file in test/
  test/main.cpp
)

set(APP_NAME main)          # The main executable
set(LIBRARY_NAME ditalini)  # Default name for the library built from src/*.cpp

# --------------------------------------------------------------------------------
#                            Build
# --------------------------------------------------------------------------------
# Compile all sources into a library
add_library(${LIBRARY_NAME} OBJECT ${SOURCES})

# Lib needs its header files, and users of the library must also see these (PUBLIC)
target_include_directories(${LIBRARY_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Set the compile options you want
target_set_warnings(${LIBRARY_NAME} ENABLE ALL AS_ERROR ALL DISABLE Annoying)
# target_compile_options(${LIBRARY_NAME} ... )  # For setting manually

# Add an executable for the file app/main.cpp.
add_executable(${APP_NAME} app/main.cpp)   # Name of exec. and location of file.
target_link_libraries(${APP_NAME} PRIVATE ${LIBRARY_NAME})  # Link the executable to library (if it uses it).
target_set_warnings(${APP_NAME} ENABLE ALL AS_ERROR ALL DISABLE Annoying) # Set warnings (if needed).
target_enable_lto(${APP_NAME} optimized)  # enable link-time-optimization if available for non-debug configurations

# Set the properties you require, e.g. what C++ standard to use. Here applied to library and main (change as needed).
set_target_properties(
    ${LIBRARY_NAME} ${APP_NAME}
      PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

# rename main app
set_target_properties(${APP_NAME} PROPERTIES OUTPUT_NAME ${LIBRARY_NAME})

# Set up tests (see test/CMakeLists.txt).
add_subdirectory(test)
