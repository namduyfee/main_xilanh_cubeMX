/*******************************    INCLUDES   ********************************/
#include "FEE_GPIO.h"

/***************************       FUNCTIONS       ****************************/

void FEE_GPIO_Innit(void)
{
		FEE_RTOS_struct.H_GPIO.S1 = 1;
		FEE_RTOS_struct.H_GPIO.S2 = 1;
		FEE_RTOS_struct.H_GPIO.S3 = 1;
		FEE_RTOS_struct.H_GPIO.S4 = 1;
//		FEE_RTOS_struct.H_GPIO.S5 = 0;
//		FEE_RTOS_struct.H_GPIO.S6 = 0;
//		FEE_RTOS_struct.H_GPIO.S7 = 0;
//		FEE_RTOS_struct.H_GPIO.S8 = 0;
//		
//		FEE_RTOS_struct.H_GPIO.S9 = 0;
//		FEE_RTOS_struct.H_GPIO.S10 = 0;
//		FEE_RTOS_struct.H_GPIO.S11 = 0;
//		FEE_RTOS_struct.H_GPIO.S12 = 0;
//		FEE_RTOS_struct.H_GPIO.S13 = 0;
//		FEE_RTOS_struct.H_GPIO.S14 = 0;
//		FEE_RTOS_struct.H_GPIO.S15 = 0;
//		FEE_RTOS_struct.H_GPIO.S16 = 0;
//		
//		FEE_RTOS_struct.H_GPIO.S17 = 0;
//		FEE_RTOS_struct.H_GPIO.S18 = 0;
//		FEE_RTOS_struct.H_GPIO.S19 = 0;
//		FEE_RTOS_struct.H_GPIO.S20 = 0;
//		FEE_RTOS_struct.H_GPIO.S21 = 0;
//		FEE_RTOS_struct.H_GPIO.S46 = 0;
//		FEE_RTOS_struct.H_GPIO.Led_Status = 0;
//    //FEE_RTOS_struct.H_GPIO.Speaker_Status = 0;
//		FEE_RTOS_struct.H_GPIO.DIR4 = 0;
//		
//		FEE_RTOS_struct.H_GPIO.S22 = 0;
//		FEE_RTOS_struct.H_GPIO.S23 = 0;
//		FEE_RTOS_struct.H_GPIO.S24 = 0;
//		FEE_RTOS_struct.H_GPIO.S25 = 0;
//		FEE_RTOS_struct.H_GPIO.S26 = 0;
//		FEE_RTOS_struct.H_GPIO.S27 = 0;
//		FEE_RTOS_struct.H_GPIO.S28 = 0;
//		FEE_RTOS_struct.H_GPIO.S29 = 0;
//		
//		FEE_RTOS_struct.H_GPIO.S30 = 0;
//		FEE_RTOS_struct.H_GPIO.S31 = 0;
//		FEE_RTOS_struct.H_GPIO.S32 = 0;
//		FEE_RTOS_struct.H_GPIO.S33 = 0;
//		FEE_RTOS_struct.H_GPIO.S34 = 0;
//		FEE_RTOS_struct.H_GPIO.S35 = 0;
//		FEE_RTOS_struct.H_GPIO.S36 = 0;
//		FEE_RTOS_struct.H_GPIO.S37 = 0;
//		
//		FEE_RTOS_struct.H_GPIO.S38 = 0;
//		FEE_RTOS_struct.H_GPIO.S39 = 0;
//		FEE_RTOS_struct.H_GPIO.S40 = 0;
//		FEE_RTOS_struct.H_GPIO.S41 = 0;
//		FEE_RTOS_struct.H_GPIO.S42 = 0;
//		FEE_RTOS_struct.H_GPIO.S43 = 0;
//		FEE_RTOS_struct.H_GPIO.S44 = 0;
//		FEE_RTOS_struct.H_GPIO.S45 = 0;
//		
//		FEE_RTOS_struct.H_GPIO.GPIO_EXTI = 0;		
//		FEE_RTOS_struct.H_GPIO.GPIO_S1_S8 = 0;
//		FEE_RTOS_struct.H_GPIO.GPIO_S9_S16 = 0;
//		FEE_RTOS_struct.H_GPIO.GPIO_S17_S21 = 0;
//		FEE_RTOS_struct.H_GPIO.GPIO_S22_S29 = 0;
//		FEE_RTOS_struct.H_GPIO.GPIO_S30_S37 = 0;
//		FEE_RTOS_struct.H_GPIO.GPIO_S38_S45 = 0;
		
}

void FEE_GPIO_Get_Data(void)
{
	FEE_RTOS_struct.H_GPIO.S1 = HAL_GPIO_ReadPin(SO0_GPIO_Port, SO0_Pin);
//	FEE_RTOS_struct.H_GPIO.S2 = HAL_GPIO_ReadPin(SO1_GPIO_Port, SO1_Pin);
	FEE_RTOS_struct.H_GPIO.S3 = HAL_GPIO_ReadPin(SO2_GPIO_Port, SO2_Pin);
    FEE_RTOS_struct.H_GPIO.S4 = HAL_GPIO_ReadPin(SO3_GPIO_Port, SO3_Pin);

//	FEE_RTOS_struct.H_GPIO.S5 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_5) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S6 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_4) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S7 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_3) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S8 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_2) ? 0 : 1;
//	
//	FEE_RTOS_struct.H_GPIO.S9 = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_10) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S10 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S11 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S12 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_13) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S13 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S14 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S15 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_10) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S16 = HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_9) ? 0 : 1;
//	
//	FEE_RTOS_struct.H_GPIO.S17 = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_2) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S18 = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_15) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S19 = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_14) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S20 = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_13) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S21 = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_12) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.S46 = HAL_GPIO_ReadPin(GPIOD, GPIO_PIN_11) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.Led_Status = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_3) ? 0 : 1;
//	FEE_RTOS_struct.H_GPIO.DIR4 = HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_4) ? 0 : 1;
	
	//FEE_RTOS_struct.H_GPIO.GPIO_EXTI = 0;		
//	FEE_RTOS_struct.H_GPIO.GPIO_S1_S8 = FEE_RTOS_struct.H_GPIO.S1 * 1 + 
//																			FEE_RTOS_struct.H_GPIO.S2 * 2 + 
//																			FEE_RTOS_struct.H_GPIO.S3 * 4 + 
//																			FEE_RTOS_struct.H_GPIO.S4 * 8 + 
//																			FEE_RTOS_struct.H_GPIO.S5 * 16 + 
//																			FEE_RTOS_struct.H_GPIO.S6 * 32 + 
//																			FEE_RTOS_struct.H_GPIO.S7 * 64 + 
//																			FEE_RTOS_struct.H_GPIO.S8 * 128;
//	
//	FEE_RTOS_struct.H_GPIO.GPIO_S9_S16 = 	FEE_RTOS_struct.H_GPIO.S9 * 1 + 
//																				FEE_RTOS_struct.H_GPIO.S10 * 2 + 
//																				FEE_RTOS_struct.H_GPIO.S11 * 4 + 
//																				FEE_RTOS_struct.H_GPIO.S12 * 8 + 
//																				FEE_RTOS_struct.H_GPIO.S13 * 16 + 
//																				FEE_RTOS_struct.H_GPIO.S14 * 32 + 
//																				FEE_RTOS_struct.H_GPIO.S15 * 64 + 
//																				FEE_RTOS_struct.H_GPIO.S16 * 128;
//	
//	FEE_RTOS_struct.H_GPIO.GPIO_S17_S21 = FEE_RTOS_struct.H_GPIO.S17 * 1 + 
//																				FEE_RTOS_struct.H_GPIO.S18 * 2 + 
//																				FEE_RTOS_struct.H_GPIO.S19 * 4 + 
//																				FEE_RTOS_struct.H_GPIO.S20 * 8 + 
//																				FEE_RTOS_struct.H_GPIO.S21 * 16 + 
//																				FEE_RTOS_struct.H_GPIO.S46 * 32 + 
//																				FEE_RTOS_struct.H_GPIO.Led_Status * 64 + 
//																				FEE_RTOS_struct.H_GPIO.DIR4 * 128;
	
//	FEE_RTOS_struct.H_GPIO.S22 = 0;
//	FEE_RTOS_struct.H_GPIO.S23 = 0;
//	FEE_RTOS_struct.H_GPIO.S24 = 0;
//	FEE_RTOS_struct.H_GPIO.S25 = 0;
//	FEE_RTOS_struct.H_GPIO.S26 = 0;
//	FEE_RTOS_struct.H_GPIO.S27 = 0;
//	FEE_RTOS_struct.H_GPIO.S28 = 0;
//	FEE_RTOS_struct.H_GPIO.S29 = 0;
//	
//	FEE_RTOS_struct.H_GPIO.S30 = 0;
//	FEE_RTOS_struct.H_GPIO.S31 = 0;
//	FEE_RTOS_struct.H_GPIO.S32 = 0;
//	FEE_RTOS_struct.H_GPIO.S33 = 0;
//	FEE_RTOS_struct.H_GPIO.S34 = 0;
//	FEE_RTOS_struct.H_GPIO.S35 = 0;
//	FEE_RTOS_struct.H_GPIO.S36 = 0;
//	FEE_RTOS_struct.H_GPIO.S37 = 0;
//	
//	FEE_RTOS_struct.H_GPIO.S38 = 0;
//	FEE_RTOS_struct.H_GPIO.S39 = 0;
//	FEE_RTOS_struct.H_GPIO.S40 = 0;
//	FEE_RTOS_struct.H_GPIO.S41 = 0;
//	FEE_RTOS_struct.H_GPIO.S42 = 0;
//	FEE_RTOS_struct.H_GPIO.S43 = 0;
//	FEE_RTOS_struct.H_GPIO.S44 = 0;
//	FEE_RTOS_struct.H_GPIO.S45 = 0;
	

//	FEE_RTOS_struct.H_GPIO.GPIO_S22_S29 = 0;
//	FEE_RTOS_struct.H_GPIO.GPIO_S30_S37 = 0;
//	FEE_RTOS_struct.H_GPIO.GPIO_S38_S45 = 0;
}


