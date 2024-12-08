		    include "msxlib/asm/msxdos.inc"

            SECTION code_user

            PUBLIC DISPHEX

; Aレジスタの内容を16進数表示する。
DISPHEX:
			PUSH AF
			
			LD B,2
			LD HL,BUF
			RRA
			RRA
			RRA
			RRA
LOOP2:		AND 0x0F
			CP 0x0A
			JP M,UNDERTEN	; 10未満なら
			ADD A,0x07		; 後で30Hを足すとASCIIコードのA～Fになる
UNDERTEN:	ADD A,0x30		; 10未満ならASCIIコードの0～9にする。
							; 10以上なら前の行のADDと組み合わせでASCIIコードA～Fになる。
			LD (HL),A
			INC HL
			POP AF
			PUSH AF
			DEC B
			JP NZ,LOOP2
			
			LD DE,BUF
			LD C,_STROUT
			CALL BDOS
			
			POP AF
			
			RET

            SECTION data_user

BUF:		db	"00$"

