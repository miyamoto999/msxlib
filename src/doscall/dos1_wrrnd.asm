    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_wrrnd
    PUBLIC _dos1_wrrnd
    PUBLIC ___dos1_wrrnd

; /* ランダム書き込み(FCB) */
; uint8_t __LIB__ dos1_wrrnd(MSX_FCB *fcb) __smallc;
dos1_wrrnd:
_dos1_wrrnd:
___dos1_wrrnd:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_WRRND
    jp BDOS
