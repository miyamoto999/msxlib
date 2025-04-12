    include "msxlib/asm/msxwork.inc"
    include "msxlib/asm/vdp.inc"

    SECTION code_user
    PUBLIC asm_msxvdp_hmmc

    EXTERN asm_msxvdp_hmmc_start, asm_msxvdp_hmmc_next
    
; HMMCコマンドの実行
;
; 入力
;    hl <- MSXVDP_REG_DATA_HMMC構造体へのポインタ(アドレス)
;    de <- データのアドレス
;    bc <- データのサイズ
; 破壊レジスタ
;    a,f,b,c,d,e,h,l 
;
; 次のコードと同等
; /* HMMCコマンドの実行 */
; void __LIB__ msxvdp_hmmc(MSXVDP_REG_DATA_HMMC *reg_data, char *datas, uint16_t size) __smallc
; {
;     uint16_t idx = 0;
;     uint8_t status;
;     uint8_t data;
;     BOOL ret;

;     reg_data->first_data = (uint8_t)datas[idx];
;     idx++;

;     msxvdp_hmmc_start(reg_data);

;     do {
;         if(idx >= size) {
;             data = 0;
;         } else {
;             data = (uint8_t)datas[idx];
;             idx++;
;         }
;         ret = msxvdp_hmmc_next(data);
;     } while(!ret);
; }
asm_msxvdp_hmmc:
    push ix
    push hl
    pop ix
    ld a,(de)
    inc de
    dec bc
    ld (ix+MSXVDP_REG_DATA_HMMC_FIRST_DATA_OFFSET),a
    pop ix

    push bc
    call asm_msxvdp_hmmc_start
    pop bc

LOOP:
    ld a,b
    or c
    jr z,NO_DATA

    ld a,(de)
    inc de
    dec bc
NO_DATA:
    push bc
    call asm_msxvdp_hmmc_next
    pop bc

    jr nz,LOOP

    ret

