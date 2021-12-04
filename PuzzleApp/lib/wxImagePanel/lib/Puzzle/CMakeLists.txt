set(SOURCE_FILES src/Puzzle.cpp)			 
set(HEADERS headers/Puzzle.h)

add_library(Puzzle)

target_sources(Puzzle
  PRIVATE
    ${SOURCE_FILES} 
	${HEADERS} 
              )
target_include_directories(Puzzle PUBLIC headers)
target_link_libraries(Puzzle 
                            ${CONAN_LIBS_WXWIDGETS}
							${CONAN_LIBS_ZLIB}
							${CONAN_LIBS_EXPAT}
							${CONAN_LIBS_LIBPNG}
							${CONAN_LIBS_LIBTIFF}
							${CONAN_LIBS_LIBJPEG}
							${CONAN_LIBS_XZ_UTILS}
							${CONAN_LIBS_JBIG}
                     )



