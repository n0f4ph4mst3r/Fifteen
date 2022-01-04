cmake_minimum_required(VERSION 3.22)

get_property(is_multi_config GLOBAL PROPERTY GENERATOR_IS_MULTI_CONFIG)
if(is_multi_config AND DEFINED CMAKE_BUILD_TYPE)
SET(CMAKE_CONFIGURATION_TYPES ${CMAKE_BUILD_TYPE} CACHE STRING "" FORCE)
endif()

project(PuzzleProject)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake"
                  "${CMAKE_BINARY_DIR}/conan.cmake")
endif()

list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

include(${CMAKE_BINARY_DIR}/conan.cmake)
				 				 
if( NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES )
   set( CMAKE_BUILD_TYPE "Release" )
endif()

function(conan_configure_install build_type gen)
    conan_cmake_configure(REQUIRES wxwidgets/3.1.5@bincrafters/stable
                                   gtest/1.10.0
	                      GENERATORS ${gen})
						 
    conan_cmake_autodetect(settings BUILD_TYPE ${build_type})
    conan_cmake_install(PATH_OR_REFERENCE .
                        BUILD missing
                        SETTINGS ${settings})
endfunction()

if(is_multi_config)  
   foreach(TYPE ${CMAKE_CONFIGURATION_TYPES})
   conan_configure_install(${TYPE} cmake_find_package_multi)
   endforeach()
   
   set(WXWIDGETS_CONANPKG wxwidgets CONFIG)
   set(GTEST_CONANPKG gtest CONFIG)
   
elseif (DEFINED CMAKE_BUILD_TYPE)
   conan_configure_install(${CMAKE_BUILD_TYPE} cmake_find_package)
		   
   set(WXWIDGETS_CONANPKG wxwidgets)
   set(GTEST_CONANPKG GTest)
endif()

add_subdirectory(PuzzleApp)

if(CMAKE_GENERATOR MATCHES "Visual Studio")
   set_directory_properties(
      PROPERTIES
         VS_STARTUP_PROJECT PuzzleApp
   )
endif()

add_subdirectory(modules/Puzzle)
find_package(${WXWIDGETS_CONANPKG})
target_link_libraries(Puzzle wxwidgets::wxwidgets)
target_compile_features(Puzzle PUBLIC cxx_std_20)

set(DEBUG_OPTIONS -Wall)
set(RELEASE_OPTIONS -Wall -O2)

target_compile_options(Puzzle PUBLIC "$<$<CONFIG:DEBUG>:${DEBUG_OPTIONS}>")
target_compile_options(Puzzle PUBLIC "$<$<CONFIG:RELEASE>:${RELEASE_OPTIONS}>")

add_subdirectory(modules/wxImagePanel)
target_link_libraries(wxImagePanel Puzzle)
target_link_libraries(PuzzleApp wxImagePanel)

enable_testing()
add_subdirectory(tests)
find_package(${GTEST_CONANPKG})
target_link_libraries(Tests PRIVATE Puzzle GTest::gtest GTest::gtest_main)
add_dependencies(Tests PuzzleApp)

install(TARGETS PuzzleApp DESTINATION ${CMAKE_SOURCE_DIR}/bin)













