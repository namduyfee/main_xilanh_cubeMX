#ifndef FEE_PES_CONTROL_H
#define FEE_PES_CONTROL_H

/*******************************    INCLUDES   ********************************/

#include "main.h"
#include "FreeRTOSConfig.h"
#include "stdarg.h"
#include "stdio.h"
#include "string.h"

/***************************    GLOBAL VARIABLES   ****************************/

extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;

//extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern I2C_HandleTypeDef hi2c1;

//extern TIM_HandleTypeDef htim2;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

/***************************       FUNCTIONS       ****************************/

void FEE_PES_Innit(UART_HandleTypeDef* pes_uart_handle_def);
void FEE_PES_Check_Connect(void);
void pes_uart_event_handle(void);
void pesPrintf(uint8_t line, const char* pString, ...);
void pesMonitorClear(void);

#endif
