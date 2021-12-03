set(SOURCE_FILES src/wxImagePanel.cpp)		 
set(HEADERS headers/wxImagePanel.h)

add_library(wxImagePanel)

target_sources(wxImagePanel
  PRIVATE
    ${SOURCE_FILES} 
	${HEADERS} 
              )
			 
target_include_directories(wxImagePanel PUBLIC headers)
add_subdirectory(lib/Puzzle)
target_link_libraries(wxImagePanel Puzzle)