    SECTION code_user
    PUBLIC cif_set_reg_workarea
    PUBLIC _cif_set_reg_workarea
    PUBLIC ___cif_set_reg_workarea

    EXTERN set_reg_workarea

cif_set_reg_workarea:
_cif_set_reg_workarea:
___cif_set_reg_workarea:
    ld hl,2
    add hl,sp

    ld d,(hl)
    inc hl
    inc hl
    ld b,(hl)
    call set_reg_workarea

    ld l,a
    ret
