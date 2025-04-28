    include "msxlib/asm/msxdos.inc"


    SECTION code_user
    PUBLIC dos2_defer
    PUBLIC _dos2_defer
    PUBLIC ___dos2_defer
    EXTERN msxlib_doscall


; /* ディスクエラー処理ルーチンの定義 */
; void dos2_defer(uint8_t (*dsker_routine)(uint8_t err, uint8_t drv, uint8_t flag, uint16_t sec_no));
dos2_defer:
_dos2_defer:
___dos2_defer:
    ld hl,2
    add hl,sp

    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ld a,d
    or e

    jp z,cancel

    ld (C_DSKER_ROUTINE+1),de

    ld de,dsker_routine
cancel:
    ld c,_DEFER
    call msxlib_doscall

    ret
;;

dsker_routine:
    ld h,0
    ld l,a
    push hl
    ld h,0
    ld l,b
    push hl
    ld h,0
    ld l,c
    push hl
    push de

    jp C_DSKER_ROUTINE
dsker_routine_next:
    pop bc
    pop bc
    pop bc
    pop bc

    ld a,l

    ret

    SECTION data_user

C_DSKER_ROUTINE:
    db 0xcd
    dw 0
    jp dsker_routine_next