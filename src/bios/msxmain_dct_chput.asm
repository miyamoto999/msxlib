
    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxmain_dct_chput
    PUBLIC _msxmain_dct_chput
    PUBLIC ___msxmain_dct_chput

; /* 文字を1文字出力する */
; void msxmain_dct_chput(char ch);

msxmain_dct_chput:
_msxmain_dct_chput:
___msxmain_dct_chput:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; chを取り出す
    ld a,(hl)

    push ix
    ; 1文字出力する
    call MSXMAIN_CHPUT
    pop ix
    
    ret