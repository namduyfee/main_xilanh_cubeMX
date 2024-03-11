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
#include "FEE_Function.h"
#include "FEE_Tu_Dong.h"
#include "FEE_Lai_Tay.h"
	
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
#define MC5_Pin GPIO_PIN_12
#define MC5_GPIO_Port GPIOB
#define MC6_Pin GPIO_PIN_13
#define MC6_GPIO_Port GPIOB
#define MC7_Pin GPIO_PIN_14
#define MC7_GPIO_Port GPIOB
#define MC8_Pin GPIO_PIN_15
#define MC8_GPIO_Port GPIOB
#define MC1_Pin GPIO_PIN_8
#define MC1_GPIO_Port GPIOA
#define MC2_Pin GPIO_PIN_11
#define MC2_GPIO_Port GPIOA
#define MC3_Pin GPIO_PIN_12
#define MC3_GPIO_Port GPIOA
#define SO0_Pin GPIO_PIN_15
#define SO0_GPIO_Port GPIOA
#define SO0_EXTI_IRQn EXTI15_10_IRQn
#define SO1_Pin GPIO_PIN_3
#define SO1_GPIO_Port GPIOB
#define SO1_EXTI_IRQn EXTI3_IRQn
#define SO2_Pin GPIO_PIN_4
#define SO2_GPIO_Port GPIOB
#define SO2_EXTI_IRQn EXTI4_IRQn
#define SO3_Pin GPIO_PIN_5
#define SO3_GPIO_Port GPIOB
#define SO3_EXTI_IRQn EXTI9_5_IRQn
#define MC4_Pin GPIO_PIN_8
#define MC4_GPIO_Port GPIOB
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

#pragma anon_unions
// struct luu tru du lieu UART

struct FEE_UART_struct_def
  {
		uint8_t		rxBuffer[32];
		uint8_t		txBuffer[32];
		uint8_t		DMA_rxBuffer[32];	
		uint8_t		rx_Data[32];
		uint8_t		CMD1[4];
		uint8_t		CMD2[4];
		uint16_t	RX_size;
		uint16_t	RX_Done;
		uint16_t	RX_Start;
		uint16_t	RX_Counter;
		uint16_t	TX_size;
		uint16_t	TX_Done;
		uint16_t	Disconnect;
		uint16_t	Protect;		
		uint8_t		Update;
		uint16_t	Loss;
	};
	
// thong so dong co 	
struct FEE_Thong_so_DC_struct_def	
{
	uint8_t chieu; 
	uint16_t toc_do
	
};


struct FEE_Trang_Thai_struct_def {
	
	uint8_t mode_run; 									// 0 : lai tay , 1 : tu dong
	uint8_t mode_lai_tay; 						// 0 : lai tay xoay lien tuc , 1 : lai tay xoay 90 , 180 
	
	uint8_t len_xuong;   							// 1 : nang , 0 : ha 
	
	uint8_t done[20]; 
	
	uint8_t home; 												// 0 : ve home và ko dem , 1 : co dem 
	uint8_t comple_reciver[20]; 		
	uint8_t khoi_tao_tu_dong; 			// tranh khoi tao nhieu lan 
	uint8_t check_sw_mode; 				// tranh chuyen mode nhieu lan 
	uint8_t check_sw_mode_lai_tay; 				// tranh chuyen mode nhieu lan
	uint8_t vi_tri_kep_lua; 						// tranh di chuyen den vi tri kep lua khoi tao nhieu lan 
	
	uint8_t count_vi_tri_tay_1_hien_tai; 				// vi tri hien tai tay 1 
	uint8_t count_vi_tri_tay_2_hien_tai; 				// vi tri hien tai tay 2 
	uint8_t count_vi_tri_tay_1_mong_muon; 	// vi tri mong muon khi cho xoay trai hoac phai 
	uint8_t count_vi_tri_tay_2_mong_muon; 	
	
	uint8_t chieu_xoay_1; 						// chieu xoay = 0 : xoay trai ; = 1 : xoay phai 
	uint8_t chieu_xoay_2; 						// xoay trai thi vi tri tay +  , xoay phai thi vi tri tay 
	
	uint8_t chong_troi_tay_1; 							// 0 : chua dc chong troi 
	uint8_t chong_troi_tay_2; 						  // 1 : da dc chong troi 
	
	uint8_t vi_tri_tay_xilanh[9]; 								// start to [1]
	
	uint16_t count_delay_chong_troi_1; 
	uint16_t count_delay_chong_troi_2;
	uint16_t limit_delay_chong_troi_1; 
	uint16_t limit_delay_chong_troi_2; 
	
	uint16_t count_suon_len_1; 
	uint16_t count_suon_len_2; 
	
	uint16_t luu_count_suon_len_1; 
	uint16_t luu_count_suon_len_2; 
	
	uint8_t khoi_dong_mem_tay_1; 
	uint8_t khoi_dong_mem_tay_2; 
	
}; 

// thong so tu dong 

struct FEE_Tu_Dong_struct_def {
	
	uint8_t stop_nang_ha; 
	uint8_t vi_tri_nang_ha; 
	uint8_t tha_lua; 
	uint8_t di_tha_lua;
	uint8_t gap_lua_len; 
	uint8_t khoi_tao_an_toan; 
	uint8_t kep_lua; 
	uint8_t tranh_cam_bien; 
	uint8_t tu_dong_number; 
	
	uint8_t day_keo_xilanh_an_toan[20]; 
	uint8_t check_cam_bien_td_tay_1[20]; 
	uint8_t check_cam_bien_td_tay_2[20]; 
	uint8_t check_cam_bien_td_nang_ha[20]; 

}; 

struct FEE_Lai_Tay_struct_def  {
	// 0 : 0 làm , 1 : lam 
	uint8_t flag_xilanh[9];  
	uint8_t chong_nhieu_xilanh[9];  
	uint8_t flag_nang; 
	uint8_t flag_ha; 
	uint8_t flag_tay_1_xoay_trai; 
	uint8_t flag_tay_1_xoay_phai;
	uint8_t flag_tay_2_xoay_trai; 
	uint8_t flag_tay_2_xoay_phai;
	uint8_t check_start_nang_ha; 
	uint8_t check_start_tay_1; 
	uint8_t check_start_tay_2; 
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
		
		// tu cau hinh 
		struct FEE_Thong_so_DC_struct_def Tay_1; 
		struct FEE_Thong_so_DC_struct_def Tay_2; 
		struct FEE_Thong_so_DC_struct_def Nang_ha; 
		struct FEE_Trang_Thai_struct_def TrangThai; 
		struct FEE_Tu_Dong_struct_def TuDong; 
		struct FEE_Lai_Tay_struct_def LaiTay; 
		
		uint16_t	Pulse;
		int16_t		Buff_Duty;
	};
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
