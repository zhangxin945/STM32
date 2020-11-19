/*
    STM32_Delay_x(_Time_Unit, __num)
    @param:_Time_Unit us ms s minute hour
    Note:need TIM_x, this file use TIM1, internal clk 30, htim1
*/

#ifndef __STM32_DELAY_X_H

#include "main.h"
#include <stdint.h>

#define STM32_Delay_x(_Time_Unit, __num) delay_##_Time_Unit##(__num)
#define TIM_1US_CNT_NUM 10
void TIM_int_cnt(void);
void get_tim_struct(TIM_HandleTypeDef *htim);

#endif

