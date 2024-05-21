include(FetchContent)
FetchContent_Declare(
  DocTest
  GIT_REPOSITORY "https://github.com/onqtam/doctest"
  GIT_TAG "v2.4.11")

FetchContent_MakeAvailable(DocTest)
include_directories(${DOCTEST_INCLUDE_DIR})
