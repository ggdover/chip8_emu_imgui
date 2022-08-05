#include "op.h"
#include "globals.h"
#include "utils.h"
#include <assert.h> // assert
#include <cstring> // memset
#include <math.h> // Math.pow

// 00E0 - CLS
// Clear the display
void Op::clear()
{
    memset(Globals::DISPLAY_MATRIX, 0, (Globals::DISPLAY_W * Globals::DISPLAY_H));
}

// 00EE - RET
// Return from subroutines
void Op::ret()
{
    printf("UNIMPLEMENTED");
}

// 1nnn - JP addr
// Jump to location 'addr' (Sets Program counter to 'addr')
void Op::jp_addr(int op_code)
{
    Globals::PC = (0x0FFF & op_code) - Globals::START_ADDR;
}

// 2nnn = CALL addr
// Call subroutine at 'addr'
void Op::call_addr(int op_code)
{
    int n = (0x0FFF & op_code);
    int addr = n - Globals::START_ADDR;

    assert(Globals::STACK.size() < Globals::STACK_SIZE);
    assert(Globals::SP < Globals::STACK_SIZE);
    Globals::STACK.push(addr);
    ++Globals::SP;
}

// 3xkk - SE Vx, byte
// Skip next instruction if 'vx' == 'kk'
// (se = Skip if Equal)
// vx = A register
// kk = A byte (value that can be set on a register)
void Op::se_vx_byte(int op_code)
{
    int kk = (0x00FF & op_code);
    int vx = ((0x0F00 & op_code) >> 8);
    assert(vx <= 15 && vx >= 0);
    if (kk == Globals::V[vx])
    {
        printf("Skipping");
        Globals::PC += 4;
    }
}

// 4xkk - SNE Vx, byte
// Skip next instruction if 'vx' != 'kk'
// (sne = Skip if Not Equal)
// vx = A register
// kk = A byte (value that can be set on a register)
void Op::sne_vx_byte(int op_code)
{
    char kk = (0x00FF & op_code);
    char vx = ((0x0F00 & op_code) >> 8);
    assert(vx <= 15 && vx >= 0);
    if (kk != Globals::V[vx])
    {
        printf("Skipping");
        Globals::PC += 4;
    }
}

// 5xy0 - SE Vx, Vy
// Skip next instruction if vx == vy
// vx, vy = two regiisters
void Op::se_vx_vy(int op_code)
{
    char vx = ((0x0F00 & op_code) >> 8);
    char vy = ((0x00F0 & op_code) >> 4);
    assert(vx <= 15 && vx >= 0);
    assert(vy <= 15 && vy >= 0);
    if (Globals::V[vx] == Globals::V[vy])
    {
        printf("Skipping");
        Globals::PC += 4;
    }
}

// 6xkk - LD Vx, byte
// Set Vx = kk.
void Op::ld_vx_byte(int op_code)
{
    char vx = ((0x0F00 & op_code) >> 8);
    assert(vx <= 15 && vx >= 0);

    char kk = (0x00FF & op_code);

    printf("Vx = %d kk = %d", Globals::V[vx], kk);
    Globals::V[vx] = kk;
    printf("AFTER Vx = %d", Globals::V[vx]);
}

// 7xkk - ADD Vx, byte
// Adds the value kk to the value of register Vx, then stores the result in Vx. 
void Op::add_vx_byte(int op_code)
{
    char vx = ((0x0F00 & op_code) >> 8);
    assert(vx <= 15 && vx >= 0);

    char kk = (0x00FF & op_code);

    printf("Vx = %d kk = %d", Globals::V[vx], kk);
    Globals::V[vx] += kk;
    printf("SUM Vx = %d", Globals::V[vx]);
}

void Op::ld_vx_vy(int op_code)
{
    char vx = ((0x0F00 & op_code) >> 8);
    assert(vx <= 15 && vx >= 0);

    char vy = ((0x00F0 & op_code) >> 4);
    assert(vy <= 15 && vy >= 0);

    Globals::V[vx] = Globals::V[vy];
}

void Op::or_vx_vy(int op_code)
{
    char vx = ((0x0F00 & op_code) >> 8);
    assert(vx <= 15 && vx >= 0);

    char vy = ((0x00F0 & op_code) >> 4);
    assert(vy <= 15 && vy >= 0);

    Globals::V[vx] |= Globals::V[vy];
}

void Op::and_vx_vy(int op_code)
{
    char vx = ((0x0F00 & op_code) >> 8);
    assert(vx <= 15 && vx >= 0);

    char vy = ((0x00F0 & op_code) >> 4);
    assert(vy <= 15 && vy >= 0);

    Globals::V[vx] &= Globals::V[vy];
}

void Op::xor_vx_vy(int op_code)
{
    char vx = ((0x0F00 & op_code) >> 8);
    assert(vx <= 15 && vx >= 0);

    char vy = ((0x00F0 & op_code) >> 4);
    assert(vy <= 15 && vy >= 0);

    Globals::V[vx] ^= Globals::V[vy];
}

void Op::add_vx_vy(int op_code)
{
    char vx = ((0x0F00 & op_code) >> 8);
    assert(vx <= 15 && vx >= 0);

    char vy = ((0x00F0 & op_code) >> 4);
    assert(vy <= 15 && vy >= 0);

    Globals::V[vx] += Globals::V[vy];
}

void Op::sub_vx_vy(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::shr_vx_vy(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::subn_vx_vy(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::shl_vx_vy(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::sne_vx_vy(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::ld_i_addr(int op_code)
{
    Globals::I = 0x0FFF & op_code;
}

void Op::jp_v0_addr(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::rnd_vx_byte(int op_code)
{
    char vx = ((0x0F00 & op_code) >> 8);
    assert(vx <= 15 && vx >= 0);

    char r = rand() % 256;
    char kk = 0x00FF & op_code;

    Globals::V[vx] = r & kk;
}

void Op::drw_vx_vy_nibble(int op_code)
{
    char vx = ((0x0F00 & op_code) >> 8);
    assert(vx <= 15 && vx >= 0);

    char vy = ((0x00F0 & op_code) >> 4);
    assert(vy <= 15 && vy >= 0);

    char nibble_count = 0x000F & op_code;
    int addr = Globals::I - Globals::START_ADDR;
    printf("drw: addr = %u", addr);
    printf("drw: vx = %u vy = %u V[vx] = %u V[vy] = %u", vx, vy, Globals::V[vx], Globals::V[vy]);
    Globals::V[0xF] = 0;

    unsigned int coordX = Globals::V[vx];
    unsigned int coordY = Globals::V[vy];

    // For each nibble
    for (char i = 0; i < nibble_count; ++i)
    {
        printf("&MEMORY = %p MEMORY.size()= %lu", (void*)&Globals::MEMORY, Globals::MEMORY.size());
        printf("MEMORY.size() = %u addr = %u(%X)", Globals::MEMORY.size(), addr, addr);
        unsigned int sprite_byte = Globals::MEMORY[addr];
        printf("sprite_byte = %u(%X)", sprite_byte);

        // For each bit (in nibble)
        for (char b = 0; b < 8; ++b)
        {
            // Get new pixel value (1 = filled, 0 = unfilled)
            unsigned char bit_mask = pow(2, b);
            printf("  bit_mask = %u", bit_mask);
            unsigned char new_pixel = sprite_byte & bit_mask;
            printf("  new_pixel = %u", new_pixel);

            //unsigned int coord = (Globals::DISPLAY_W * Globals::V[vy]) + Globals::V[vx];
            unsigned int coord = (Globals::DISPLAY_W * coordY) + coordX;
            printf("  coordX = %u coordY = %u", coordX, coordY);
            printf("  coord = %u", coord);
            assert(coord >= 0 && coord <= (Globals::DISPLAY_W * Globals::DISPLAY_H) - 1);

            // If the pixel on "coord" will be erased as
            // a result of the upcoming XOR, toggle the flag
            // VF (Globals::V[0xF]) to 1.
            Globals::V[0x0F] |= (Globals::DISPLAY_MATRIX[coord] == new_pixel);

            // Painting the pixel is done by XOR'ing
            Globals::DISPLAY_MATRIX[coord] ^= new_pixel;

            // Next pixel is one step to the right.
            ++coordX;
            // Wrap-around if we reach end of row.
            /*if (coordX > Globals::DISPLAY_W)
            {
                ++coordY;
                coordX = 0;
            }*/
        }

        ++coordY;
        coordX = Globals::V[vx] + (8 * (coordY / Globals::DISPLAY_H));

        ++addr;
    }
}

void Op::skp_vx(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::sknp_vx(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::ld_vx_dt(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::ld_vx_k(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::ld_dt_vx(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::ld_st_vx(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::add_i_vx(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::ld_f_vx(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::ld_b_vx(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::ld_i_vx_store(int op_code)
{
    printf("UNIMPLEMENTED");
}

void Op::ld_i_vx_read(int op_code)
{
    printf("UNIMPLEMENTED");
}
