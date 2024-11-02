    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_const
    PUBLIC _dos1_const
    PUBLIC ___dos1_const


; /* コンソールステータス */
; uint8_t dos1_const();
dos1_const:
_dos1_const:
___dos1_const:
    ld c,_CONST
    jp BDOS
