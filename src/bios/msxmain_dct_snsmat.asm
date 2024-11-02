    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxmain_dct_snsmat
    PUBLIC _msxmain_dct_snsmat
    PUBLIC ___msxmain_dct_snsmat

;;;;; uint8_t msxmain_dct_snsmat(uint8_t m)

msxmain_dct_snsmat:
_msxmain_dct_snsmat:
___msxmain_dct_snsmat:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; mを取り出す
    ld a,(hl)

    ; キーボードマトリックス取り出しを呼び出す
    call MSXMAIN_SNSMAT

    ld l,a
    ret
