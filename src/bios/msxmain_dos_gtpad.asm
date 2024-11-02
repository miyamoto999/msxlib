
    include "msxlib/asm/msxbios.inc"
    include "msxlib/asm/msxwork.inc"

    SECTION code_user
    PUBLIC msxmain_dos_gtpad
    PUBLIC _msxmain_dos_gtpad
    PUBLIC ___msxmain_dos_gtpad

;   /* 各種入出力機器の状態取得 */
;;;;uint8_t msxmain_dos_gtpad(uint8_t id);

msxmain_dos_gtpad:
_msxmain_dos_gtpad:
___msxmain_dos_gtpad:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; idを取り出す
    ld a,(hl)

    push ix
    ; 各種入出力機器の状態取得
    ld ix, MSXMAIN_GTPAD
    ; メインスロットを取り出す。
    ld iy,(MSXWORK_EXPTBL - 1)
    call MSXMAIN_CALSLT
    ei
    pop ix

    ld l,a

    ret