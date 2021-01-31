
// Holds information coming from imgui.
// - Status to indicate if we have run into an error
// - State of keypresses and other interaction from gui
typedef struct _imgui_state
{
	// Return status. 0 means OK, anything else means an error occured
	int status;
	// State of keys, whether pressed or not
	bool key_1;
	bool key_2;
	bool key_3;
	bool key_c;
	bool key_4;
	bool key_5;
	bool key_6;
	bool key_d;
	bool key_7;
	bool key_8;
	bool key_9;
	bool key_e;
	bool key_a;
	bool key_0;
	bool key_b;
	bool key_f;
} ImguiState;
