
    include "msxlib/asm/msxbios.inc"
    include "msxlib/asm/msxwork.inc"

    SECTION code_user
    PUBLIC msxmain_dos_snsmat
    PUBLIC _msxmain_dos_snsmat
    PUBLIC ___msxmain_dos_snsmat

;;;; uint8_t msxmain_dos_snsmat(uint8_t m)
msxmain_dos_snsmat:
_msxmain_dos_snsmat:
___msxmain_dos_snsmat:

    ; リターンアドレスを無視
    ld hl,2
    add hl,sp

    push ix
    ; mを取り出す
    ld a,(hl)

    ; キーボードマトリックス取り出しを呼び出す
    ld ix, MSXMAIN_SNSMAT
    ; メインスロットを取り出す。
    ld iy,(MSXWORK_EXPTBL-1)
    call MSXMAIN_CALSLT
    ei

    pop ix

    ld l,a

    ret