#include "examples/imgui_impl_sdl.h"
#include "types.h"

#include <string>

class Gui
{
    public:
        /*
         * SUMMARY
         * Steps to setup imgui before 'Gui::draw()' can be called
         *
         * PARAMETERS
         * - window [out] = Instance is instantiated inside this function and needs to be passed when calling 'Gui::draw()' later
         */
        static int setup(SDL_Window*& window);

        /*
         * SUMMARY
         * Should be called in a loop continously
         *
         * PARAMETERS
         * - window [in] = The instance that is instantiated when passed to function 'Gui::setup()'
         */
        static ImguiState draw(SDL_Window* window);

        static inline bool key(const std::string text, bool sameLine);

        static int shutdown();
};
