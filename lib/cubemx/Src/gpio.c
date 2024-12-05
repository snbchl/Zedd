/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(led_GPIO_Port, led_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, outA4_Pin|outA5_Pin|outA6_Pin|outA7_Pin
                          |outA8_Pin|outA11_Pin|outA12_Pin|outA14_Pin
                          |outA15_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, outB0_Pin|outB1_Pin|outB2_Pin|outB10_Pin
                          |outB12_Pin|outB13_Pin|outB14_Pin|outB15_Pin
                          |outB3_Pin|outB4_Pin|outB5_Pin|outB6_Pin
                          |outB7_Pin|outB8_Pin|outB9_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : led_Pin */
  GPIO_InitStruct.Pin = led_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(led_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : out_Pin outA5_Pin outA6_Pin outA7_Pin
                           outA8_Pin outA11_Pin outA12_Pin outA14_Pin
                           outA15_Pin */
  GPIO_InitStruct.Pin = outA4_Pin|outA5_Pin|outA6_Pin|outA7_Pin
                          |outA8_Pin|outA11_Pin|outA12_Pin|outA14_Pin
                          |outA15_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : outB0_Pin outB1_Pin outB2_Pin outB10_Pin
                           outB12_Pin outB13_Pin outB14_Pin outB15_Pin
                           outB3_Pin outB4_Pin outB5_Pin outB6_Pin
                           outB7_Pin outB8_Pin outB9_Pin */
  GPIO_InitStruct.Pin = outB0_Pin|outB1_Pin|outB2_Pin|outB10_Pin
                          |outB12_Pin|outB13_Pin|outB14_Pin|outB15_Pin
                          |outB3_Pin|outB4_Pin|outB5_Pin|outB6_Pin
                          |outB7_Pin|outB8_Pin|outB9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */