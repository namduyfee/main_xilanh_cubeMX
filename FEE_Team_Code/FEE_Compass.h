#ifndef FEE_COMPASS_H
#define FEE_COMPASS_H

/*******************************    INCLUDES   ********************************/

#include "main.h"

/***************************    GLOBAL VARIABLES   ****************************/

extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;

extern ADC_HandleTypeDef hadc1;
extern DMA_HandleTypeDef hdma_adc1;

extern I2C_HandleTypeDef hi2c1;

extern TIM_HandleTypeDef htim1;

extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;
/***************************       FUNCTIONS       ****************************/

void FEE_Compass_Innit(void);
void FEE_Compass_Process(void);
void FEE_Compass_Check_Connect(void);
void lay_Goc(int16_t G_ly_thuyet);
#endif
