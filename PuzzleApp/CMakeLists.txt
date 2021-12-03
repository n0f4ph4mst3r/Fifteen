set(SOURCE_FILES src/main.cpp
				 src/PuzzleApp.cpp
				 )
				 
set(HEADERS headers/main.h 
			headers/PuzzleApp.h 
			)	
			
set(RESOURCES res/app_icon.rc)

add_executable(PuzzleApp WIN32
                          ${SOURCE_FILES} 
	                      ${HEADERS} 
	                      ${RESOURCES}
	          )


target_include_directories(PuzzleApp PUBLIC headers)
add_subdirectory(lib/wxImagePanel)
target_link_libraries(PuzzleApp wxImagePanel)

if( CMAKE_GENERATOR MATCHES "Visual Studio" )
   set_directory_properties(
      PROPERTIES
         VS_STARTUP_PROJECT PuzzleApp
   )
endif()

