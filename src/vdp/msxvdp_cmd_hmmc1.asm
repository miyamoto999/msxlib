    include "msxlib/asm/msxwork.inc"
    include "msxlib/asm/vdp.inc"

    SECTION code_user
    PUBLIC asm_msxvdp_hmmc_start
    PUBLIC asm_msxvdp_hmmc_next
    EXTERN _g_msxvdp_write_port_1, _g_msxvdp_read_port_1, _g_msxvdp_write_port_3


;   HMMCのコマンド送信 
;
;   入力
;       hl <- MSXVDP_REG_DATA_HMMC構造体へのポインタ(アドレス)
;
;   破壊レジスタ
;       a,f,b,c
;
;   次のコードと同等
; /* HMMCのコマンド送信 */
; void __LIB__ msxvdp_hmmc_start(MSXVDP_REG_DATA_HMMC *reg_data) __smallc
; {
;     msxvdp_set_reg_indirect(36);
;     for(int i = 0; i < sizeof(MSXVDP_REG_DATA_HMMC); i++)
;     {
;         msxvdp_set_reg_indirect_val(((uint8_t *)reg_data)[i]);
;     }
;     msxvdp_set_reg_indirect_val(MSXVDP_CMD_HMMC);
; }

asm_msxvdp_hmmc_start:
    ld a,(_g_msxvdp_write_port_1)
    ld c,a

    di
    MAC_VDP_SET_REG_INDIRECT 36
    ei
    
    ld a,36
    ld (MSXWORK_RG17SAV),a

    ld a,(_g_msxvdp_write_port_3)
    ld c,a

    ld b,MSXVDP_REG_DATA_HMMC_SIZE
    otir

    ld a,MSXVDP_CMD_HMMC
    out (c),a

    ret


;;;;;;;
; HMMCの次のデータを送信
;
; 入力
;    a <- 送信するデータ
; 出力
;    zフラグ <- 1:送信完了(HMMCの全データ送信完了)
;         0:次のデータ要求
; 破壊レジスタ
;    a,f,b,c,h,l 
;
; 次のコードと同等
; /* HMMCの次のデータを送信 */
; BOOL __LIB__ msxvdp_hmmc_next(uint8_t data) __smallc
; {
;     uint8_t status;

;     while(TRUE) {
;         status = msxvdp_get_status(2);
;         if((status & MSXVDP_STATUS2_CE) == 0) {
;             return TRUE;
;         }
;         if((status & MSXVDP_STATUS2_TR) != 0) {
;             break;
;         }
;     }
;     msxvdp_set_reg(44, data);
    
;     return FALSE;
; }

asm_msxvdp_hmmc_next:
    ld b,a

LOOP:
    di
    MAC_VDP_GET_STATUS h,2
    ei
    ld a,h
    and MSXVDP_STATUS2_CE
    ret z
    ld a,h
    and MSXVDP_STATUS2_TR
    jr z,LOOP

    ld a,(_g_msxvdp_write_port_1)
    ld c,a
    di
    MAC_VDP_SET_REG 44, b
    ei

    or a

    ret

