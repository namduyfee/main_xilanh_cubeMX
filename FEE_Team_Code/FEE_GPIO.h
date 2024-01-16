#ifndef		__FEE_GPIO_H__
#define		__FEE_GPIO_H__

/*******************************    INCLUDES   ********************************/
#include "main.h"
//#include "cmsis_os.h"

/***************************   GLOBAL VARIABLES  ******************************/
extern struct FEE_RTOS_struct_def	FEE_RTOS_struct;


/***************************       FUNCTIONS       ****************************/

//Khoi tao GPIO
void FEE_GPIO_Innit(void);

//Lay du lieu tu GPIO
void FEE_GPIO_Get_Data(void);

#endif
