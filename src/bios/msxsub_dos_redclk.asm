    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxsub_dos_redclk
    PUBLIC _msxsub_dos_redclk
    PUBLIC ___msxsub_dos_redclk
    GLOBAL dos_extrom

; uint8_t msxsub_dos_redclk(uint8_t addr);
msxsub_dos_redclk:
_msxsub_dos_redclk:
___msxsub_dos_redclk:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; modeを取り出す
    ld c,(hl)

    push ix
    ld ix,MSXSUB_REDCLK
    call dos_extrom
    ld l,a
    pop ix
    
    ret
    