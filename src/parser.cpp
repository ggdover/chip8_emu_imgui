#include "parser.h"
#include <stdio.h>
#include <assert.h>

void Parser::read_rom(std::string filepath, std::vector<int>& op_codes)
{
    FILE* fp;
    size_t count = 0;

    fp = fopen(filepath.c_str(), "r");
    if (fp == NULL)
    {
        printf("error open file\n");
        return;
    }

    do
    {
        int msb_byte = fgetc(fp);
        if (EOF == msb_byte)
        {
            printf("msb_byte EOF. File reading done!\n");
            break;
        }

        int lsb_byte = fgetc(fp);
        if (EOF == lsb_byte)
        {
            printf("ERROR! lsb_byte EOF\n");
            assert(false);
            break;
        }

        int opcode = (msb_byte << 8) + lsb_byte; // 16-bit, size of a chip8 instruction
        printf("msb = %2x | lsb = %2x | opcode = %4x\n", msb_byte, lsb_byte, opcode);
        op_codes.push_back(opcode);

        ++count;
    } while(1);

    fclose(fp);
}

//#### Function that parses op_code and couples each op_code with a function call
void Parser::parse_op_codes(std::vector<int> op_codes)
{
    for (auto op_code : op_codes)
    {
        parse_op_code(op_code);
    }
}

void Parser::parse_op_code(int op_code)
{
    if ( !(0xF000 & op_code) ) // 0nnn, SYS addr, Jump to a machine code routine at nnn
    {

    }
    else if (0x00E0 == op_code) // CLS. Clear the display
    {

    }
    else if (0x00EE == op_code) // RET. return from subroutine
    {

    }
    else if (0x1000 & op_code) // 1nnn - JP addr. Jump to location nnnn
    {

    }
    else if (0x2000 & op_code) // 2nnn - CALL addr. Call subroutine at nnn
    {

    }
    else if (0x3000 & op_code) // 3xkk - SE Vx, byte. Skip next instruction if Vx == kk
    {

    }
    else if (0x4000 & op_code) // 4xkk - SNE Vx, byte. Skip next instruction if Vx != kk
    {

    }
    else if (0x5000 & op_code) // 5xy0 - SE Vx, Vy. Skip next instruction if Vx == Vy
    {

    }
    else if (0x6000 & op_code) // 6xkk - LD Vx, byte. Set Vx == kk
    {

    }




    /*switch (op_code)
    {


        case 0x00E0: // CLS, clear screen
        {
            

            break;
        }
        case 0x00EE: // RET, return from subroutine
        {


            break;
        }

        
        default:
            printf("UNKNOWN OP_CODE: 0x%x4", op_code);
            break;
    }*/
}