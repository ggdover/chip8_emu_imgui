
#include "globals.h"

// Initialize all the public static members of "Globals" class
unsigned char Globals::DISPLAY_MATRIX[] = {0};
unsigned char Globals::V[] = {0};
unsigned int Globals::I = 0;
unsigned int Globals::PC = 0;
unsigned char Globals::SP = 0;
std::vector<unsigned char> Globals::MEMORY;
std::stack<unsigned int> Globals::STACK;
