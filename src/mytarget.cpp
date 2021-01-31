#include <stdio.h>
#include "gui.h"

int main(int argc, char* argv[])
{
    printf("Hello world");

    //(void)Gui::imgui_example();

    SDL_Window* window;

    (void)Gui::setup(window);
    
    //while (1)
    //{
    	(void)Gui::draw(window);
    //}

    (void)Gui::shutdown();


    return 0;
}
