cmake_minimum_required(VERSION 3.22)

project(PuzzleProject)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_run(CONANFILE conanfile.txt BASIC_SETUP CMAKE_TARGETS NO_OUTPUT_DIRS)

add_subdirectory(PuzzleApp)

if( CMAKE_GENERATOR MATCHES "Visual Studio" )
   set_directory_properties(
      PROPERTIES
         VS_STARTUP_PROJECT PuzzleApp
   )
endif()

add_subdirectory(modules/Puzzle)
conan_target_link_libraries(Puzzle)
target_compile_features(Puzzle PUBLIC cxx_std_20)
target_compile_options(Puzzle PUBLIC -Wall -O2)

add_subdirectory(modules/wxImagePanel)
target_link_libraries(wxImagePanel Puzzle)
target_link_libraries(PuzzleApp wxImagePanel)

enable_testing()
add_subdirectory(tests)
add_dependencies(Tests PuzzleApp)


