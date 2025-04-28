    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_fdel
    PUBLIC _dos1_fdel
    PUBLIC ___dos1_fdel
    EXTERN msxlib_doscall


; /* ファイルの削除(FCB) */
; uint8_t __LIB__ dos1_fdel(MSX_FCB *fcb) __smallc;
dos1_fdel:
_dos1_fdel:
___dos1_fdel:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_FDEL
    jp msxlib_doscall
