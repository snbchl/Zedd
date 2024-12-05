/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024-11-22     GL       the first version
 */
#include "key.h"
#include <stdio.h>
#include <rtthread.h>
#include "stm32f1xx_hal_gpio.h"
#include <usart.h>
#include <string.h>
typedef void (*FunctionPointer)();
FunctionPointer functions[] = {Key1,Key2,Key3,Key4,Key5,Key6,Key7,Key8,Key9,Key10,Key11,Key12,Key13,Key14,Key15,Key16,Key17,Key18,Key19,Key20,Key21,Key22,Key23,Key24};
FunctionPointer functions1[] = {Key14,Key22,Key21,Key23,Key18,Key17,Key19,Key10,Key9,Key11};

#define Clear_key Key12

void key_count()
{
    for(int i = 1;i<10;i++){
        for(int j = 1;i<10;j++){
            functions1[i]();
            rt_thread_delay(500);
            functions1[j]();
        }
    }
}

void set_gpio_level(GPIO_TypeDef* GPIOx, GPIO_PinState Pin, uint8_t level) {
    if (level) {
        HAL_GPIO_WritePin(GPIOx, Pin, GPIO_PIN_SET); // 设置高电平
    } else {
        HAL_GPIO_WritePin(GPIOx, Pin, GPIO_PIN_RESET); // 设置低电平
    }
}

void key_TEST()
{

    for(int i = 0;i<24;i++)
    {
        functions[i]();

    }

}



void key_output_3bit()
{
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            for (int k = 1; k < 10; k++) {
                functions1[i]();
                rt_thread_delay(100);
                functions1[j]();
                rt_thread_delay(100);
                functions1[k]();
                rt_thread_delay(100);
                Clear_key();
                rt_thread_delay(100);
                rt_kprintf("\n");

               }
            }

        }
    }




void key_output_4bit()
{
    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            for (int k = 0; k <= 10; k++) {
                for (int p = 0; p <= 10; p++){
                functions[i]();
                rt_thread_delay(500);
                functions[j]();
                rt_thread_delay(500);
                functions[k]();
                rt_thread_delay(500);
                functions[p]();
                rt_thread_delay(500);
                functions[17]();
                rt_thread_delay(500);
                rt_kprintf("\n");
                }
            }
        }
    }

}





void Key1() {
    key1(1);
    if(HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin) == GPIO_PIN_SET)
    {
    rt_kprintf("key1____ok!");
    }
}

void Key2() {
    key2(1);
    rt_kprintf("key2____ok!");
}

void Key3() {
    key3(1);
    rt_kprintf("key3____ok!");
}
void Key4() {
    key4(1);
    rt_kprintf("key4____ok!");
}
void Key5() {
    key5(1);
    rt_thread_delay(1000);
    key5(0);
    rt_kprintf("key5____ok!");
}

void Key6() {
    key6(1);
    rt_kprintf("key6____ok!");
}

void Key7() {
    key7(1);
    rt_kprintf("key7____ok!");
}
void Key8() {
    key8(1);
    rt_kprintf("key8____ok!");
}

void Key9() {
    key9(1);
    rt_thread_delay(100);
    if(HAL_GPIO_ReadPin(KEY9_GPIO_Port, KEY9_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key9____ok!");
    }
    key9(0);
}

void Key10() {
    key10(1);
    rt_thread_delay(100);
    if(HAL_GPIO_ReadPin(KEY10_GPIO_Port, KEY10_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key10____ok!");
    }
    key10(0);
}

void Key11() {
    HAL_GPIO_WritePin(KEY11_GPIO_Port, KEY11_Pin, SET);
    rt_thread_delay(100);
    if(HAL_GPIO_ReadPin(KEY11_GPIO_Port, KEY11_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key11____ok!");
    }
    HAL_GPIO_WritePin(KEY11_GPIO_Port, KEY11_Pin, RESET);
}
void Key12() {
    HAL_GPIO_WritePin(KEY12_GPIO_Port, KEY12_Pin, SET);
    rt_thread_delay(100);
    if(HAL_GPIO_ReadPin(KEY12_GPIO_Port, KEY12_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key12____ok!");
    }
    HAL_GPIO_WritePin(KEY12_GPIO_Port, KEY12_Pin, RESET);
}
void Key13() {
    HAL_GPIO_WritePin(KEY13_GPIO_Port, KEY13_Pin, SET);
//      key12(1);

    rt_thread_delay(500);
    if(HAL_GPIO_ReadPin(KEY13_GPIO_Port, KEY13_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key13____ok!");
    }
//      key12(0);
    HAL_GPIO_WritePin(KEY13_GPIO_Port, KEY13_Pin, RESET);
}

void Key14() {
    HAL_GPIO_WritePin(KEY14_GPIO_Port, KEY14_Pin, SET);
    rt_thread_delay(100);
    if(HAL_GPIO_ReadPin(KEY14_GPIO_Port, KEY14_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key14____ok!");
    }
    HAL_GPIO_WritePin(KEY14_GPIO_Port, KEY14_Pin, RESET);
}

void Key15() {
    HAL_GPIO_WritePin(KEY15_GPIO_Port, KEY15_Pin, SET);
    rt_thread_delay(500);
    if(HAL_GPIO_ReadPin(KEY15_GPIO_Port, KEY15_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key15____ok!");
    }
    HAL_GPIO_WritePin(KEY15_GPIO_Port, KEY15_Pin, RESET);
}
void Key16() {
    HAL_GPIO_WritePin(KEY16_GPIO_Port, KEY16_Pin, SET);
    rt_thread_delay(500);
    if(HAL_GPIO_ReadPin(KEY16_GPIO_Port, KEY16_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key16____ok!");
    }
    HAL_GPIO_WritePin(KEY16_GPIO_Port, KEY16_Pin, RESET);
}

void Key17() {
    HAL_GPIO_WritePin(KEY17_GPIO_Port, KEY17_Pin, SET);
    rt_thread_delay(100);
    if(HAL_GPIO_ReadPin(KEY17_GPIO_Port, KEY17_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key17____ok!");
    }
    HAL_GPIO_WritePin(KEY17_GPIO_Port, KEY17_Pin, RESET);
}

void Key18() {
    HAL_GPIO_WritePin(KEY18_GPIO_Port, KEY18_Pin, SET);
    rt_thread_delay(100);
    if(HAL_GPIO_ReadPin(KEY18_GPIO_Port, KEY18_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key18____ok!");
    }
    HAL_GPIO_WritePin(KEY18_GPIO_Port, KEY18_Pin, RESET);
}

void Key19() {
    HAL_GPIO_WritePin(KEY18_GPIO_Port, KEY18_Pin, SET);
    rt_thread_delay(100);
    if(HAL_GPIO_ReadPin(KEY18_GPIO_Port, KEY18_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key18____ok!");
    }
    HAL_GPIO_WritePin(KEY18_GPIO_Port, KEY18_Pin, RESET);
}
void Key20() {
    HAL_GPIO_WritePin(KEY20_GPIO_Port, KEY20_Pin, SET);
    rt_thread_delay(500);
    if(HAL_GPIO_ReadPin(KEY20_GPIO_Port, KEY20_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key20____ok!");
    }
    HAL_GPIO_WritePin(KEY20_GPIO_Port, KEY20_Pin, RESET);
}
void Key21() {
    HAL_GPIO_WritePin(KEY21_GPIO_Port, KEY21_Pin, SET);
    rt_thread_delay(100);
    if(HAL_GPIO_ReadPin(KEY21_GPIO_Port, KEY21_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key21____ok!");
    }
    HAL_GPIO_WritePin(KEY21_GPIO_Port, KEY21_Pin, RESET);
}

void Key22() {
    key22(1);
    rt_thread_delay(100);
    if(HAL_GPIO_ReadPin(KEY22_GPIO_Port, KEY22_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key22____ok!");
    }
    key22(0);



}

void Key23() {
    key23(1);
    rt_thread_delay(100);
    if(HAL_GPIO_ReadPin(KEY23_GPIO_Port, KEY23_Pin) == GPIO_PIN_SET)
    {
        rt_kprintf("key23____ok!");
    }
    key23(0);

}
void Key24() {
    key24(0);
    if(HAL_GPIO_ReadPin(KEY24_GPIO_Port, KEY24_Pin) == GPIO_PIN_RESET)
    {
        rt_kprintf("key24____ok!");
    }

}
