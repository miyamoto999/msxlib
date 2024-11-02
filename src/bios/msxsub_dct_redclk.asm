    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxsub_dct_redclk
    PUBLIC _msxsub_dct_redclk
    PUBLIC ___msxsub_dct_redclk

; uint8_t msxsub_dct_redclk(uint8_t addr);
msxsub_dct_redclk:
_msxsub_dct_redclk:
___msxsub_dct_redclk:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; modeを取り出す
    ld c,(hl)

    push ix
    ld ix,MSXSUB_REDCLK
    call MSXMAIN_EXTROM
    ld l,a
    pop ix

    ret
    