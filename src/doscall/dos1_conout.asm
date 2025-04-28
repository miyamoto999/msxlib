    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_conout
    PUBLIC _dos1_conout
    PUBLIC ___dos1_conout
    EXTERN msxlib_doscall


; /* コンソールに1文字出力する */
; void dos1_conout(char ch);
dos1_conout:
_dos1_conout:
___dos1_conout:
    ld hl,2
    add hl,sp

    ld e,(hl)
    
    ld c,_CONOUT
    jp msxlib_doscall
