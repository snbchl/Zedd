/*
 * Copyright (c) 2006-2024, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024-11-29     RT-Thread    first version
 */

#include <rtthread.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include <stdio.h>
#include <string.h>
#include "stm32f1xx_hal_gpio.h"
#include "board.h"
#include "rtthread.h"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include <math.h>
#include <key.h>

uint16_t passnum[]={8858,6868,1233,5698,3336,2680};

uint8_t numake(int number) {
    int temp = number;
    int numDigits = 0;

    if (temp == 0) {
        numDigits = 1;
    } else {
        while (temp != 0) {
            temp /= 10;
            numDigits++;
        }
    }
    return numDigits;
}

double pow(double base, double exp) {
    double result = 1.0;
    // 使用循环计算幂
    for (int i = 0; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

void passout(uint16_t arr[],uint8_t len)
{
//    uint8_t num = sizeof(arr) / sizeof(arr[0]);
    for(int i=0; i<len; i++)

    {
        uint8_t wei = numake(passnum[i]);
        for(int j = wei ; j >= 1 ;j--)
        {
            int temp=0;
            temp = (passnum[i]/(1000/(int)pow(10,wei - j))) % 10;

            //函数调用key(temp);
            setlevel(temp);
            rt_kprintf("%d has set ",temp);
        }
        rt_kprintf("\n");
    }
}

//void setlevel(uint8_t ever)
//{
//    switch(ever)
//    {
//    case 0:HAL_GPIO_WritePin(GPIOA, outA4_Pin, GPIO_PIN_SET);break;
//    case 1:HAL_GPIO_WritePin(GPIOA, outA5_Pin, GPIO_PIN_SET);break;
//    case 2:HAL_GPIO_WritePin(GPIOA, outA6_Pin, GPIO_PIN_SET);break;
//    case 3:HAL_GPIO_WritePin(GPIOA, outA7_Pin, GPIO_PIN_SET);break;
//    case 4:HAL_GPIO_WritePin(GPIOA, outA8_Pin, GPIO_PIN_SET);break;
//    case 5:HAL_GPIO_WritePin(GPIOA, outA11_Pin, GPIO_PIN_SET);break;
//    case 6:HAL_GPIO_WritePin(GPIOA, outA12_Pin, GPIO_PIN_SET);break;
//    case 7:HAL_GPIO_WritePin(GPIOA, outA14_Pin, GPIO_PIN_SET);break;
//    case 8:HAL_GPIO_WritePin(GPIOA, outA15_Pin, GPIO_PIN_SET);break;
//    case 9:HAL_GPIO_WritePin(GPIOB, outB0_Pin, GPIO_PIN_SET);break;
//    case 10:HAL_GPIO_WritePin(GPIOB, outB1_Pin, GPIO_PIN_SET);break;
//    case 11:HAL_GPIO_WritePin(GPIOB, outB2_Pin, GPIO_PIN_SET);break;
//    case 12:HAL_GPIO_WritePin(GPIOB, outB3_Pin, GPIO_PIN_SET);break;
//    case 13:HAL_GPIO_WritePin(GPIOB, outB4_Pin, GPIO_PIN_SET);break;
//    case 14:HAL_GPIO_WritePin(GPIOB, outB5_Pin, GPIO_PIN_SET);break;
//    case 15:HAL_GPIO_WritePin(GPIOB, outB6_Pin, GPIO_PIN_SET);break;
//    case 16:HAL_GPIO_WritePin(GPIOB, outB7_Pin, GPIO_PIN_SET);break;
//    case 17:HAL_GPIO_WritePin(GPIOB, outB8_Pin, GPIO_PIN_SET);break;
//    case 18:HAL_GPIO_WritePin(GPIOB, outB9_Pin, GPIO_PIN_SET);break;
//    case 19:HAL_GPIO_WritePin(GPIOB, outB10_Pin, GPIO_PIN_SET);break;
//    case 20:HAL_GPIO_WritePin(GPIOB, outB12_Pin, GPIO_PIN_SET);break;
//    case 21:HAL_GPIO_WritePin(GPIOB, outB13_Pin, GPIO_PIN_SET);break;
//    case 22:HAL_GPIO_WritePin(GPIOB, outB14_Pin, GPIO_PIN_SET);break;
//    case 23:HAL_GPIO_WritePin(GPIOB, outB15_Pin, GPIO_PIN_SET);break;
//    }
//}

void setlevel(uint8_t ever)
{
    switch(ever)
    {
    case 0:Key1(); break;
    case 1:Key2();break;
    case 2:Key3();break;
    case 3:Key4();break;
    case 4:Key5();break;
    case 5:Key6();break;
    case 6:Key7();break;
    case 7:Key8();break;
    case 8:Key9();break;
    case 9:Key10();break;
    case 10:Key11();break;
    case 11:Key12();break;
    case 12:Key13();break;
    case 13:Key14();break;
    case 14:Key15();break;
    case 15:Key16();break;
    case 16:Key17();break;
    case 17:Key18();break;
    case 18:Key19();break;
    case 19:Key20();break;
    case 20:Key21();break;
    case 21:Key22();break;
    case 22:Key23();break;
    case 23:Key24();break;
    }
}

void dfs(int *temp, int index, int length, int width)
{
    if(index == length)
    {
        for(int i = 0; i<length; i++)
        {
            setlevel(temp[i]);
            rt_kprintf("%d has set\n",temp[i]);

        }
        return ;
    }

    for(int i = 1; i<= width; i++)
    {
        temp[index] = i;
        dfs(temp, index+1, length, width);
    }
}

int main(void)
{
    int count = 1;
//    int temp[24] = {0};
//    dfs(temp, 0, 4, 5);
      int length = sizeof(passnum) / sizeof(passnum[0]);
      passout(passnum,length);
    while (count++)
    {
        rt_thread_mdelay(1000);
    }

    return RT_EOK;
}