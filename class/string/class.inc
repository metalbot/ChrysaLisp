(import 'class/sequence/class.inc)

(def-class 'string 'sequence)
(dec-method 'vtable 'class/class_string)
(dec-method 'create_from_buffer 'class/string/create_from_buffer 'static '(r0 r1) '(r0))
(dec-method 'create_from_cstr 'class/string/create_from_cstr 'static '(r0) '(r0))
(dec-method 'create_from_file 'class/string/create_from_file 'static '(r0) '(r0))
(dec-method 'create_from_long 'class/string/create_from_long 'static '(r0 r1) '(r0))
(dec-method 'append 'class/string/append 'static '(r0 r1) '(r0))
(dec-method 'cat 'class/string/cat 'static '(r0) '(r0))
(dec-method 'new 'class/string/new 'static '(r0) '(r0))
(dec-method 'init 'class/string/init 'static '(r0 r1 r2 r3))
(dec-method 'init1 'class/string/init1 'static '(r0 r1 r2 r3) '(r0 r1))
(dec-method 'init2 'class/string/init2 'static '(r0 r1 r2 r3) '(r0 r1))
(dec-method 'init3 'class/string/init3 'static '(r0 r1 r2) '(r0 r1))
(dec-method 'split 'class/string/split 'static '(r0 r1) '(r0 r1))
(dec-method 'compare 'class/string/compare 'static '(r0 r1) '(r0 r1))
(dec-method 'same 'class/string/same 'static '(r0 r1) '(r0 r1))
(dec-method 'find 'class/string/find 'static '(r0 r1) '(r0 r1))

(dec-method 'hash 'class/string/hash 'final)
(dec-method 'get_length 'class/string/get_length 'final)
(dec-method 'ref_element 'class/string/ref_element 'final)
(dec-method 'slice 'class/string/slice 'final)

(def-struct 'string 'sequence)
	(uint 'length)
	(uint 'hashcode)
	(local-align)
	(offset 'data)
(def-struct-end)

(defcvar 'string_gap (sub 64 string_data ptr_size byte_size))

(defcvar 'char_backspace 8)
(defcvar 'char_tab 9)
(defcvar 'char_lf 10)
(defcvar 'char_cr 13)
(defcvar 'char_esc 27)
(defcvar 'char_space (ascii " "))
(defcvar 'char_underscore (ascii "_"))
(defcvar 'char_pipe (ascii "|"))
(defcvar 'char_lrb (ascii "("))
(defcvar 'char_rrb (ascii ")"))
(defcvar 'char_lsb (ascii "["))
(defcvar 'char_rsb (ascii "]"))
(defcvar 'char_lcb (ascii "{"))
(defcvar 'char_rcb (ascii "}"))
(defcvar 'char_quote (ascii "'"))
(defcvar 'char_double_quote 34)
(defcvar 'char_tick (ascii "`"))
(defcvar 'char_comma (ascii ","))
(defcvar 'char_tilda (ascii "~"))
(defcvar 'char_semi (ascii ";"))
(defcvar 'char_dot (ascii "."))
(defcvar 'char_at (ascii "@"))
(defcvar 'char_lt (ascii "<"))
(defcvar 'char_gt (ascii ">"))
(defcvar 'char_equal (ascii "="))
(defcvar 'char_plus (ascii "+"))
(defcvar 'char_minus (ascii "-"))
(defcvar 'char_multiply (ascii "*"))
(defcvar 'char_divide (ascii "/"))
(defcvar 'char_0 (ascii "0"))
(defcvar 'char_9 (ascii "9"))
(defcvar 'char_a (ascii "a"))
(defcvar 'char_z (ascii "z"))
(defcvar 'char_A (ascii "A"))
(defcvar 'char_Z (ascii "Z"))
(defcvar 'char_x (ascii "x"))
(defcvar 'char_b (ascii "b"))
(defcvar 'char_o (ascii "o"))

;;;;;;;;;;;;;;;
;inline methods
;;;;;;;;;;;;;;;

(defcfun class/string/new ()
	;inputs
	;r0 = object size (bytes)
	;outputs
	;r0 = 0 if error, else object (ptr)
	;trashes
	;r1-r3
	(f-call 'sys_mem 'alloc '(r0) '(r0 _)))

(defcfun class/string/get_length ()
	;inputs
	;r0 = string object (ptr)
	;outputs
	;r0 = string object (ptr)
	;r1 = string length (bytes)
	(vp-cpy-ir-ui r0 string_length r1))