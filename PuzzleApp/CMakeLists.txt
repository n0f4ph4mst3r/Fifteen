set(SOURCE_FILES src/main.cpp
				 src/PuzzleApp.cpp
				 )
				 
set(HEADERS headers/main.h 
			headers/PuzzleApp.h 
			)	
			
set(RESOURCES res/image_resources.rc)

add_executable(PuzzleApp WIN32
                          ${SOURCE_FILES} 
	                      ${HEADERS} 
	                      ${RESOURCES}
	          )


target_include_directories(PuzzleApp PUBLIC headers)
add_subdirectory(lib/wxImagePanel)
target_link_libraries(PuzzleApp wxImagePanel)


