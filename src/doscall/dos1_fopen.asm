    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_fopen
    PUBLIC _dos1_fopen
    PUBLIC ___dos1_fopen


; /* ファイルオープン */
; int8_t dos1_fmake(void *fcb);
dos1_fopen:
_dos1_fopen:
___dos1_fopen:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_FOPEN
    jp BDOS
