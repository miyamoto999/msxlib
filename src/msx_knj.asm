    include "msxlib/asm/msxwork.inc"

;   漢字モードの設定や取得を行う関数を提供します。
;
;   こちらのページを参考にしました。
;   https://www.msxcomputermagazine.nl/mccw/91/KANJI-stuff/en.html
;

    SECTION code_user
    PUBLIC msx_chk_knjdrv, _msx_chk_knjdrv, ___msx_chk_knjdrv
    PUBLIC msx_set_knjmode, _msx_set_knjmode, ___msx_set_knjmode
    PUBLIC msx_get_knjmode, _msx_get_knjmode, ___msx_get_knjmode

; /* 漢字ドライバーのチェック */
; BOOL __LIB__ msx_chk_knjdrv(void) __smallc;
msx_chk_knjdrv:
_msx_chk_knjdrv:
___msx_chk_knjdrv:
    call msx_get_knjmode
    inc l

    ret z
    ld l,1

    ret

; /* 漢字モードの設定　*/
; void __LIB__ msx_set_knjmode(uint8_t mode) __smallc;
;    mode: 0:ank
;          1:kanji0
;          2:kanji1
;          3:kanji2
;          4:kanji3
msx_set_knjmode:
_msx_set_knjmode:
___msx_set_knjmode:
    ld hl,2
    add hl,sp

    push ix
    ld a,(hl)
    ld de,0x1101
    call MSXWORK_EXTBIO

    pop ix

    ret

; /* 現在の漢字モードの取得 */
; int8_t __LIB__ msx_get_knjmode(void) __smallc;
;    戻り値: 0:ank
;          1:kanji0
;          2:kanji1
;          3:kanji2
;          4:kanji3
;       -1:エラー(漢字ドライバーが無い)
msx_get_knjmode:
_msx_get_knjmode:
___msx_get_knjmode:
    push ix
    
    ld a,0xff
    ld de,0x1100
    call MSXWORK_EXTBIO
    ld l,a
    
    pop ix

    ret
