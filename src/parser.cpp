#include "parser.h"
#include <assert.h>
#include "op.h"
#include "globals.h"
#include "utils.h"

void Parser::read_rom(std::string filepath)
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
        printf("msb = %2X | lsb = %2X | opcode = %0X", msb_byte, lsb_byte, opcode);
        Globals::MEMORY.push_back(msb_byte);
        Globals::MEMORY.push_back(lsb_byte);

        ++count;
    } while(1);

    printf("&MEMORY = %p MEMORY.size()= %lu", 
        (void*)&Globals::MEMORY, 
        Globals::MEMORY.size());

    fclose(fp);
}

void Parser::cycle()
{
    int prevPC = Globals::PC;

    int op_code = (Globals::MEMORY[Globals::PC] << 8) + Globals::MEMORY[Globals::PC+1];
    printf("PC = %d(0x%0X) op_code = %d(0x%0X)", Globals::PC, Globals::PC, op_code, op_code);
    execute(op_code);

    // Only update the PC register here if the op-code 
    // execution didn't update the register itself
    if (prevPC == Globals::PC)
    {
        Globals::PC += 2;
    }
}

void Parser::execute(int op_code)
{    
    if (0x00E0 == op_code)
    {
        Op::clear();
    }
    else if (0x00EE == op_code)
    {
        Op::ret();
    }
    else if ((0xF000 & op_code) == 0x1000)
    {
        Op::jp_addr(op_code);
    }
    else if ((0xF000 & op_code) == 0x2000)
    {
        Op::call_addr(op_code);
    }
    else if ((0xF000 & op_code) == 0x3000)
    {
        Op::se_vx_byte(op_code);
    }
    else if ((0xF000 & op_code) == 0x4000)
    {
        Op::sne_vx_byte(op_code);
    }
    else if ((0xF00F & op_code) == 0x5000)
    {
        Op::se_vx_vy(op_code);
    }
    else if ((0xF000 & op_code) == 0x6000)
    {
        Op::ld_vx_byte(op_code);
    }
    else if ((0xF000 & op_code) == 0x7000)
    {
        Op::add_vx_byte(op_code);
    }
    else if ((0xF00F & op_code) == 0x8000)
    {
        Op::ld_vx_vy(op_code);
    }
    else if ((0xF00F & op_code) == 0x8001)
    {
        Op::or_vx_vy(op_code);
    }
    else if ((0xF00F & op_code) == 0x8002)
    {
        Op::and_vx_vy(op_code);
    }
    else if ((0xF00F & op_code) == 0x8003)
    {
        Op::xor_vx_vy(op_code);
    }
    else if ((0xF00F & op_code) == 0x8004)
    {
        Op::add_vx_vy(op_code);
    }
    else if ((0xF00F & op_code) == 0x8005)
    {
        Op::sub_vx_vy(op_code);
    }
    else if ((0xF00F & op_code) == 0x8006)
    {
        Op::shr_vx_vy(op_code);
    }
    else if ((0xF00F & op_code) == 0x8007)
    {
        Op::subn_vx_vy(op_code);
    }
    else if ((0xF00F & op_code) == 0x800E)
    {
        Op::shl_vx_vy(op_code);
    }
    else if ((0xF00F & op_code) == 0x9000)
    {
        Op::sne_vx_vy(op_code);
    }
    else if ((0xF000 & op_code) == 0xA000)
    {
        Op::ld_i_addr(op_code);
    }
    else if ((0xF000 & op_code) == 0xB000)
    {
        Op::jp_v0_addr(op_code);
    }
    else if ((0xF000 & op_code) == 0xC000)
    {
        Op::rnd_vx_byte(op_code);
    }
    else if ((0xF000 & op_code) == 0xD000)
    {
        Op::drw_vx_vy_nibble(op_code);
    }
    else if ((0xF0FF & op_code) == 0xE09E)
    {
        Op::skp_vx(op_code);
    }
    else if ((0xF0FF & op_code) == 0xE0A1)
    {
        Op::sknp_vx(op_code);
    }
    else if ((0xF0FF & op_code) == 0xF007)
    {
        Op::ld_vx_dt(op_code);
    }
    else if ((0xF0FF & op_code) == 0xF00A)
    {
        Op::ld_vx_k(op_code);
    }
    else if ((0xF0FF & op_code) == 0xF015)
    {
        Op::ld_dt_vx(op_code);
    }
    else if ((0xF0FF & op_code) == 0xF018)
    {
        Op::ld_st_vx(op_code);
    }
    else if ((0xF0FF & op_code) == 0xF01E)
    {
        Op::add_i_vx(op_code);
    }
    else if ((0xF0FF & op_code) == 0xF029)
    {
        Op::ld_f_vx(op_code);
    }
    else if ((0xF0FF & op_code) == 0xF033)
    {
        Op::ld_b_vx(op_code);
    }
    else if ((0xF0FF & op_code) == 0xF055)
    {
        Op::ld_i_vx_store(op_code);
    }
    else if ((0xF0FF & op_code) == 0xF065)
    {
        Op::ld_i_vx_read(op_code);
    }
    else
    {
        printf("Unknown Op_code = %0X\n", op_code);
    }
}
