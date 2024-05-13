set(SRCS
  main.cpp
  utils/square.cpp
)

set(HDRS
  ditalini.hpp
  utils/square.cpp
  utils/utils.cpp
)

convert_filenames_to_full_paths(SRCS)
convert_filenames_to_full_paths(HDRS)

set(SOURCES ${SOURCES} ${SRCS} PARENT_SCOPE)
set(HEADERS ${HEADERS} ${HDRS} PARENT_SCOPE)