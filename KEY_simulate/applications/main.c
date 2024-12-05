/*
 * Copyright (c) 2006-2024, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024-11-22     RT-Thread    first version
 */

#include <rtthread.h>
#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "main.h"
#include "usart.h"
#include "gpio.h"
#include "key.h"
static rt_thread_t key_id =RT_NULL;
//static rt_thread_t key_id =RT_NULL; // 全局线程ID
static rt_thread_t lib_id =RT_NULL;
extern uint16_t passnum[7] ;//密码库数组
void SystemClock_Config(void);
//
//
//
void key_output3bit(void)
{
    if(key_id != RT_NULL)
    {
        rt_thread_startup(key_id);
        rt_kprintf("led_iBd start ok!\n");
    }

}
MSH_CMD_EXPORT(key_output3bit , say hello to RT-Thread);


static void key_delete_thread(void)
{
    if (key_id != RT_NULL)
    {
        rt_thread_delete(key_id); // 删除线程
    }
}
MSH_CMD_EXPORT(key_delete_thread , say hello to RT-Thread);
//
//void key_rt_thread_entry()
//{
//    while (1)
//    {
//
//        key_output_3bit();
//    }

void key_rt_thread_entry()
{

    while(1)
    {

        key_output_3bit();

    }

}


int main(void)
{
    int count = 1;

    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_USART1_UART_Init();
//    g_tid = rt_thread_create("my_thread",thread_entry, RT_NULL,1024,10,10);

//    key_id = rt_thread_create("key_thread", key_rt_thread_entry, RT_NULL, 1024, 10, 10);
//    key_id = rt_thread_create("led1_thread", key_rt_thread_entry, RT_NULL, 512, 25, 25);
//    lib_id = rt_thread_create("lib_thread", lib_rt_thread_entry, (uint8_t*)passnum,RT_NULL, 512, 25, 25);
    uint16_t length = sizeof(passnum) / sizeof(passnum[0]);//计算长度
    passout(passnum,length);//调用函数输出；
    while (count++)
    {
      rt_thread_mdelay(1000);
    }

    return RT_EOK;
}