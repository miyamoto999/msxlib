    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_fren
    PUBLIC _dos1_fren
    PUBLIC ___dos1_fren
    EXTERN msxlib_doscall


; /* ファイル名の変更(FCB) */
; uint8_t __LIB__ dos1_fren(void *fcb) __smallc;
dos1_fren:
_dos1_fren:
___dos1_fren:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_FREN
    jp msxlib_doscall
