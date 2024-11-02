    include "msxlib/asm/msxbios.inc"
    include "msxlib/asm/msxwork.inc"

    SECTION code_user
    PUBLIC msxmain_dos_chgclr
    PUBLIC _msxmain_dos_chgclr
    PUBLIC ___msxmain_dos_chgclr

; void msxmain_dos_chgclr(uint8_t fg, uint8_t bg, uint8_t bd);

msxmain_dos_chgclr:
_msxmain_dos_chgclr:
___msxmain_dos_chgclr:
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
    ; COLORモードを変更
    ld ix, MSXMAIN_CHGCLR
    ; メインスロットの情報を取り出す。
    ld iy,(MSXWORK_EXPTBL-1)
    call MSXMAIN_CALSLT
    ei
    pop ix
    
    ret
