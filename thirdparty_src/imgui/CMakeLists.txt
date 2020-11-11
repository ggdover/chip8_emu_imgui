
# imgui is a cross-platform library for creating GUI, as in: window with buttons and text elements etc.
# Imgui itself only provides a front-end of a gui library and so the backend is handled by other lower-level
# libraries. 
# There is also a number of choices when it comes to the backend and all of them along with example code showing
# how you can implement any of them exists in the "examples" folder in the imgui repository.
# This level of customizability means that the way you integrate imgui into your project/codebase is up to you.
# In this project we're already using cmake as buildsystem, so we just write this cmake file to build the imgui source code.

add_library(myimgui)

target_sources(myimgui
    PRIVATE
        # The backend can be divided in two parts: Renderer (Draws the graphics) and Event handling (Mouse/Keyboard inputs, Sound etc.)
        # In this example, for backend, we are using
        # Event handling: SDL2
        # Rendering: OpenGL3
        imgui/examples/imgui_impl_sdl.h
        imgui/examples/imgui_impl_sdl.cpp
        imgui/examples/imgui_impl_opengl3.h
        imgui/examples/imgui_impl_opengl3.cpp
        # imgui header files
        imgui/imgui.h
        imgui/imconfig.h
        imgui/imgui_internal.h
        imgui/imstb_rectpack.h
        imgui/imstb_textedit.h
        imgui/imstb_truetype.h
        # imgui source files
        imgui/imgui.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_demo.cpp
)

target_link_libraries(myimgui
    glad
)

target_include_directories(myimgui
    PUBLIC
        imgui
)
