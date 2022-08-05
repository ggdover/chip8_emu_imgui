
#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <vector>
#include <stack>

class Globals
{
	public:
		// Start address for most Chip-8 programs 
		// (except for the ones intended for ETI 660, that instead start at 0x600)
		static const unsigned int START_ADDR = 0x200;

		// DISPLAY_MATRIX Width
		static const unsigned int DISPLAY_W = 64;

		// DISPLAY_MATRIX Height
		static const unsigned int DISPLAY_H = 32;

		static const unsigned int STACK_SIZE = 16;

		// Holds information coming from imgui.
		// - Status to indicate if we have run into an error
		// - State of keypresses and other interaction from gui
		typedef struct _imgui_state
		{
			// Return status. 0 means OK, anything else means an error occured
			int status = 0;
			// State of keys, whether pressed or not
			bool key_1 = false;
			bool key_2 = false;
			bool key_3 = false;
			bool key_c = false;
			bool key_4 = false;
			bool key_5 = false;
			bool key_6 = false;
			bool key_d = false;
			bool key_7 = false;
			bool key_8 = false;
			bool key_9 = false;
			bool key_e = false;
			bool key_a = false;
			bool key_0 = false;
			bool key_b = false;
			bool key_f = false;
		} ImguiState;

		// Represents all the pixels of monochromatic display and their state
		// 0 = Unfilled pixel (black color)
		// 1 = Fill pixel (white color)
		static unsigned char DISPLAY_MATRIX[DISPLAY_W * DISPLAY_H];

		// 16 general purpose 8-bit registers.
		// Usually referred to as Vx, where
		// x is a hexadecimal digit from (0 to F)
		// (VF should not be used by any program,
		//  as it is used as a flag by some instructions)
		static unsigned char V[16];

		// 16-bit (but only lowest 12-bits are used) 
		// register used to store memory addresses
		static unsigned int I;

		// 16-bit register, the program-counter register
		// store the currently executing address
		static unsigned int PC;

		// 8-bit regiser, stack-pointer register
		// used to point to the topmost level of the stack (STACK)
		// - The stack is an array of 16 16-bit values, used
		//   to store the address that the interpreter should
		//   return to when finished with a subroutine.
		//   Chip8 allows for up to 16 levels of nested subroutines.
		static unsigned char SP;

		// Stack that can hold up to 16 different addresses.
		// Whenever a subroutine is called the current PC address
		// will be pushed to top of the stack and then when a subroutine
		// is returned from, it will pop the address at the top of the
		// stack and load it into the PC register.
		static std::stack<unsigned int> STACK;

		// A list of all the bytes of the rom.
		// Which is semantically the same as all the bytes in 
		// the chip-8 memory, starting from the address START_ADDR.
		static std::vector<unsigned char> MEMORY;
};

#endif // _GLOBALS_H_
