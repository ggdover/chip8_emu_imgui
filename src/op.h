
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
        static void load_vx_byte(int op_code);
};
