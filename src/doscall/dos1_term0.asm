    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_term0
    PUBLIC _dos1_term0
    PUBLIC ___dos1_term0


; /* プログラムの終了 */
; void __LIB__ dos1_term0(void) __smallc;
dos1_term0:
_dos1_term0:
___dos1_term0:
    ld c,_TERM0
    jp BDOS
