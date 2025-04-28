    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_dskrst
    PUBLIC _dos1_dskrst
    PUBLIC ___dos1_dskrst
    EXTERN msxlib_doscall

; /* ディスクリセット */
; void __LIB__ dos1_dskrst(void) __smallc;
dos1_dskrst:
_dos1_dskrst:
___dos1_dskrst:
    ld c,_DSKRST
    jp msxlib_doscall
