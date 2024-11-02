    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxmain_dct_gtpad
    PUBLIC _msxmain_dct_gtpad
    PUBLIC ___msxmain_dct_gtpad


; 各種入出力機器の状態取得
;;;;; uint8_t msxmain_dct_gtpad(uint8_t id)

msxmain_dct_gtpad:
_msxmain_dct_gtpad:
___msxmain_dct_gtpad:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; idを取り出す
    ld a,(hl)

    push ix
    ; 各種入出力機器の状態取得
    call MSXMAIN_GTPAD
    pop ix

    ld l,a
    ret