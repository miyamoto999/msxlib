    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos1_lstout
    PUBLIC _dos1_lstout
    PUBLIC ___dos1_lstout
    EXTERN msxlib_doscall

; /* プリンタ出力 */
; void __LIB__ dos1_lstout(char ch) __smallc;
dos1_lstout:
_dos1_lstout:
___dos1_lstout:
    ld hl,2
    add hl,sp

    ld e,(hl)
    
    ld c,_LSTOUT
    jp msxlib_doscall
