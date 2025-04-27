#include <msxlib/msxlib.h>
#include <msxlib/msxwork.h>
#include <msxlib/msxdos.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <assert.h>

// ダミー
uint8_t g_msxvdp_write_port_1 = 0;
uint8_t g_msxvdp_reg_saves = 0;
/////

#define REG0_7_SIZE (MSXWORK_RG7SAV - MSXWORK_RG0SAV + 1)
#define REG8_27_SIZE (MSXWORK_RG27SAV - MSXWORK_RG8SAV + 1)

uint8_t reg0_7[REG0_7_SIZE];
uint8_t reg8_27[REG8_27_SIZE];

uint8_t __LIB__ cif_set_reg_workarea(uint8_t reg, uint8_t val) __smallc;

static const uint8_t *reg_workarea[] = {
    MSXWORK_RG0SAV,MSXWORK_RG1SAV,MSXWORK_RG2SAV,MSXWORK_RG3SAV,MSXWORK_RG4SAV,
    MSXWORK_RG5SAV,MSXWORK_RG6SAV,MSXWORK_RG7SAV,MSXWORK_RG8SAV,MSXWORK_RG9SAV,
    MSXWORK_RG10SAV,MSXWORK_RG11SAV,MSXWORK_RG12SAV,MSXWORK_RG13SAV,MSXWORK_RG14SAV,
    MSXWORK_RG15SAV,MSXWORK_RG16SAV,MSXWORK_RG17SAV,MSXWORK_RG18SAV,MSXWORK_RG19SAV,
    MSXWORK_RG20SAV,MSXWORK_RG21SAV,MSXWORK_RG22SAV,MSXWORK_RG23SAV,0,
    MSXWORK_RG25SAV,MSXWORK_RG26SAV,MSXWORK_RG27SAV,
};

void test1(int reg)
{
    uint8_t back, ret;
    uint8_t *addr;

    if(reg > 27) {
        addr = 0;
    } else {
        addr = reg_workarea[reg];
    }
    memcpy(reg0_7, (char*)MSXWORK_RG0SAV, REG0_7_SIZE);
    memcpy(reg8_27, (char*)MSXWORK_RG8SAV, REG8_27_SIZE);

    if(addr) {
        back = *addr;
    }
    printf("Set vdp R#%d workarea:", reg);
    for(int i = 0; i < 256; i++) {
        ret = cif_set_reg_workarea(reg, i);
        if(addr) {
            if(reg < 8) {
                reg0_7[reg] = i;
            } else {
                reg8_27[(uint16_t)addr - MSXWORK_RG8SAV] = i;
            }
        }
    
        if(addr) {
            assert(ret == 1);
        } else {
            assert(ret == 0);
        }
        assert(memcmp((char*)MSXWORK_RG0SAV, reg0_7, REG0_7_SIZE) == 0);
        assert(memcmp((char*)MSXWORK_RG8SAV, reg8_27, REG8_27_SIZE) == 0);
    }

    if(addr) {
        *addr = back;
    }
    printf("OK\n");
}

int main(void) 
{
    for(int i = 0; i < 47;i++) {
        test1(i);
    }

    return 0;
}

