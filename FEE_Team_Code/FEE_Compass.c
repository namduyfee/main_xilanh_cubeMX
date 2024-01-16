/*******************************    INCLUDES   ********************************/
#include "FEE_Compass.h"

/*******************************    DEFINITONS   ******************************/

#define DISCONNECT_TIMEOUT	500

/***************************    GLOBAL VARIABLES   ****************************/

int pc = 0;
int16_t ss_g_now=0,ss_g_pre=0;


/***************************       FUNCTIONS       ****************************/

void FEE_Compass_Innit(void)
{
	for(pc = 0; pc < 8; pc++)
	{
		FEE_RTOS_struct.H_Compass.RX_Data[pc] = 0;
		FEE_RTOS_struct.H_Compass.DMA_Data[pc] = 0;
	}
	// khoi tao Compass Data
	FEE_RTOS_struct.H_Compass.Verify = 0;
	FEE_RTOS_struct.H_Compass.isConnected = 0;
	FEE_RTOS_struct.H_Compass.Timeout = 0;
	FEE_RTOS_struct.H_Compass.Angle_Data = 0;
	FEE_RTOS_struct.H_Compass.Angle = 0;
    
	

	FEE_RTOS_struct.H_UART3.txBuffer[0] = 'a';
	HAL_UART_Transmit(&huart3, &FEE_RTOS_struct.H_UART3.txBuffer[0], 1, 100);
    HAL_Delay(200);
	FEE_RTOS_struct.H_UART3.txBuffer[0] = 'a';
	HAL_UART_Transmit(&huart3, &FEE_RTOS_struct.H_UART3.txBuffer[0], 1, 100);
    HAL_Delay(200);
	FEE_RTOS_struct.H_UART3.txBuffer[0] = 'z';
	HAL_UART_Transmit(&huart3, &FEE_RTOS_struct.H_UART3.txBuffer[0], 1, 100);
    HAL_Delay(200);
	HAL_UART_Receive_IT(&huart3, &FEE_RTOS_struct.H_Compass.RX_Data[0], 1);
}

void FEE_Compass_Check_Connect(void)
{
	if(FEE_RTOS_struct.H_Compass.isConnected){
		FEE_RTOS_struct.H_Compass.isConnected = 0;
	}
	else{
		if(xTaskGetTickCount() - FEE_RTOS_struct.H_Compass.Timeout >= DISCONNECT_TIMEOUT){
			// todo: reconnect and beep to warning.

			FEE_RTOS_struct.H_UART3.txBuffer[0] = 'z';
            
        HAL_UART_Transmit(&huart3, &FEE_RTOS_struct.H_UART3.txBuffer[0], 1, 100);
        HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 1);
        osDelay(300);
        HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 0);
        osDelay(300);

			HAL_UART_Receive_IT(&huart3, &FEE_RTOS_struct.H_Compass.RX_Data[0], 1);
		}
	}
}

void FEE_Compass_Process(void)
{
	static uint8_t byHeadIsTrue = 0;
	static uint8_t i_compass = 0;
	static uint8_t compassBuff[3];
	
		if(FEE_RTOS_struct.H_Compass.RX_Data[0] == 'z'){
			byHeadIsTrue = 1;
			i_compass = 0;
		}
		else{
			if(byHeadIsTrue){
				compassBuff[i_compass++] = FEE_RTOS_struct.H_Compass.RX_Data[0];
				if(i_compass >= 2)
				{
						byHeadIsTrue = 0;
						i_compass = 0;
						FEE_RTOS_struct.H_Compass.Angle_Data = (compassBuff[1]<<8 | compassBuff[0]) - (ss_g_now*10);
						FEE_RTOS_struct.H_Compass.Angle = FEE_RTOS_struct.H_Compass.Angle_Data*360/3600;

						FEE_RTOS_struct.H_Compass.isConnected = 1;
						FEE_RTOS_struct.H_Compass.Timeout = xTaskGetTickCount();
				}
			}
		}
    HAL_UART_Receive_IT(&huart3, &FEE_RTOS_struct.H_Compass.RX_Data[0], 1);
}


void lay_Goc(int16_t G_ly_thuyet)
{
    ss_g_pre=ss_g_now;
    ss_g_now=(FEE_RTOS_struct.H_Compass.Angle-G_ly_thuyet)+ss_g_pre;
}