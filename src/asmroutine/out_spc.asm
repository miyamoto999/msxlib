		    include "msxlib/asm/msxdos.inc"

            SECTION code_user
            PUBLIC OUT_SPC

; スペースを出力
OUT_SPC:	LD C,_CONOUT
			LD E,0x20
			CALL BDOS
			RET

