    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxmain_dct_chgmod
    PUBLIC _msxmain_dct_chgmod
    PUBLIC ___msxmain_dct_chgmod

;;;;; void msxmain_dct_chgmod(uint8_t mode);

msxmain_dct_chgmod:
_msxmain_dct_chgmod:
___msxmain_dct_chgmod:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp

    ; modeを取り出す
    ld a,(hl)

    push ix
    ; SCREENモードを変更
    call MSXMAIN_CHGMOD
    pop ix

    ret
