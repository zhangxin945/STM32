#include "STM32_Delay_x.h"

static uint8_t tim_0p1us_int_cnt = 0;
static uint8_t tim_1us_cnt = 0;
static TIM_HandleTypeDef *Delay_x_htim = NULL;

/*
    Note: Put this function(TIM_int_cnt) into HAL_TIM_PeriodElapsedCallback() stm32_f1/2/3/4xx_hal_tim.c;
*/
void TIM_int_cnt(void)
{
    if (tim_0p1us_int_cnt < tim_1us_cnt)
    {
        tim_0p1us_int_cnt++;
    }
    HAL_TIM_Base_Stop_IT(Delay_x_htim);
}

/*
    Note: Put this function(get_tim_struct) into main() before while(1) main.c
*/
void get_tim_struct(TIM_HandleTypeDef *htim)
{
    Delay_x_htim = htim;
}

void delay_1us(void)
{
    tim_1us_cnt = TIM_1US_CNT_NUM;
    while (1)
    {
        HAL_TIM_Base_Start_IT(Delay_x_htim);
        if (tim_0p1us_int_cnt == tim_1us_cnt)
        {
            tim_1us_cnt = 0;
            tim_0p1us_int_cnt = 0;
            break;
        }
    }
}

void delay_us(uint32_t time_cnt)
{
    for (uint32_t i = 0; i < time_cnt; i++)
    {
        delay_1us();
    }
}

void delay_ms(uint32_t time_cnt)
{
    for (uint32_t i = 0; i < time_cnt; i++)
    {
        delay_us(1000);
    }
}

void delay_s(uint32_t time_cnt)
{
    for (uint32_t i = 0; i < time_cnt; i++)
    {
        delay_ms(1000);
    }
}