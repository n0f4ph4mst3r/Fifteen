set(SOURCE_FILES src/Puzzle.cpp)			 
set(HEADERS headers/Puzzle.h)

add_library(Puzzle)

target_sources(Puzzle
  PRIVATE
    ${SOURCE_FILES} 
	${HEADERS})
target_include_directories(Puzzle PUBLIC headers)



