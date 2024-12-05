/*
 * Copyright (c) 2006-2024, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024-11-28     RT-Thread    first version
 */

#include <rtthread.h>
#include <main.h>
#include <gpio.h>
#include <usart.h>
#include <stm32f1xx.h>
#include <stm32f1xx_hal_conf.h>
#include <stm32f1xx_it.h>


#include <rtdbg.h>

uint16_t sweep()
{
    HAL_GPIO_WritePin(GPIOB, colB15_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, colB12_Pin|colB13_Pin|colB14_Pin, GPIO_PIN_RESET);
    if(HAL_GPIO_ReadPin(GPIOB, rowB1_Pin) == GPIO_PIN_RESET)
    {
        HAL_Delay(20);
        if(HAL_GPIO_ReadPin(GPIOB, rowB1_Pin) == GPIO_PIN_RESET)
        {
            while(HAL_GPIO_ReadPin(GPIOB, rowB1_Pin) == GPIO_PIN_RESET);
            HAL_UART_Transmit(&huart2, (uint8_t *)"key:25\r\n", 8, 1000);
            return 25;
        }
    }
}


void IN6(uint8_t pin)
{
    uint8_t level;
    switch(pin)
    {
    case 0:
        if(HAL_GPIO_ReadPin(GPIOB, rowB1_Pin) == GPIO_PIN_RESET){level = 0;}else{level = 1;}

    case 1:
            if(HAL_GPIO_ReadPin(GPIOB, rowB0_Pin) == GPIO_PIN_RESET){level = 0;}
            else{level = 1;}

    case 2:
            if(HAL_GPIO_ReadPin(GPIOA, rowA7_Pin) == GPIO_PIN_RESET){level = 0;}
            else{level = 1;}



    }
}

void OUT4(uint8_t pin)
{
    switch(pin)
       {
       case 0:HAL_GPIO_WritePin(GPIOB, colB15_Pin, GPIO_PIN_SET);
       break;
       case 1:HAL_GPIO_WritePin(GPIOB, colB14_Pin, GPIO_PIN_SET);
       break;
       case 2:HAL_GPIO_WritePin(GPIOB, colB13_Pin, GPIO_PIN_SET);
       break;
       case 3:HAL_GPIO_WritePin(GPIOB, colB12_Pin, GPIO_PIN_SET);
       break;
       }
}

int main(void)
{
    int count = 1;
    SystemClock_Config();
    while (count++)
    {
        LOG_D("Hello RT-Thread!");
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}
