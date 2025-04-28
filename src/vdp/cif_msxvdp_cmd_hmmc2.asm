    SECTION code_user
    PUBLIC msxvdp_hmmc
    PUBLIC _msxvdp_hmmc
    PUBLIC ___msxvdp_hmmc

    EXTERN asm_msxvdp_hmmc
    
msxvdp_hmmc:
_msxvdp_hmmc:
___msxvdp_hmmc:
    ld hl,2
    add hl,sp

    ld c,(hl)
    inc hl
    ld b,(hl)
    inc hl

    ld e,(hl)
    inc hl
    ld d,(hl)
    inc hl

    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    jp asm_msxvdp_hmmc

