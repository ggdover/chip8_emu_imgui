# One of two lines present depending on if output is a library (shared or static) or an executable
#add_library(mytarget)
add_executable(mytarget)

# Both all source and header files (.cpp and .h) should be listed in target_sources
# (So basically all files in 'src' directory and recursivley in all subdirectories)
target_sources(mytarget
	PRIVATE
		mytarget.cpp
		gui.h
		gui.cpp
		globals.h
		globals.cpp
		parser.h
		parser.cpp
		op.h
		op.cpp
		utils.h
		utils.cpp
)

# Incase there are any shared or static libraries that we are linking to
target_link_libraries(mytarget
    ${SDL2_LIBRARIES}
	${OPENGL_gl_LIBRARY}
	myimgui
)
