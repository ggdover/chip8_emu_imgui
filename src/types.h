
// Holds information coming from imgui.
// - Status to indicate if we have run into an error
// - State of keypresses and other interaction from gui
typedef struct _imgui_state
{
	// Return status. 0 means OK, anything else means an error occured
	int status = 0;
	// State of keys, whether pressed or not
	bool key_1 = false;
	bool key_2 = false;
	bool key_3 = false;
	bool key_c = false;
	bool key_4 = false;
	bool key_5 = false;
	bool key_6 = false;
	bool key_d = false;
	bool key_7 = false;
	bool key_8 = false;
	bool key_9 = false;
	bool key_e = false;
	bool key_a = false;
	bool key_0 = false;
	bool key_b = false;
	bool key_f = false;
} ImguiState;
