    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos2_defab
    PUBLIC _dos2_defab
    PUBLIC ___dos2_defab


; /* アボート終了ルーチンの定義 */
; void dos2_defab(BOOL (*abort_routine)(uint8_t err1, uint8_t err2));
dos2_defab:
_dos2_defab:
___dos2_defab:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ld a,d
    or e

    jp z,cancel

    ld (C_ABORT_ROUTINE+1),de

    ld de,abort_routine
cancel:
    ld c,_DEFAB
    jp BDOS
;;

abort_routine:
    ld h,0
    ld l,a
    push hl
    ld l,b
    push hl

    jp C_ABORT_ROUTINE
abort_routine_next:
    pop bc
    pop bc

    ld a,l
    or a
    ret z

    pop hl
    ret

    SECTION data_user

C_ABORT_ROUTINE:
    db 0xcd
    dw 0
    jp abort_routine_next