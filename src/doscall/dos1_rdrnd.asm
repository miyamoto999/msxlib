    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_rdrnd
    PUBLIC _dos1_rdrnd
    PUBLIC ___dos1_rdrnd

; /* ランダム読み出し(FCB) */
; uint8_t dos1_rdrnd(void *fcb) __smallc;
dos1_rdrnd:
_dos1_rdrnd:
___dos1_rdrnd:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_RDRND
    jp BDOS