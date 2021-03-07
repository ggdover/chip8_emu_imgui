#include "parser.h"
#include <stdio.h>
#include <assert.h>
#include "op.h"

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
    if (0x00E0 == op_code)
    {
        Op::clear();
    }
    else if (0x00EE == op_code)
    {
        Op::ret();
    }
    else if (0x1000 & op_code == 0x1000)
    {
        Op::jp_addr(op_code);
    }
    else if (0x2000 & op_code == 0x2000)
    {
        Op::call_addr(op_code);
    }
    else if (0x3000 & op_code == 0x3000)
    {
        Op::se_vx_byte(op_code);
    }
    else if (0x4000 & op_code == 0x4000)
    {
        Op::sne_vx_byte(op_code);
    }
    else if (0x5000 & op_code == 0x5000)
    {
        Op::se_vx_vy(op_code);
    }
    else if (0x6000 & op_code == 0x6000)
    {
        Op::load_vx_byte(op_code);
    }
    else
    {
        printf("Unknown Op_code = %x\n", op_code);
    }
}