    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxsub_dos_knjprt
    PUBLIC _msxsub_dos_knjprt
    PUBLIC ___msxsub_dos_knjprt
    GLOBAL dos_extrom

;;;;; void msxsub_dos_knjprt(uint8_t mode, uint16_t code);
msxsub_dos_knjprt:
_msxsub_dos_knjprt:
___msxsub_dos_knjprt:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; codeを取り出す。
    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl
    ; modeを取り出す
    ld a,(hl)
    
    push ix
    ld ix,MSXSUB_KNJPRT
    call dos_extrom
    pop ix

    ret
