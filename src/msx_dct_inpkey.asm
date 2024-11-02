
    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msx_dct_inpkey
    PUBLIC _msx_dct_inpkey
    PUBLIC ___msx_dct_inpkey

;   /* キーボードバッファから1文字入力する。 */
; int16_t msx_dct_inpkey();

msx_dct_inpkey:
_msx_dct_inpkey:
___msx_dct_inpkey:
    ;;; キーボードバッファが空かどうか調べる
    ; キーボードバッファが空かどうか調べるBIOSを呼ぶ
    call MSXMAIN_CHSNS
    jr z,L_END

    ; キーボードバッファから1文字取り出すBIOSを呼ぶ。
    call MSXMAIN_CHGET

    ld h,0
    ld l,a
    ret

L_END:
    ld hl,0xffff
    ret
