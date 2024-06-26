# --------------------------------------------------------------------------------
# Miscellaneous
# --------------------------------------------------------------------------------
# Have CMake parse the config file, generating the config header, with correct
# definitions. Here only used to make version number available to the source
# code. Include "ditaliniConfig.h" (no .in suffix) in the source.
configure_file("${PROJECT_SOURCE_DIR}/include/ditaliniConfig.h.in"
               "${PROJECT_BINARY_DIR}/ditaliniConfig.h")
# add the binary tree to the search path for include files so that we will find
# ditaliniConfig.h
include_directories("${PROJECT_BINARY_DIR}")

# Ask CMake to output a compile_commands.json file for use with things like Vim
# YCM.
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
