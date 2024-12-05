/*
 * Copyright (c) 2006-2024, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024-11-15     RT-Thread    first version
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
#include "key_scan.h"
static rt_thread_t led_id =RT_NULL;
static rt_thread_t key_id =RT_NULL;
static rt_thread_t key_test =RT_NULL;
 char* key_scan;     //键盘扫描的值


void led_rt_thread_entry()
{

    while(1)
    {
            rt_thread_mdelay(500);
            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
            rt_thread_mdelay(500);
            HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
    }
}



    void key_rt_thread_entry()
    {
        while(1)
        {
            rt_thread_mdelay(50);
            Key_Scan();
                rt_kprintf("key_velue:%s\n",key_scan);
//                key_scan = 0;

        }
    }
    uint16_t passnum[]={6686};

uint8_t numake(int number) {
    int temp = number; // 保存原始数值以便计算位数
    int numDigits = 0;

    // 计算数字的位数
    if (temp == 0) {
        numDigits = 1; // 特殊处理0的情况
    } else {
        while (temp != 0) {
            temp /= 10;
            numDigits++;
        }
    }
    return numDigits;
}


void passout(uint8_t arr[])
{
    for(int i=0; i<sizeof(passnum); i++)
    {
        uint8_t wei = numake(passnum[i]);
        for(int i = wei - 1; i >= 0 ;i--)
        {
            int temp=0;
            temp = passnum[i] % 10;
            //函数调用key(temp);
            temp /= 10;
        }
    }
}

void setlevel(uint8_t ever)
{
    switch(ever)
    {
    case 0:HAL_GPIO_WritePin(GPIOA, IN1_Pin, GPIO_PIN_SET);break;
    case 1:HAL_GPIO_WritePin(GPIOA, IN2_Pin, GPIO_PIN_SET);break;
    case 2:HAL_GPIO_WritePin(GPIOA, IN3_Pin, GPIO_PIN_SET);break;
    case 3:HAL_GPIO_WritePin(GPIOA, IN4_Pin, GPIO_PIN_SET);break;
    case 4:HAL_GPIO_WritePin(GPIOA, IN5_Pin, GPIO_PIN_SET);break;
    case 5:HAL_GPIO_WritePin(GPIOA, IN6_Pin, GPIO_PIN_SET);break;
    case 6:HAL_GPIO_WritePin(GPIOB, OUT1_Pin, GPIO_PIN_SET);break;
    case 7:HAL_GPIO_WritePin(GPIOB, TOU2_Pin, GPIO_PIN_SET);break;
    case 8:HAL_GPIO_WritePin(GPIOB, TOU3_Pin, GPIO_PIN_SET);break;
    case 9:HAL_GPIO_WritePin(GPIOB, TOU4_Pin, GPIO_PIN_SET);break;
    }
}

void dfs(int *temp, int index, int length, int width)
{
    if(index == length)
    {
        for(int i = 0; i<length; i++)
        {
            rt_kprintf("%d has set",temp[i]);
            setlevel(temp[i]);
        }
        return ;
    }

    for(int i = 1; i<= width; i++)
    {
        temp[index] = i;
        dfs(temp, index+1, length, width);
    }
}




//    void key_send_in(unsigned char key , unsigned lev)
//
//    {
//        switch (key)
//        {
//            case 0:
//            if(lev) HAL_GPIO_WritePin(IN1_GPIO_Port, IN1_Pin, GPIO_PIN_SET);
//            break;
//
//            case 1:
//            if(lev) HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_SET);
//                else HAL_GPIO_WritePin(IN2_GPIO_Port, IN2_Pin, GPIO_PIN_RESET);
//            break;
//
//            case 2:
//            if(lev) HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, GPIO_PIN_SET);
//                else HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, GPIO_PIN_RESET);
//            break;
//
//            case 3:
//            if(lev) HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, GPIO_PIN_SET);
//                else HAL_GPIO_WritePin(IN3_GPIO_Port, IN3_Pin, GPIO_PIN_RESET);
//            break;
//
//            case 4:
//            if(lev) HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, GPIO_PIN_SET);
//                else HAL_GPIO_WritePin(IN4_GPIO_Port, IN4_Pin, GPIO_PIN_RESET);
//            break;
//
//            case 5:
//            if(lev) HAL_GPIO_WritePin(IN5_GPIO_Port, IN5_Pin, GPIO_PIN_SET);
//                else HAL_GPIO_WritePin(IN5_GPIO_Port, IN5_Pin, GPIO_PIN_RESET);
//            break;
//        }
//    }
//
//
//
//void Key_intput(unsigned char out)
//
//{
//    unsigned char temp;
//
//    for (int i = 1;i < 6; i++)
//    {
//        temp = out & (0x20>>1);
//        key_send_in(i,temp);
//    }
//}
//void key_out(unsigned char out)
//{
//    unsigned char temp;
//    for (int i = 0; i < 4; i++)
//    {
//        temp = out & (0x08>>1);
//
//        Key_GpioOut(i, temp);
//    }
//}
//
//void Key_send_scan()
//{
//    key_out(0x07);
//    Key_intput(0x1f);
//
//}

int main(void)
{
    HAL_Init();
    MX_GPIO_Init();
    MX_USART1_UART_Init();
    led_id = rt_thread_create("led1_thread", led_rt_thread_entry, RT_NULL, 512, 25, 25);
                    //  启动线程
    key_id = rt_thread_create("key_thread", key_rt_thread_entry, RT_NULL, 512, 25, 25);

    key_test = rt_thread_create("key_test", key_TEST_entry, RT_NULL, 512, 25, 25);

    if(led_id != RT_NULL)
      {
          rt_thread_startup(led_id);
          rt_kprintf("led_iBd start ok!\n");
      }

    if(key_id != RT_NULL)
      {
          rt_thread_startup(key_id);
          rt_kprintf("key_scan_start ok!\n");
      }

    if(key_test != RT_NULL)
      {
//          rt_thread_startup(key_test);
//          rt_kprintf("key_scan_start ok!\n");
      }

    int count = 1;

    while (count++)
    {

        rt_thread_mdelay(500);
    }
//    return RT_EOK;
}

