set(SOURCE_FILES src/main.cpp
				 src/PuzzleApp.cpp
				 )
				 
set(HEADERS headers/main.h 
			headers/PuzzleApp.h 
			res/headers/BACKGROUND.h
			)	
			
set(RESOURCES res/image_resources.rc)

set(XPM res/xpm/aaaaaaaa_logo.XPM)

set(PNG res/images/BACKGROUND.png)

if(WIN32)
add_executable(PuzzleApp WIN32)
target_sources(PuzzleApp PRIVATE ${RESOURCES})
source_group("Resource files" FILES ${RESOURCES})						  
else()
add_executable(PuzzleApp)
endif()

target_sources(PuzzleApp PRIVATE
                          ${SOURCE_FILES} 
	                      ${HEADERS} 
						  ${XPM}
	          )		  
source_group("XPM files" FILES ${XPM})

if(APPLE)
target_sources(PuzzleApp PRIVATE ${PNG})
set_target_properties(PuzzleApp PROPERTIES
  MACOSX_BUNDLE TRUE
  MACOSX_FRAMEWORK_IDENTIFIER org.cmake.PuzzleApp
  RESOURCE "${PNG}")
endif()

target_include_directories(PuzzleApp PUBLIC headers res/xpm res/headers)


