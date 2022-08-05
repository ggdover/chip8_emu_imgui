#include <stdio.h>
#include "gui.h"
#include "parser.h"

int main(int argc, char* argv[])
{
    // Use current time as seed for random generator
    srand(time(0));

    //----------------------------------------------------------
    // Read and Parse Chip8 rom file
    std::vector<int> op_codes;
    Parser::read_rom("../../roms/Maze [David Winter, 199x].ch8");

    //----------------------------------------------------------
    // Setup and run main GUI (rendering + events handling) thread

    SDL_Window* window;

    Gui::setup(window);
    
    Globals::ImguiState state;
    while (state.status == 0)
    {
        // Execute the next op-code (instruction)
        Parser::cycle();

        // Render GUI and capture keypresses and other interactions from GUI
        Gui::draw(window, state);

        // Poll imgui events (If gui is closed/exited etc.)
        Gui::pollEvents(window, state);
    }

    Gui::shutdown();

    return 0;
}
