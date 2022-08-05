
// #### This file:
// Responsible for reading binary data from Chip8 rom file
// and parse them into op-code and execute/interpret them

//Memory Map:
//+---------------+= 0xFFF (4095) End of Chip-8 RAM
//|               |
//|               |
//|               |
//|               |
//|               |
//| 0x200 to 0xFFF|
//|     Chip-8    |
//| Program / Data|
//|     Space     |
//|               |
//|               |
//|               |
//+- - - - - - - -+= 0x600 (1536) Start of ETI 660 Chip-8 programs
//|               |
//|               |
//|               |
//+---------------+= 0x200 (512) Start of most Chip-8 programs
//| 0x000 to 0x1FF|
//| Reserved for  |
//|  interpreter  |
//+---------------+= 0x000 (0) Start of Chip-8 RAM

#include <vector>
#include <string>

class Parser
{
    public:
        /*
         * SUMMARY
         * Read the bytes of from the chip8 rom file and store it in global variable MEMORY
         *
         * PARAMETERS
         * - filepath [in]  = Filepath to rom file to be read
         */
        static void read_rom(std::string filepath);

        /*
         * SUMMARY
         * Step/Run a CPU cycle, which means take the address in PC register and 
         * execute the 16bit op_code from that address, including update PC register
         * to it's next correct value.
         */
        static void cycle();

    private:
        /*
         * SUMMARY
         * Read opcode and execute actions
         *
         * PARAMETERS
         * - op_code [in] = The op code to execute
         */
        static void execute(int op_code);
};
