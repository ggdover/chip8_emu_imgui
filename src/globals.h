
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

#define DISPLAY_W 64
#define DISPLAY_H 32

// Represents all the pixels of monochromatic display and their state
// 0 = Unfilled pixel (black color)
// 1 = Fill pixel (white color)
extern char DISPLAY_MATRIX[DISPLAY_W * DISPLAY_H];

// 16 general purpose 8-bit registers.
// Usually referred to as Vx, where
// x is a hexadecimal digit from (0 to F)
// (VF should not be used by any program,
//  as it is used aas a flag by some instructions)
extern char V[16];

// 16-bit (but only lowest 12-bits are used) 
// register used to store memory addresses
extern int I;

// 16-bit register, the program-counter register
// store the currently executing address
extern int PC;

// 8-bit regiser, stack-pointer register
// used to point to the topmost level of the stack
// - The stack is an array of 16 16-bit values, used
//   to store the address that the interpreter should
//   return to when finished with a subroutine.
//   Chip8 allows for up to 16 levels of nested subroutines.
extern char SP;
