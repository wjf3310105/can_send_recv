/**
 * @brief       : 
 *
 * @file        : energy.h
 * @author      : gang.cheng
 * @version     : v0.0.1
 * @date        : 2015/5/7
 *
 * Change Logs  :
 *
 * Date        Version      Author      Notes
 * 2015/5/7    v0.0.1      gang.cheng    first version
 */
#ifndef __ENERGY_H__
#define __ENERGY_H__

#include "common/lib/lib.h"

#define FULL_POWER_VAR              (3800)
#define LOW_POWER_VAR               (3200)
#define POWER_DIV                   ((FULL_POWER_VAR-LOW_POWER_VAR)/100)
      

#define ADC12_INIT()                                                \
    do                                                              \
    {                                                               \
        P6SEL |= BIT4;                                              \
        P6DIR &= ~BIT4;                                             \
        REFCTL0 |= REFMSTR+REFVSEL_2+REFON+REFTCOFF;                \
        ADC12CTL0 |= ADC12SHT00 + ADC12SHT01 + ADC12SHT02 +         \
              ADC12SHT03 + ADC12REF2_5V + ADC12REFON_L + ADC12ON_L; \
	    ADC12CTL1 |= ADC12SHP + ADC12DIV0 + ADC12SSEL0;             \
	    ADC12CTL2 |= ADC12PDIV + ADC12TCOFF + ADC12RES1 + ADC12SR;  \
	    ADC12MCTL0 |= ADC12SREF_1 + ADC12INCH_4;                   \
    } while(__LINE__ == -1)
    

#define ADC12_WAIT_IDLE()	        while(ADC12CTL1 & ADC12BUSY)
#define ADC12_WAIT_CONVERSION_END()	while(!(ADC12IFG & BIT0))
#define ADC12_IS_CONVERSION_END()   (ADC12IFG & BIT0)
#define ADC12_ON()			        st( ADC12CTL0 |= ADC12ON_L; ADC12CTL0 |= ADC12ENC_L + ADC12SC_L; )
#define ADC12_OFF()			                                        \
        do                                                          \
        {                                                           \
            ADC12CTL0 = 0;                                          \
            ADC12CTL0 &= ~(ADC12ON_L|ADC12REFON_L|ADC12ENC_L);      \
            ADC12CTL0 = 0;                                          \
            ADC12CTL1 = 0; ADC12CTL2 = 0; ADC12MCTL0 = 0;           \
            REFCTL0 &= ~REFON;                                      \
        } while(__LINE__ == -1)
            
#define ADC12_CONVERSION_RESULT()	(((uint32_t)ADC12MEM0 * 2500) / 4095)

#define ADC12_FREE()         \
    do                       \
    {                        \
        ADC12_WAIT_IDLE();   \
	    ADC12_OFF();         \
    } while(__LINE__ == -1)
        
        
#define ADC12_DEINIT()       \
    do                       \
    {                        \
        P6SEL &= ~BIT4;      \
        P6DIR &= ~BIT4;      \
    } while(__LINE__ == -1)
        

void energy_init(void);

uint8_t energy_get(void);

/**
 * @brief 返回实际的电压值
 * @return  电压值，单位MV
 */
uint16_t energy_value(void);

#endif
