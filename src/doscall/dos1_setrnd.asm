    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_setrnd
    PUBLIC _dos1_setrnd
    PUBLIC ___dos1_setrnd


; /* ランダムレコードの設定[FCB] */
; void __LIB__ dos1_setrnd(MSX_FCB *fcb) __smallc;
dos1_setrnd:
_dos1_setrnd:
___dos1_setrnd:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_SETRND
    jp BDOS
