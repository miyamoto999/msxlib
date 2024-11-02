    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxsub_dos_setplt
    PUBLIC _msxsub_dos_setplt
    PUBLIC ___msxsub_dos_setplt
    GLOBAL dos_extrom

; void msxsub_dos_setplt(uint8_t pal, uint8_t r, uint8_t g, uint8_t b);
;   sp + 2 b
;   sp + 4 g
;   sp + 6 r
;   sp + 8  pal   
msxsub_dos_setplt:
_msxsub_dos_setplt:
___msxsub_dos_setplt:
    ; bを取り出す
    ld hl,2
    add hl,sp
    ld d,(hl)
    ; gを取り出す
    inc hl
    inc hl
    ld e,(hl)
    ; rを取り出す
    inc hl
    inc hl
    ld a,(hl)
    ; aを4ビットシフト
    sla a
    sla a
    sla a
    sla a
    ; r,bをまとめる
    or a,d
    ; palを取り出す
    inc hl
    inc hl
    ld d,(hl)

    push ix
    ld ix,MSXSUB_SETPLT
    call dos_extrom
    pop ix

    ret