    include "msxlib/asm/msxbios.inc"
    include "msxlib/asm/msxwork.inc"

    SECTION code_user
    PUBLIC msxmain_dos_chgmod
    PUBLIC _msxmain_dos_chgmod
    PUBLIC ___msxmain_dos_chgmod

;;;;; void msxmain_dos_chgmod(uint8_t mode);
msxmain_dos_chgmod:
_msxmain_dos_chgmod:
___msxmain_dos_chgmod:

    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; modeを取り出す
    ld a,(hl)

    push ix
    ; SCREENモードを変更
    ld ix, MSXMAIN_CHGMOD
    ; メインスロットを取り出す。
    ld iy,(MSXWORK_EXPTBL - 1)
    call MSXMAIN_CALSLT
    ei

    pop ix

    ret
