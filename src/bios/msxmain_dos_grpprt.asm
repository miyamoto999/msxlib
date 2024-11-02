
    include "msxlib/asm/msxbios.inc"
    include "msxlib/asm/msxwork.inc"

    SECTION code_user
    PUBLIC msxmain_dos_grpprt
    PUBLIC _msxmain_dos_grpprt
    PUBLIC ___msxmain_dos_grpprt

; void msxmain_dos_grpprt(char ch);

msxmain_dos_grpprt:
_msxmain_dos_grpprt:
___msxmain_dos_grpprt:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; chを取り出す
    ld a,(hl)

    push ix
    ; COLORモードを変更
    ld ix, MSXMAIN_GRPPRT
    ; メインスロットの情報を取り出す。
    ld iy,(MSXWORK_EXPTBL-1)
    call MSXMAIN_CALSLT
    ei
    pop ix

    ret
