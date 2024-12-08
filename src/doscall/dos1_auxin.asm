    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_auxin
    PUBLIC _dos1_auxin
    PUBLIC ___dos1_auxin

; /* 補助入力 */
; uint8_t __LIB__ dos1_auxin(void) __smallc;
dos1_auxin:
_dos1_auxin:
___dos1_auxin:
    ld c,_AUXIN
    jp BDOS
