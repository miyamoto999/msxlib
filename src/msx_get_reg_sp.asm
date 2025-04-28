    SECTION code_user

    PUBLIC msx_get_reg_sp, _msx_get_reg_sp, ___msx_get_reg_sp

msx_get_reg_sp:
_msx_get_reg_sp:
___msx_get_reg_sp:
    ld hl,0
    add hl,sp

    ret