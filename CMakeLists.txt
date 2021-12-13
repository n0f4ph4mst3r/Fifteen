cmake_minimum_required(VERSION 3.22)

project(PuzzleProject)

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
else()
    message(FATAL_ERROR "NO CONANBUILDINFO.CMAKE FILE FOUND")
endif()
conan_basic_setup()

add_subdirectory(PuzzleApp)

if( CMAKE_GENERATOR MATCHES "Visual Studio" )
   set_directory_properties(
      PROPERTIES
         VS_STARTUP_PROJECT PuzzleApp
   )
endif()

add_subdirectory(libs/Puzzle)
target_link_libraries(Puzzle ${CONAN_LIBS})
target_compile_features(Puzzle PUBLIC cxx_std_20)
target_compile_options(Puzzle PUBLIC -Wall -O2)

add_subdirectory(libs/wxImagePanel)
target_link_libraries(wxImagePanel Puzzle)
target_link_libraries(PuzzleApp wxImagePanel)

enable_testing()
add_subdirectory(tests)
add_dependencies(Tests PuzzleApp)


