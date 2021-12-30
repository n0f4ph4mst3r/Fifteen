set(TESTS_SOURCE PuzzleTests.cc)
set (CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_executable(Tests ${TESTS_SOURCE})
target_include_directories(Tests PRIVATE headers)
add_test(NAME TEST_ALL COMMAND Tests)


