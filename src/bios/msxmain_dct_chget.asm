    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxmain_dct_chget
    PUBLIC _msxmain_dct_chget
    PUBLIC ___msxmain_dct_chget

; /* 文字を1文字入力する */
; char __LIB__ msxmain_dct_chget(void) __smallc;

msxmain_dct_chget:
_msxmain_dct_chget:
___msxmain_dct_chget:

    push ix
    ; 1文字入力する
    call MSXMAIN_CHGET
    pop ix

    ld l,a

    ret
