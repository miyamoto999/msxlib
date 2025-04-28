    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_dirio
    PUBLIC _dos1_dirio
    PUBLIC ___dos1_dirio
    EXTERN msxlib_doscall


; /* 直接コンソールI/O */
; char dos1_dirio(char code);
dos1_dirio:
_dos1_dirio:
___dos1_dirio:
    ld hl,2
    add hl,sp

    ld e,(hl)

    ld c,_DIRIO
    jp msxlib_doscall
