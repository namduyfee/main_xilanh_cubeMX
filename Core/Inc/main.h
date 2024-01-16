/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "FEE_RTOS.h"
#include "FEE_ADC.h"
#include "FEE_EXTI.h"
#include "FEE_GPIO.h"
#include "FEE_LCD.h"
#include "FEE_UART.h"
#include "FEE_PES_Control.h"
#include "FEE_Compass.h"
#include "FEE_Robot.h"
#include "FEE_FLASH.h"

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
#define IO1_Pin GPIO_PIN_13
#define IO1_GPIO_Port GPIOC
#define IO2_Pin GPIO_PIN_14
#define IO2_GPIO_Port GPIOC
#define IO3_Pin GPIO_PIN_15
#define IO3_GPIO_Port GPIOC
#define IO4_Pin GPIO_PIN_0
#define IO4_GPIO_Port GPIOA
#define IO5_Pin GPIO_PIN_1
#define IO5_GPIO_Port GPIOA
#define IO6_Pin GPIO_PIN_4
#define IO6_GPIO_Port GPIOA
#define IO7_Pin GPIO_PIN_5
#define IO7_GPIO_Port GPIOA
#define MC1_Pin GPIO_PIN_8
#define MC1_GPIO_Port GPIOA
#define MC2_Pin GPIO_PIN_11
#define MC2_GPIO_Port GPIOA
#define MC3_Pin GPIO_PIN_12
#define MC3_GPIO_Port GPIOA
#define SO0_Pin GPIO_PIN_15
#define SO0_GPIO_Port GPIOA
#define SO1_Pin GPIO_PIN_3
#define SO1_GPIO_Port GPIOB
#define SO2_Pin GPIO_PIN_4
#define SO2_GPIO_Port GPIOB
#define SO3_Pin GPIO_PIN_5
#define SO3_GPIO_Port GPIOB
#define IO0_Pin GPIO_PIN_8
#define IO0_GPIO_Port GPIOB
#define BUZZER_Pin GPIO_PIN_9
#define BUZZER_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */
#define MO 0
#define DONG 1
#define PI 3.141592654
#define V_Ban_2_ADDR 0x0801F800 //PAGE 126
#define V_Ban_ADDR 0x0801FC00 //PAGE 127
#define SAN        0x0801F100
#define angle 		FEE_RTOS_struct.H_Compass.Angle_Data
#define AngleRT 	FEE_RTOS_struct.H_Compass.Angle
#define FEE_PES     FEE_RTOS_struct.H_PES.cmd_b
#define FEE_PES_Js  FEE_RTOS_struct.H_PES.joystick_b
#define FEE_PES_Btn  FEE_RTOS_struct.H_PES.button_b
#define FEE_UART1   FEE_RTOS_struct.H_UART1
#define FEE_UART2   FEE_RTOS_struct.H_UART2
#define FEE_UART3   FEE_RTOS_struct.H_UART3
#define FEE_GPIOIn  FEE_RTOS_struct.H_GPIO
#define FEE_ADC     FEE_RTOS_struct.H_ADC
#define Sick3       FEE_RTOS_struct.H_ADC.DMA_adc_value[3]
#define SS1          HAL_GPIO_ReadPin(SO0_GPIO_Port, SO0_Pin)
#define SS2          HAL_GPIO_ReadPin(SO1_GPIO_Port, SO1_Pin)
#define SS3          HAL_GPIO_ReadPin(SO2_GPIO_Port, SO2_Pin)
#define SS4          HAL_GPIO_ReadPin(SO3_GPIO_Port, SO3_Pin)
#define TRAI        1
#define PHAI        0
#define COT1        FEE_RTOS_struct.H_PES.button_b.S24
#define COT2        FEE_RTOS_struct.H_PES.button_b.S23
#define COT3        FEE_RTOS_struct.H_PES.button_b.S19
#define COT4        FEE_RTOS_struct.H_PES.button_b.S18
#define COT5        FEE_RTOS_struct.H_PES.button_b.S17
#define COT6        FEE_RTOS_struct.H_PES.button_b.S22
#define COT7        FEE_RTOS_struct.H_PES.button_b.S21
#define COT8        FEE_RTOS_struct.H_PES.button_b.S20
#define CAO         0
#define THAP        1
#define ON          0
#define OFF         1
#define DO          1
#define XANH        0
#pragma anon_unions
// struct luu tru du lieu UART

struct FEE_UART_struct_def
{		
		uint8_t		rxBuffer[64];
		uint8_t		txBuffer[64];
		uint8_t		DMA_rxBuffer[64];
		uint8_t		CMD1[4];
		uint8_t		CMD2[4];
		uint16_t	RX_size;
		uint16_t	RX_Done;
		uint16_t	TX_size;
		uint16_t	TX_Done;
		uint16_t	Disconnect;
};
	
	
	// struct luu tru du lieu ADC
struct FEE_ADC_struct_def
{
		uint16_t 	DMA_adc_value[8]; 		// du lieu luu tru trong DMA
		uint16_t 	adc_value_Raw[8]; 		// gia tri tho 
		double 		adc_value_Volt[8]; 		// gia tri dien ap
		double 		adc_value_Result[8]; 	// ket qua tinh toan tu dien ap
		uint16_t 	DMA_done; 		// gia tri doc xong
};
	
	// struct luu tru du lieu GPIO
struct FEE_GPIO_struct_def
{
		uint8_t 	S1;
		uint8_t 	S2;
		uint8_t 	S3;
		uint8_t 	S4;
		uint16_t	EXTI_Counter1;
		uint16_t	EXTI_Counter2;
		uint16_t	EXTI_Counter3;
		uint16_t	EXTI_Counter4;
	};
	// struct luu tru du lieu PES
struct FEE_PES_struct_def
  {
		uint8_t		RX_Data[8];
		uint8_t		DMA_Data[8];
		uint8_t 	Verify;
		uint8_t 	IsConnected;
		TickType_t 	Timeout;
		
		uint8_t 	Header;
		union{
			uint8_t 	PES[2];
			struct{
				uint16_t Select:1;
				uint16_t L:1;
				uint16_t R:1;
				uint16_t Start:1;
				uint16_t Up:1;
				uint16_t Right:1;
				uint16_t Down:1;
				uint16_t Left:1;

				uint16_t L2:1;
				uint16_t R2:1;
				uint16_t L1:1;
				uint16_t R1:1;
				uint16_t TamGiac:1;
				uint16_t Tron:1;
				uint16_t X:1;
				uint16_t Vuong:1;
                    }cmd_b;
            };

		union{
			uint8_t 	US[4]; //uint8_t 	US[3]
			struct{
                    uint32_t S1:1;
                    uint32_t S2:1;
                    uint32_t S3:1;
                    uint32_t S4:1;
                    uint32_t S5:1;
                    uint32_t S6:1;
                    uint32_t S7:1;
                    uint32_t S8:1;
                    
                    uint32_t S9:1;
                    uint32_t S10:1;
                    uint32_t S11:1;
                    uint32_t S12:1;
                    uint32_t S13:1;
                    uint32_t S14:1;
                    uint32_t S15:1;
                    uint32_t S16:1;
                    
                    uint32_t S17:1;
                    uint32_t S18:1;
                    uint32_t S19:1;
                    uint32_t S20:1;
                    uint32_t S21:1;
                    uint32_t S22:1;
                    uint32_t S23:1;
                    uint32_t S24:1;
                    uint32_t 	:8;
                   }button_b;
            };

		union{
			uint8_t 	Analog;
			struct{
                    uint8_t down_L:1;
                    uint8_t up_L:1;
                    uint8_t right_L:1;
                    uint8_t left_L:1;
                    
                    uint8_t down_R:1;
                    uint8_t up_R:1;
                    uint8_t right_R:1;
                    uint8_t left_R:1;
                    }joystick_b;
                   };
		uint8_t 	CMD_Byte8;
		
	};
	
	// struct luu tru du lieu COMPASS
	struct FEE_Compass_struct_def
  {
		uint8_t		RX_Data[8];
		uint8_t		DMA_Data[8];
		uint8_t 	Verify;
		uint8_t 	isConnected;
		uint32_t 	Timeout;
		int16_t 	ss_g_now;
		int16_t 	ss_g_pre;
		int16_t 	Angle_Data;
		int16_t 	Angle;
	};
	
	// struct du lieu he thong
	struct FEE_RTOS_struct_def
  {	
		struct FEE_UART_struct_def H_UART1;
		struct FEE_UART_struct_def H_UART2;
		struct FEE_UART_struct_def H_UART3;
		struct FEE_UART_struct_def H_Remote;
		
		struct FEE_ADC_struct_def H_ADC;
		struct FEE_GPIO_struct_def H_GPIO;
		struct FEE_PES_struct_def H_PES;
		struct FEE_Compass_struct_def H_Compass;
		
		uint8_t		UART_Update;
		uint16_t	UART_Loss;
		
		uint8_t		Process_Mode;
		uint8_t		Process_done;
		uint8_t		Request_Save_Flash;
		uint8_t		Request_Read_Flash;
		
		uint16_t	Pulse;
		int16_t		Buff_Duty;
	};
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
