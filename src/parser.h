
// #### This file:
// Responsible for reading binary data from Chip8 rom file
// and parse the data into an accessable data-structure

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
         * Read op codes from chip8 rom file
         *
         * PARAMETERS
         * - filepath [in]  = Filepath to rom file to be read
         * - op_codes [out] = List of op codes read from rom file
         */
        static void read_rom(std::string filepath, std::vector<int>& op_codes);

        /*
         * SUMMARY
         * TBD
         *
         * PARAMETERS
         * TBD
         */
        void parse_op_codes(std::vector<int> op_codes);

    private:
        void parse_op_code(int op_code);
};
