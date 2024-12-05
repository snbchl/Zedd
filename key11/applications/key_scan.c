/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024-11-18     你好       the first version
 */
#include "key_scan.h"
#include "usart.h"
#include "stm32f1xx_hal_gpio.h"
#include <rtthread.h>
char key_count[10];
/*
 * func：按键io口输出，对输入的引脚置高低电平；
 * para：key：引脚位；lev：电平
 *
 *
 * */
void Key_GpioOut(unsigned char key, unsigned char lev)
{
    switch(key)
    {
        case 0:
            if(lev) HAL_GPIO_WritePin(OUT1_GPIO_Port, OUT1_Pin, GPIO_PIN_SET);
            else        HAL_GPIO_WritePin(OUT1_GPIO_Port, OUT1_Pin, GPIO_PIN_RESET);
        break;

        case 1:
            if(lev) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
            else        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
        break;

        case 2:
            if(lev) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
            else        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
        break;

        case 3:
            if(lev) HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
            else        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
        break;
    }
}

/*
 * func：读取指定引脚的电平，并对lev赋值；
 * para：key：引脚位；
 *
 * */
    unsigned char Key_GpioIn(unsigned char key)
    {
        unsigned char lev;      //防止warning
        switch(key)
        {
            case 4:
                if(HAL_GPIO_ReadPin(IN1_GPIO_Port, IN1_Pin) == GPIO_PIN_SET)    lev = 1;
                else        lev = 0;
            break;

            case 5:
                if(HAL_GPIO_ReadPin(IN2_GPIO_Port, IN2_Pin) == GPIO_PIN_SET)    lev = 1;
                else        lev = 0;
            break;

            case 6:
                if(HAL_GPIO_ReadPin(IN3_GPIO_Port, IN3_Pin) == GPIO_PIN_SET)    lev = 1;
                else        lev = 0;
            break;
            case 7:
                if(HAL_GPIO_ReadPin(IN4_GPIO_Port, IN4_Pin) == GPIO_PIN_SET)    lev = 1;
                else        lev = 0;
            break;
            case 8:
                if(HAL_GPIO_ReadPin(IN5_GPIO_Port, IN5_Pin) == GPIO_PIN_SET)    lev = 1;
                else        lev = 0;
            break;
            case 9:
                if(HAL_GPIO_ReadPin(IN6_GPIO_Port, IN6_Pin) == GPIO_PIN_SET)    lev = 1;
                else        lev = 0;
            break;
        }

        if(lev) return 1;
        else        return 0;
    }

/*
 * func：将引脚4-9的电平状态以十六进制形式存入back；
 * */
    unsigned char Key_Input()
    {
        unsigned char back = 0x00;

        back |= Key_GpioIn(4);

        for(unsigned char i=5; i<10; i++)
        {
            back = back << 1;
            back |= Key_GpioIn(i);
        }
//        rt_kprintf("bcke:%x\n",back);
        return back;
    }

    /*
     * func：给将指定引脚置低电平，其他三个高电平
     * para：out：电平参数
     * */
    void Key_Output(unsigned char out)
    {
        unsigned char temp;
        for(unsigned char i=0; i<4; i++)
        {
            temp = out & (0x01<<i);
            temp = temp >> i;
            Key_GpioOut(i, temp);
        }
    }


    void Key_Scan()
    {
        unsigned char temp;                 //临时储存

        //扫描第一行---------------------------------
//        Key_Output(0x07);       //out1置低
        Key_Output(0x0e);//给引脚0置低电平，其他三个高电平
        if(Key_Input() != 0x0f)
        {
            temp = Key_Input();//将输出引脚电平存入temp；

            switch(temp)//检查temp
            {

                case 0x1f:  key_scan = "KEY1";   break;//KEY1 15
                case 0x2f:  key_scan = "KEY5";   break;//KEY5 16
                case 0x37:  key_scan = "KEY9";   break;//KEY9 17
                case 0x3b:  key_scan = "KEY13";   break;//KEY13 18
                case 0x3d:  key_scan = "KEY17";   break;//KEY17 19
                case 0x3e:  key_scan = "KEY21";   break;//KEY21 10
            }
        }

        //扫描第二行---------------------------------
//        Key_Output(0x0b);       //out2置低
        Key_Output(0x0d);
        if(Key_Input() != 0x0f)
        {
            temp = Key_Input();

            switch(temp)
            {
            case 0x1f:  key_scan = "KEY2";   break;//KEY2 25
            case 0x2f:  key_scan = "KEY6";   break;//KEY6 26
            case 0x37:  key_scan = "KEY10";   break;//KEY10 27
            case 0x3b:  key_scan = "KEY14";   break;//KEY14 28
            case 0x3d:  key_scan = "KEY18";   break;//KEY18 29
            case 0x3e:  key_scan = "KEY22";   break;//KEY22 20
            }
        }

        //扫描第三行---------------------------------
//        Key_Output(0x0d);       //out3置低
        Key_Output(0x0b);
        if(Key_Input() != 0x0f)
        {
            temp = Key_Input();

            switch(temp)
            {
            case 0x1f:  key_scan = "KEY3";   break;//KEY3 35
            case 0x2f:  key_scan = "KEY7";   break;//KEY7 36
            case 0x37:  key_scan = "KEY11";   break;//KEY11 37
            case 0x3b:  key_scan = "KEY15";   break;//KEY15 38
            case 0x3d:  key_scan = "KEY19";   break;//KEY19 39
            case 0x3e:  key_scan = "KEY23";   break;//KEY23 30
            }
        }

        //扫描第四行---------------------------------
//        Key_Output(0x0e);
        Key_Output(0x07);//out4置低

        if(Key_Input() != 0x0f)
        {
            temp = Key_Input();

            switch(temp)
            {
            case 0x1f:  key_scan = "KEY4";   break;//KEY4 45
            case 0x2f:  key_scan = "KEY8";   break;//KEY8 46
            case 0x37:  key_scan = "KEY12";   break;//KEY12 47
            case 0x3b:  key_scan = "KEY16";   break;//KEY16 48
            case 0x3d:  key_scan = "KEY20";   break;//KEY20 49
            case 0x3e:  key_scan = "KEY24";   break;//KEY24 40
            }
        }

    }



    void key_TEST_entry()
    {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12,SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14,SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15,RESET);
        while(1)
        {
            HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
            rt_thread_mdelay(100);
            uint32_t pin_value0 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_0);
            uint32_t pin_value1 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_1);
            uint32_t pin_value2 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_2);
            uint32_t pin_value3 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_3);
            uint32_t pin_value4 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4);
            uint32_t pin_value5 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_5);
            if (pin_value0 == GPIO_PIN_RESET) {
                rt_kprintf("keyA0_ok!");
            }
            if (pin_value1 == GPIO_PIN_RESET) {
                rt_kprintf("keyA1_ok!");
            }
            if (pin_value2 == GPIO_PIN_RESET) {
                rt_kprintf("keyA2_ok!");
            }
            if (pin_value3 == GPIO_PIN_RESET) {
                rt_kprintf("keyA3_ok!");
            }
            if (pin_value4 == GPIO_PIN_RESET) {
                rt_kprintf("keyA4_ok!");
            }
            if (pin_value5 == GPIO_PIN_RESET) {
                rt_kprintf("keyA5_ok!");
            }
        }
    }
