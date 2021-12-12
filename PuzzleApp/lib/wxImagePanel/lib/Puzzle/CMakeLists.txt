set(SOURCE_FILES src/Puzzle.cpp)			 
set(HEADERS headers/Puzzle.h)

add_library(Puzzle)

target_sources(Puzzle
  PRIVATE
    ${SOURCE_FILES} 
	${HEADERS} 
              )
target_include_directories(Puzzle PUBLIC headers)
target_link_libraries(Puzzle ${CONAN_LIBS})

target_compile_features(Puzzle PUBLIC cxx_std_20)
target_compile_options(Puzzle PUBLIC -Wall -O2)



