set(SOURCE_FILES src/main.cpp
				 src/PuzzleApp.cpp
				 )
				 
set(HEADERS headers/main.h 
			headers/PuzzleApp.h 
			res/headers/BACKGROUND.h
			)	
			
set(RESOURCES res/image_resources.rc)

set(XPM res/xpm/aaaaaaaa_logo.XPM
		)

if(WIN32)
add_executable(PuzzleApp WIN32)
else()
add_executable(PuzzleApp)
endif()
target_sources(PuzzleApp PRIVATE
                          ${SOURCE_FILES} 
	                      ${HEADERS} 
	                      ${RESOURCES}
						  ${XPM}
	          )


target_include_directories(PuzzleApp PUBLIC headers res/xpm res/headers)
add_subdirectory(lib/wxImagePanel)
target_link_libraries(PuzzleApp wxImagePanel)


