    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxsub_dct_knjprt
    PUBLIC _msxsub_dct_knjprt
    PUBLIC ___msxsub_dct_knjprt
 
;;;;; void msxsub_dct_knjprt(uint8_t mode, uint16_t code);
msxsub_dct_knjprt:
_msxsub_dct_knjprt:
___msxsub_dct_knjprt:
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
    call MSXMAIN_EXTROM
    pop ix

    ret