/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2024-11-18     你好       the first version
 */
#ifndef APPLICATIONS_KEY_SCAN_H_
#define APPLICATIONS_KEY_SCAN_H_


extern  char* key_scan;
void Key_GpioOut(unsigned char key, unsigned char lev);

unsigned char Key_GpioIn(unsigned char key);
unsigned char Key_Input();
void Key_Output(unsigned char out);
void Key_Scan();
void key_TEST_entry();

#endif /* APPLICATIONS_KEY_SCAN_H_ */
