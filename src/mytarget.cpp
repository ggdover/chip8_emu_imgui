#include <stdio.h>
#include "gui.h"

int main(int argc, char* argv[])
{
    SDL_Window* window;

    Gui::setup(window);
    
    ImguiState state;
    while (state.status == 0)
    {
        // Render GUI and capture keypresses and other interactions from GUI
        Gui::draw(window, state);

        // Poll imgui events (If gui is closed/exited etc.)
        Gui::pollEvents(window, state);
    }

    Gui::shutdown();

    return 0;
}
