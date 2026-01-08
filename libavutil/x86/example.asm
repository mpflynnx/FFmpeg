%define private_prefix ff ; hack
%include "libavutil/x86/x86inc.asm"

SECTION .text

; Function: void ff_add_bytes_sse2(uint8_t *dst, uint8_t *src, int len)
; cglobal params: function_name, num_args, num_regs_used, num_xmm_regs, arg_names...
INIT_XMM sse2
cglobal add_bytes, 3, 3, 2, dst, src, len
    .loop:
        movu      m0, [srcq]      ; Load 16 bytes from src (unaligned)
        movu      m1, [dstq]      ; Load 16 bytes from dst
        paddb     m0, m1          ; Parallel add 16 bytes
        movu      [dstq], m0      ; Store result back to dst
        
        add       srcq, 16        ; Increment pointers by 16
        add       dstq, 16
        sub       lend, 16        ; Decrement length
        jg        .loop           ; Jump if len > 0
    RET