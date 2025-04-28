    include "msxlib/asm/msxbios.inc"
    include "msxlib/asm/msxwork.inc"

    SECTION code_user
    PUBLIC msxmain_dos_chget
    PUBLIC _msxmain_dos_chget
    PUBLIC ___msxmain_dos_chget

; /* 文字を1文字入力する */
; char __LIB__ msxmain_dos_chget(void) __smallc;

msxmain_dos_chget:
_msxmain_dos_chget:
___msxmain_dos_chget:

    push ix
    ; 1文字出力する
    ld ix, MSXMAIN_CHGET
    ; メインスロットを取り出す。
    ld iy,(MSXWORK_EXPTBL - 1)
    call MSXMAIN_CALSLT
    ei
    pop ix

    ld l,a

    ret
