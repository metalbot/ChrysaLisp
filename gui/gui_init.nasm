%include 'inc/func.inc'
%include 'inc/gui.inc'

def_func gui/gui_init
	;inputs
	;r0 = sdl function table

	;init sdl function table
	f_bind gui_gui, statics, r3
	vp_cpy r0, [r3 + gui_statics_sdl_funcs]

	;init old region
	vp_xor r0, r0
	vp_cpy r0, [r3 + gui_statics_old_region]

	;init region heap
	f_call sys_heap, init, {&[r3 + gui_statics_rect_heap], gui_rect_size, gui_rect_size * 32}

	;init signal heap
	f_jmp sys_heap, init, {&[r3 + gui_statics_sigslot_heap], gui_sigslot_size, gui_sigslot_size * 32}

def_func_end
