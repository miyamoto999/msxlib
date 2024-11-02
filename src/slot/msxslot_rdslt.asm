    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxslot_rdslt
    PUBLIC _msxslot_rdslt
    PUBLIC ___msxslot_rdslt

;;;; uint8_t msxslot_rdslt(uint8_t slot, void *addr);
msxslot_rdslt:
_msxslot_rdslt:
___msxslot_rdslt:
    ; リターンアドレスを無視
    ld hl,2
    add hl,sp
    ; addrを取り出す
    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl
    ; slotを取り出す
    ld a,(hl)

    push ix
    ex hl,de
    call MSXMAIN_RDSLT
    ei
    ld l,a
    pop ix

    ret