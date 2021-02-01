#include <stdio.h>
#include "gui.h"
#include "parser.h"

int main(int argc, char* argv[])
{
    //----------------------------------------------------------
    // Read and Parse Chip8 rom file
    std::vector<int> op_codes;
    Parser::read_rom("../../roms/Maze [David Winter, 199x].ch8", op_codes);

    //----------------------------------------------------------
    // Setup and run main GUI (rendering + events handling) thread

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
