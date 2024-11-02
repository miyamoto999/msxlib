    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxsub_dct_chgmdp
    PUBLIC _msxsub_dct_chgmdp
    PUBLIC ___msxsub_dct_chgmdp


;;;; CHGMDP スクリーンモードを変更します。(パレットも初期化)
; void msxsub_dct_chgmdp(uint8_t mode);

msxsub_dct_chgmdp:
_msxsub_dct_chgmdp:
___msxsub_dct_chgmdp:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; modeを取り出す
    ld a,(hl)

    push ix
    ld ix,MSXSUB_CHGMDP

    call MSXMAIN_EXTROM
    pop ix
    ret