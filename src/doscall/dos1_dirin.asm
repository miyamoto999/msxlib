    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_dirin
    PUBLIC _dos1_dirin
    PUBLIC ___dos1_dirin

; /* 直接コンソール入力 */
; uint8_t __LIB__ dos1_dirin(void) __smallc;
dos1_dirin:
_dos1_dirin:
___dos1_dirin:
    ld c,_DIRIN
    jp BDOS
