
// Op = Operation
class Op
{
    public:
        static void clear();
        static void ret();
        static void jp_addr(int op_code);
        static void call_addr(int op_code);
        static void se_vx_byte(int op_code);
        static void sne_vx_byte(int op_code);
        static void se_vx_vy(int op_code);
        static void ld_vx_byte(int op_code);
        static void add_vx_byte(int op_code);
        static void ld_vx_vy(int op_code);
        static void or_vx_vy(int op_code);
        static void and_vx_vy(int op_code);
        static void xor_vx_vy(int op_code);
        static void add_vx_vy(int op_code);
        static void sub_vx_vy(int op_code);
        static void shr_vx_vy(int op_code);
        static void subn_vx_vy(int op_code);
        static void shl_vx_vy(int op_code);
        static void sne_vx_vy(int op_code);
        static void ld_i_addr(int op_code);
        static void jp_v0_addr(int op_code);
        static void rnd_vx_byte(int op_code);
        static void drw_vx_vy_nibble(int op_code);
        static void skp_vx(int op_code);
        static void sknp_vx(int op_code);
        static void ld_vx_dt(int op_code);
        static void ld_vx_k(int op_code);
        static void ld_dt_vx(int op_code);
        static void ld_st_vx(int op_code);
        static void add_i_vx(int op_code);
        static void ld_f_vx(int op_code);
        static void ld_b_vx(int op_code);
        static void ld_i_vx_store(int op_code);
        static void ld_i_vx_read(int op_code);
};
