    include "msxlib/asm/msxbios.inc"
    include "msxlib/asm/msxwork.inc"

    SECTION code_user
    PUBLIC msxmain_dct_chgclr
    PUBLIC _msxmain_dct_chgclr
    PUBLIC ___msxmain_dct_chgclr

; void msxmain_dct_chgclr(uint8_t fg, uint8_t bg, uint8_t bd);

msxmain_dct_chgclr:
_msxmain_dct_chgclr:
___msxmain_dct_chgclr:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; bdを取り出す
    ld a,(hl)
    ld (MSXWORK_BDRCLR),a
    inc hl
    inc hl
    ; bgを取り出す
    ld a,(hl)
    ld (MSXWORK_BAKCLR),a
    inc hl
    inc hl
    ; fgを取り出す
    ld a,(hl)
    ld (MSXWORK_FORCLR),a

    push ix
    ; COLORを変更
    call MSXMAIN_CHGCLR
    pop ix

    ret