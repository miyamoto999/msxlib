    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_fsize
    PUBLIC _dos1_fsize
    PUBLIC ___dos1_fsize
    EXTERN msxlib_doscall

; /* ファイルサイズの取得(FCB) */
; uint8_t __LIB__ dos1_fsize(MSX_FCB *fcb) __smallc;
dos1_fsize:
_dos1_fsize:
___dos1_fsize:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_FSIZE
    jp msxlib_doscall
