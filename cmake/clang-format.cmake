# --------------------------------------------------------------------------------
#                         Clang
# --------------------------------------------------------------------------------
# Add a make target 'format' to automatically format all source files

# Find all source files
set(CLANG_FORMAT_CXX_FILE_EXTENSIONS ${CLANG_FORMAT_CXX_FILE_EXTENSIONS} *.cpp *.h *.cxx *.hxx *.hpp *.cc *.ipp)
file(GLOB_RECURSE ALL_SOURCE_FILES ${CLANG_FORMAT_CXX_FILE_EXTENSIONS})

# Don't include some common build folders
set(CLANG_FORMAT_EXCLUDE_PATTERNS ${CLANG_FORMAT_EXCLUDE_PATTERNS} "/CMakeFiles/" "cmake")

# get all project files file
foreach (SOURCE_FILE ${ALL_SOURCE_FILES}) 
    foreach (EXCLUDE_PATTERN ${CLANG_FORMAT_EXCLUDE_PATTERNS})
        string(FIND ${SOURCE_FILE} ${EXCLUDE_PATTERN} EXCLUDE_FOUND) 
        if (NOT ${EXCLUDE_FOUND} EQUAL -1) 
            list(REMOVE_ITEM ALL_SOURCE_FILES ${SOURCE_FILE})
        endif () 
    endforeach ()
endforeach ()

add_custom_target(format
    COMMENT "Running clang-format to change files"
    COMMAND ${CLANG_FORMAT_BIN}
    -style=file
    -i
    ${ALL_SOURCE_FILES}
)
