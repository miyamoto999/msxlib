    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_fmake
    PUBLIC _dos1_fmake
    PUBLIC ___dos1_fmake


; /* ファイルの作成 */
; int8_t dos1_fmake(void *fcb);
dos1_fmake:
_dos1_fmake:
___dos1_fmake:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)

    ld c,_FMAKE
    jp BDOS
