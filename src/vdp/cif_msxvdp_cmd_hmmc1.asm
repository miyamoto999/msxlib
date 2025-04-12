    SECTION code_user
    PUBLIC msxvdp_hmmc_start
    PUBLIC _msxvdp_hmmc_start
    PUBLIC ___msxvdp_hmmc_start
    PUBLIC msxvdp_hmmc_next
    PUBLIC _msxvdp_hmmc_next
    PUBLIC ___msxvdp_hmmc_next

    EXTERN asm_msxvdp_hmmc_start, asm_msxvdp_hmmc_next

msxvdp_hmmc_start:
_msxvdp_hmmc_start:
___msxvdp_hmmc_start:
    ld hl,2
    add hl,sp

    ld a,(hl)
    inc hl
    ld h,(hl)
    ld l,a

    jp asm_msxvdp_hmmc_start

msxvdp_hmmc_next:
_msxvdp_hmmc_next:
___msxvdp_hmmc_next:
    ld hl,2
    add hl,sp

    ld a,(hl)
    call asm_msxvdp_hmmc_next

    ld l,0
    ret nz

    inc l
    ret

