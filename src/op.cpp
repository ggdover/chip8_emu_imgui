#include "op.h"
#include "globals.h"
#include <assert.h> // assert
#include <cstdio> // printf
#include <cstring> // memset

// 00E0 - CLS
// Clear the display
void Op::clear()
{
    memset(DISPLAY_MATRIX, 0, (DISPLAY_W * DISPLAY_H));
}

// 00EE - RET
// Return from subroutine
void Op::ret()
{
    printf("UNIMPLEMENTED");
}

// 1nnn - JP addr
// Jump to location 'addr' (Sets Program counter to 'addr')
void Op::jp_addr(int op_code)
{
    PC = (0x0FFF & op_code);
}

// 2nnn = CALL addr
// Call subroutine at 'addr'
void Op::call_addr(int op_code)
{
    printf("UNIMPLEMENTED");
}

// 3xkk - SE Vx, byte
// Skip next instruction if 'vx' == 'kk'
// (se = Skip if Equal)
// vx = A register
// kk = A byte (value that can be set on a register)
void Op::se_vx_byte(int op_code)
{
    int kk = (0x00FF & op_code);
    int vx = (0x0F00 & op_code);
    if (kk == vx)
    {
        PC += 2;
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
    char vx = (0x0F00 & op_code);
    if (kk != vx)
    {
        PC += 2;
    }
}

// 5xy0 - SE Vx, Vy
// Skip next instruction if vx == vy
// vx, vy = two regiisters
void Op::se_vx_vy(int op_code)
{
    char vx = (0x0F00 & op_code);
    char vy = (0x00F0 & op_code);
    if (vx == vy)
    {
        PC += 2;
    }
}

// 6xkk - LD Vx, byte
// Set Vx = kk.
void Op::load_vx_byte(int op_code)
{
    char vx = (0x0F00 & op_code);
    assert(vx <= 16 && vx >= 0);

    char kk = (0x00FF & op_code);

    V[vx] = kk;
}
