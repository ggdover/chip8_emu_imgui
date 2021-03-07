#include "examples/imgui_impl_sdl.h"
#include <string>
#include "globals.h"

#define PIXEL_W 10
#define PIXEL_H 10

// These represent window padding which I have eye-balled
// because I haven't found any proper way to get the actual
// values of these from imgui api.
#define WIN_PADDING_RIGHT 8
#define WIN_PADDING_BOTTOM 8

class Gui
{
    public:
        /*
         * SUMMARY
         * Steps to setup imgui before 'Gui::draw()' can be called
         *
         * PARAMETERS
         * - window [out] = Instance is instantiated inside this function and
         *                  needs to be passed when calling 'Gui::draw()' later
         */
        static int setup(SDL_Window*& window);

        /*
         * SUMMARY
         * Should be called in a loop continously
         *
         * PARAMETERS
         * - window [in] = The instance that is instantiated when passed to function 'Gui::setup()'
         * - state [Out] = Holds information on key presses and other gui interaction
         */
        static void draw(SDL_Window* window, ImguiState &state);

        /*
         * SUMMARY
         * TBD
         *
         * PARAMETERS
         * - window [in] = The instance that is instantiated when passed to function 'Gui::setup()'
         * - state [Out] = TBD
         */
        static void pollEvents(SDL_Window* window, ImguiState &state);

        /*
         * SUMMARY
         * Makes sure proper shutdown sequence of Gui
         *
         * RETURNS
         * TBD
         */
        static int shutdown();

    private:

        static inline bool key(const std::string text, bool sameLine);
};
