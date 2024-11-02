
    include "msxlib/asm/msxbios.inc"
    include "msxlib/asm/msxwork.inc"

    SECTION code_user
    PUBLIC msx_dos_inpkey
    PUBLIC _msx_dos_inpkey
    PUBLIC ___msx_dos_inpkey

;   /* キーボードバッファから1文字入力する。 */
; int16_t msx_dos_inpkey();

msx_dos_inpkey:
_msx_dos_inpkey:
___msx_dos_inpkey:
    push ix
    ;;; キーボードバッファが空かどうか調べる
    ; メインスロットを取り出す。
    ld iy,(MSXWORK_EXPTBL - 1)
    ; キーボードバッファが空かどうか調べるBIOSを呼ぶ
    ld ix, MSXMAIN_CHSNS
    call MSXMAIN_CALSLT
    ei
    jr z,L_END

    ; メインスロットを取り出す。
    ld iy,(MSXWORK_EXPTBL - 1)
    ; キーボードバッファから1文字取り出すBIOSを呼ぶ。
    ld ix,MSXMAIN_CHGET
    call MSXMAIN_CALSLT
    ei

    ld h,0
    ld l,a
    pop ix
    ret

L_END:
    ld hl,0xffff
    pop ix
    ret
