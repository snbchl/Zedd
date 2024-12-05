/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
//#define led_Pin GPIO_PIN_13
//#define led_GPIO_Port GPIOC
//#define outA4_Pin GPIO_PIN_4
//#define out_GPIO_Port GPIOA
//#define outA5_Pin GPIO_PIN_5
//#define outA5_GPIO_Port GPIOA
//#define outA6_Pin GPIO_PIN_6
//#define outA6_GPIO_Port GPIOA
//#define outA7_Pin GPIO_PIN_7
//#define outA7_GPIO_Port GPIOA
//#define outB0_Pin GPIO_PIN_0
//#define outB0_GPIO_Port GPIOB
//#define outB1_Pin GPIO_PIN_1
//#define outB1_GPIO_Port GPIOB
//#define outB2_Pin GPIO_PIN_2
//#define outB2_GPIO_Port GPIOB
//#define outB10_Pin GPIO_PIN_10
//#define outB10_GPIO_Port GPIOB
//#define outB12_Pin GPIO_PIN_12
//#define outB12_GPIO_Port GPIOB
//#define outB13_Pin GPIO_PIN_13
//#define outB13_GPIO_Port GPIOB
//#define outB14_Pin GPIO_PIN_14
//#define outB14_GPIO_Port GPIOB
//#define outB15_Pin GPIO_PIN_15
//#define outB15_GPIO_Port GPIOB
//#define outA8_Pin GPIO_PIN_8
//#define outA8_GPIO_Port GPIOA
//#define outA11_Pin GPIO_PIN_11
//#define outA11_GPIO_Port GPIOA
//#define outA12_Pin GPIO_PIN_12
//#define outA12_GPIO_Port GPIOA
//#define outA14_Pin GPIO_PIN_14
//#define outA14_GPIO_Port GPIOA
//#define outA15_Pin GPIO_PIN_15
//#define outA15_GPIO_Port GPIOA
//#define outB3_Pin GPIO_PIN_3
//#define outB3_GPIO_Port GPIOB
//#define outB4_Pin GPIO_PIN_4
//#define outB4_GPIO_Port GPIOB
//#define outB5_Pin GPIO_PIN_5
//#define outB5_GPIO_Port GPIOB
//#define outB6_Pin GPIO_PIN_6
//#define outB6_GPIO_Port GPIOB
//#define outB7_Pin GPIO_PIN_7
//#define outB7_GPIO_Port GPIOB
//#define outB8_Pin GPIO_PIN_8
//#define outB8_GPIO_Port GPIOB
//#define outB9_Pin GPIO_PIN_9
//#define outB9_GPIO_Port GPIOB

#define KEY1_Pin GPIO_PIN_0
#define KEY1_GPIO_Port GPIOA
#define KEY2_Pin GPIO_PIN_1
#define KEY2_GPIO_Port GPIOA
#define KEY3_Pin GPIO_PIN_2
#define KEY3_GPIO_Port GPIOA
#define KEY4_Pin GPIO_PIN_3
#define KEY4_GPIO_Port GPIOA
#define KEY5_Pin GPIO_PIN_4
#define KEY5_GPIO_Port GPIOA
#define KEY6_Pin GPIO_PIN_5
#define KEY6_GPIO_Port GPIOA
#define KEY7_Pin GPIO_PIN_6
#define KEY7_GPIO_Port GPIOA
#define KEY8_Pin GPIO_PIN_7
#define KEY8_GPIO_Port GPIOA
#define KEY9_Pin GPIO_PIN_0
#define KEY9_GPIO_Port GPIOB
#define KEY10_Pin GPIO_PIN_1
#define KEY10_GPIO_Port GPIOB
#define KEY11_Pin GPIO_PIN_10
#define KEY11_GPIO_Port GPIOB
#define KEY12_Pin GPIO_PIN_14
#define KEY12_GPIO_Port GPIOA
#define KEY13_Pin GPIO_PIN_12
#define KEY13_GPIO_Port GPIOB
#define KEY14_Pin GPIO_PIN_13
#define KEY14_GPIO_Port GPIOB
#define KEY15_Pin GPIO_PIN_14
#define KEY15_GPIO_Port GPIOB
#define KEY16_Pin GPIO_PIN_15
#define KEY16_GPIO_Port GPIOB
#define KEY17_Pin GPIO_PIN_8
#define KEY17_GPIO_Port GPIOA
#define KEY18_Pin GPIO_PIN_11
#define KEY18_GPIO_Port GPIOA
#define KEY19_Pin GPIO_PIN_12
#define KEY19_GPIO_Port GPIOA
#define KEY20_Pin GPIO_PIN_15
#define KEY20_GPIO_Port GPIOA
#define KEY21_Pin GPIO_PIN_3
#define KEY21_GPIO_Port GPIOB
#define KEY22_Pin GPIO_PIN_4
#define KEY22_GPIO_Port GPIOB
#define KEY23_Pin GPIO_PIN_5
#define KEY23_GPIO_Port GPIOB
#define KEY24_Pin GPIO_PIN_6
#define KEY24_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
