/*******************************    INCLUDES   ********************************/

#include "FEE_RTOS.h"
//#include "main.h"
/***************************    GLOBAL VARIABLES   ****************************/


struct FEE_RTOS_struct_def		    FEE_RTOS_struct;

/***************************       FUNCTIONS       ****************************/


void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == GPIO_PIN_15) {
	
	}
  if(GPIO_Pin == GPIO_PIN_4) {
	
	}
	
	if(GPIO_Pin == GPIO_PIN_5) {
	
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) 
{
	if(huart->Instance == USART1) // PES 
	{
		
	}
	if(huart->Instance == USART3) {
		
	}
	
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{	

}

void FEE_Data_Innit(void)
{
	FEE_RTOS_struct.UART_Update 		= 0;
	FEE_RTOS_struct.UART_Loss 			= 0;

	FEE_RTOS_struct.Process_Mode		= 0;
	FEE_RTOS_struct.Process_done		= 0;
	FEE_RTOS_struct.Request_Save_Flash	= 0;
	FEE_RTOS_struct.Request_Read_Flash	= 0;

	FEE_RTOS_struct.Pulse 				= 0;
	FEE_RTOS_struct.Buff_Duty 			= 0;
	
}



void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef* htim)
{		

}

void FEE_RTOS_Innit(void)
{	
  FEE_UART_Innit();
//	FEE_LCD_Innit();
	FEE_Data_Innit();
//	FEE_ADC_Innit();
//	FEE_EXTI_Innit();
	FEE_GPIO_Innit();
//	FEE_PES_Innit(&huart1);
//	FEE_Compass_Innit();
	
    // khoi tao timmer
	//HAL_TIM_Base_Start_IT(&htim2);
    
//    lcd_put_cur(1,0);
//    lcd_send_string("FEE_Start");
    //HAL_Delay(200);
	
	// cai dat DMA UART2: PES Remote
	//HAL_UART_Receive_IT(&huart2, FEE_RTOS_struct.H_Remote.DMA_rxBuffer, 8);
//	HAL_UARTEx_ReceiveToIdle_DMA(&huart2, FEE_RTOS_struct.H_Remote.DMA_rxBuffer, 8);
    //__HAL_DMA_DISABLE_IT(&hdma_usart2_rx, DMA_IT_HT);
}
	

