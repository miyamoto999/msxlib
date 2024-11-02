    include "msxlib/asm/msxbios.inc"

    SECTION code_user
    PUBLIC msxmain_dct_kilbuf
    PUBLIC _msxmain_dct_kilbuf
    PUBLIC ___msxmain_dct_kilbuf

;;;;; void msxmain_dct_kilbuf()

msxmain_dct_kilbuf:
_msxmain_dct_kilbuf:
___msxmain_dct_kilbuf:
    ; キー入力バッファをクリア
    jp MSXMAIN_KILBUF
