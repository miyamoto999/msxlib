
            SECTION code_user
            GLOBAL DISPHEX, OUT_SPC, OUT_CRLF
            PUBLIC DUMP
            
; メモリダンプ
;	HL:スタートアドレス
;	BC:バイト数
DUMP:		LD A,(HL)
			PUSH HL
			PUSH BC
			CALL DISPHEX
			CALL OUT_SPC
			POP BC
			POP HL
			DEC BC
			INC HL
			LD A,B
			OR C
			JR NZ,DUMP
			CALL OUT_CRLF
			RET
