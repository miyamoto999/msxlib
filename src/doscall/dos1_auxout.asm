    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_auxout
    PUBLIC _dos1_auxout
    PUBLIC ___dos1_auxout

; /* 補助出力 */
; void __LIB__ dos1_auxout(char ch) __smallc;
dos1_auxout:
_dos1_auxout:
___dos1_auxout:
    ld hl,2
    add hl,sp

    ld e,(hl)
    
    ld c,_AUXOUT
    jp BDOS
