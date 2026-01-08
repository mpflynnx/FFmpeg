%define private_prefix ff ; hack
%include "libavutil/x86/x86inc.asm"

SECTION .text

;Function: static void add_values_sse2(uint8_t *src, const uint8_t *src2)
; cglobal params: function_name, num_args, num_regs_used, num_xmm_regs, arg_names...

INIT_XMM sse2  
cglobal add_values, 2, 2, 2, src, src2   
    movu  m0, [srcq]    ; Load 16 bytes from src (unaligned)
    movu  m1, [src2q]   ; Load 16 bytes from src2

    paddb m0, m1        ; Parallel add 16 bytes

    movu  [srcq], m0    ; Store result back to src

    RET