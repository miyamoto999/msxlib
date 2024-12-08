    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_bufin
    PUBLIC _dos1_bufin
    PUBLIC ___dos1_bufin

; /* バッファ行入力 */
; void __LIB__ dos1_bufin(char *buf) __smallc;
dos1_bufin:
_dos1_bufin:
___dos1_bufin:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)
    
    ld c,_BUFIN
    jp BDOS
