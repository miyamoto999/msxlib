		    include "msxlib/asm/msxdos.inc"

            SECTION code_user
            PUBLIC OUT_CRLF

; 改行を出力
OUT_CRLF:
			LD C,_STROUT
			LD DE,MSG_CRLF
			CALL BDOS
			RET

            SECTION rodata_user
MSG_CRLF:	db 0x0D, 0x0A, "$"
            
