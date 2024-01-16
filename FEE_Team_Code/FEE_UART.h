#ifndef		__FEE_UART_H__
#define		__FEE_UART_H__

/*******************************    INCLUDES   ********************************/

#include "cmsis_os.h"
#include "main.h"

/***************************    GLOBAL VARIABLES   ****************************/

extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart3;

/***************************       FUNCTIONS       ****************************/

void FEE_UART_Innit(void);
void FEE_UART_Test(void);

void send_uart(uint8_t data);

void pid_dc1(uint8_t chieu,uint8_t tocdo);
void pid_dc2(uint8_t chieu,uint8_t tocdo);
void pid_dc3(uint8_t chieu,uint8_t tocdo);
//void pid_dc8(uint8_t chieu,uint8_t tocdo);
//void pid_dc9(uint8_t chieu,uint8_t tocdo);
//void pid_dc10(uint8_t chieu,uint8_t tocdo);
#endif
