    include "msxlib/asm/msxbios.inc"
    include "msxlib/asm/msxwork.inc"

    SECTION code_user
    PUBLIC msxmain_dos_chput
    PUBLIC _msxmain_dos_chput
    PUBLIC ___msxmain_dos_chput

; /* 文字を1文字出力する */
; void msxmain_dos_chput(char ch);

msxmain_dos_chput:
_msxmain_dos_chput:
___msxmain_dos_chput:

    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; chを取り出す
    ld a,(hl)

    push ix
    ; 1文字出力する
    ld ix, MSXMAIN_CHPUT
    ; メインスロットを取り出す。
    ld iy,(MSXWORK_EXPTBL - 1)
    call MSXMAIN_CALSLT
    ei
    pop ix

    ret
