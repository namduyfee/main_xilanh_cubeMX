#ifndef		__FEE_ADC_H__
#define		__FEE_ADC_H__

/*******************************    INCLUDES   ********************************/
#include "main.h"
#include "cmsis_os.h"

/***************************   GLOBAL VARIABLES  ******************************/

extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;

//extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern I2C_HandleTypeDef hi2c1;

//extern TIM_HandleTypeDef htim2;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

/***************************       FUNCTIONS       ****************************/

void FEE_ADC_Innit(void);
// luu du lieu tu DMA
void FEE_ADC_Get_Raw(void);
// tinh gia tri dien ap tu gia tri tho
void FEE_ADC_Get_Volt(void);
// tinh toan du lieu tu dien ap do duoc
void FEE_ADC_Get_Result(void);

#endif
