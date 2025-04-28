    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_innoe
    PUBLIC _dos1_innoe
    PUBLIC ___dos1_innoe
    EXTERN msxlib_doscall

; /* エコーなしコンソール入力 */
; uint8_t __LIB__ dos1_innoe(void) __smallc;
dos1_innoe:
_dos1_innoe:
___dos1_innoe:
    ld c,_INNOE
    jp msxlib_doscall
