    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxsub_dos_chgmdp
    PUBLIC _msxsub_dos_chgmdp
    PUBLIC ___msxsub_dos_chgmdp
    GLOBAL dos_extrom


;;;; CHGMDP スクリーンモードを変更します。(パレットも初期化)
; void msxsub_dos_chgmdp(uint8_t mode);

msxsub_dos_chgmdp:
_msxsub_dos_chgmdp:
___msxsub_dos_chgmdp:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; modeを取り出す
    ld a,(hl)

    push ix
    ld ix,MSXSUB_CHGMDP

    call dos_extrom
    pop ix

    ret