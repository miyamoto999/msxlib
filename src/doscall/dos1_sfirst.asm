    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_sfirst
    PUBLIC _dos1_sfirst
    PUBLIC ___dos1_sfirst
    EXTERN msxlib_doscall

; /* 最初のエントリの検索(FCB) */
; uint8_t __LIB__ dos1_sfirst(void *fcb) __smallc;

dos1_sfirst:
_dos1_sfirst:
___dos1_sfirst:
    ; fcbを取り出す
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_SFIRST
    jp msxlib_doscall