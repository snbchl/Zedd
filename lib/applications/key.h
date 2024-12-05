/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024-11-22     GL       the first version
 */
#ifndef APPLICATIONS_KEY_H_
#define APPLICATIONS_KEY_H_
#include "gpio.h"
#include "stm32f1xx_hal_gpio.h"
#include <rtthread.h>
#include "stm32f1xx_hal_gpio.h"
#define GPIO_HIGH(GPIOx,GPIO_PIN)    HAL_GPIO_WritePin(GPIOx,GPIO_PIN,GPIO_PIN_SET)
#define GPIO_LOW(GPIOx,GPIO_PIN)    HAL_GPIO_WritePin(GPIOx,GPIO_PIN,GPIO_PIN_SET)

#define key1(level) set_gpio_level(KEY1_GPIO_Port, KEY1_Pin, level)
#define key2(level) set_gpio_level(KEY2_GPIO_Port, KEY2_Pin, level)
#define key3(level) set_gpio_level(KEY3_GPIO_Port, KEY3_Pin, level)
#define key4(level) set_gpio_level(KEY4_GPIO_Port, KEY4_Pin, level)
#define key5(level) set_gpio_level(KEY5_GPIO_Port, KEY5_Pin, level)
#define key6(level) set_gpio_level(KEY6_GPIO_Port, KEY6_Pin, level)
#define key7(level) set_gpio_level(KEY7_GPIO_Port, KEY7_Pin, level)
#define key8(level) set_gpio_level(KEY8_GPIO_Port, KEY8_Pin, level)

#define key9(level) set_gpio_level(KEY9_GPIO_Port, KEY9_Pin, level)
#define key10(level) set_gpio_level(KEY10_GPIO_Port, KEY10_Pin, level)
#define key11(level) set_gpio_level(KEY11_GPIO_Port, KEY11_Pin, level)
#define key12(level) set_gpio_level(KEY12_GPIO_Port, KEY12_Pin, level)
#define key13(level) set_gpio_level(KEY13_GPIO_Port, KEY13_Pin, level)
#define key14(level) set_gpio_level(KEY14_GPIO_Port, KEY14_Pin, level)
#define key15(level) set_gpio_level(KEY15_GPIO_Port, KEY15_Pin, level)
#define key16(level) set_gpio_level(KEY16_GPIO_Port, KEY16_Pin, level)

#define key17(level) set_gpio_level(KEY17_GPIO_Port, KEY17_Pin, level)
#define key18(level) set_gpio_level(KEY18_GPIO_Port, KEY18_Pin, level)
#define key19(level) set_gpio_level(KEY19_GPIO_Port, KEY19_Pin, level)
#define key20(level) set_gpio_level(KEY20_GPIO_Port, KEY20_Pin, level)
#define key21(level) set_gpio_level(KEY21_GPIO_Port, KEY21_Pin, level)
#define key22(level) set_gpio_level(KEY22_GPIO_Port, KEY22_Pin, level)
#define key23(level) set_gpio_level(KEY23_GPIO_Port, KEY23_Pin, level)
#define key24(level) set_gpio_level(KEY24_GPIO_Port, KEY24_Pin, level)

void Key1();
void Key2();
void Key3();
void Key4();
void Key5();
void Key6();
void Key7();
void Key8();
void Key9();
void Key10();
void Key11();
void Key12();
void Key13();
void Key14();
void Key15();
void Key16();
void Key17();
void Key18();
void Key19();
void Key20();
void Key21();
void Key22();
void Key23();
void Key24();

void set_gpio_level(GPIO_TypeDef* GPIOx, GPIO_PinState Pin, uint8_t level);
void key_output_3bit();
void key_count();

uint16_t passnum[]={8858,6868,1233,5698,3336,2680};


#endif /* APPLICATIONS_KEY_H_ */