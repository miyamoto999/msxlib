    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_snext
    PUBLIC _dos1_snext
    PUBLIC ___dos1_snext
    EXTERN msxlib_doscall

; /* 次のエントリの検索(FCB) */
; uint8_t __LIB__ dos1_snext(void) __smallc;

dos1_snext:
_dos1_snext:
___dos1_snext:

    ld c,_SNEXT
    jp msxlib_doscall