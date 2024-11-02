
    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxmain_dct_grpprt
    PUBLIC _msxmain_dct_grpprt
    PUBLIC ___msxmain_dct_grpprt

; void msxmain_dct_grpprt(char ch);

msxmain_dct_grpprt:
_msxmain_dct_grpprt:
___msxmain_dct_grpprt:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; chを取り出す
    ld a,(hl)

    ; 文字を描画
    jp MSXMAIN_GRPPRT
