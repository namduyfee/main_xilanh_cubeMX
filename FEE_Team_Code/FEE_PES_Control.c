/*******************************    INCLUDES   ********************************/
#include "FEE_PES_Control.h"

/*******************************    DEFINITONS   ******************************/

#define DISCONNETC_TIMEOUT	1000 // 1s (do configTICK_RATE_HZ = 1000Hz)

/***************************    GLOBAL VARIABLES   ****************************/

int ph = 0;

UART_HandleTypeDef* UartTransmit;

/***************************       FUNCTIONS       ****************************/

void FEE_PES_Innit(UART_HandleTypeDef* pes_uart_handle_def)
{
	UartTransmit = pes_uart_handle_def;
	memset(&FEE_RTOS_struct.H_PES, 0, sizeof(struct FEE_PES_struct_def));
	
	FEE_RTOS_struct.H_PES.Analog = 0xFF;
	FEE_RTOS_struct.H_PES.US[0] = 0xFF;
	FEE_RTOS_struct.H_PES.US[1] = 0xFF;
	FEE_RTOS_struct.H_PES.US[2] = 0xFF;
	FEE_RTOS_struct.H_PES.PES[0] = 0xFF;
	FEE_RTOS_struct.H_PES.PES[1] = 0xFF;
	HAL_UART_Receive_IT(UartTransmit, &FEE_RTOS_struct.H_PES.RX_Data[0], 1);
}

void FEE_PES_Check_Connect(void){
	static uint8_t fistConnected = 0;

	if(FEE_RTOS_struct.H_PES.IsConnected){
		if(!fistConnected){
			// todo: Beep to warning
			for(uint8_t i_bz= 0; i_bz < 2; i_bz ++){
			HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 1);
			osDelay(200);
			HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 0);
			osDelay(200);
			}
			fistConnected = 1;
		}
		FEE_RTOS_struct.H_PES.IsConnected = 0;
	}
	else{
		if(xTaskGetTickCount() - FEE_RTOS_struct.H_PES.Timeout >= DISCONNETC_TIMEOUT){
			// Reconnect
			HAL_UART_Receive_IT(UartTransmit, &FEE_RTOS_struct.H_PES.RX_Data[0], 1);
			fistConnected=0;
            // todo: Beep to warning
//			HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 1);
//			osDelay(200);
//			HAL_GPIO_WritePin(BUZZER_GPIO_Port, BUZZER_Pin, 0);
//			osDelay(200);
		}
	}
}

void pes_uart_event_handle(void){
	static uint8_t byHeadIsTrue = 0;
	static uint8_t i_pes = 0;
	static uint8_t pesBuff[7];

	if(FEE_RTOS_struct.H_PES.RX_Data[0] == 'F' ){
		byHeadIsTrue = 1;
		i_pes = 0;
	}
	else{
		if(byHeadIsTrue){
			pesBuff[i_pes++] = FEE_RTOS_struct.H_PES.RX_Data[0];
			if(i_pes >= 6){
				FEE_RTOS_struct.H_PES.PES[0] = pesBuff[0];
				FEE_RTOS_struct.H_PES.PES[1] = pesBuff[1];
                FEE_RTOS_struct.H_PES.Analog = pesBuff[2];
				FEE_RTOS_struct.H_PES.US[3] = pesBuff[3];
				FEE_RTOS_struct.H_PES.US[2] = pesBuff[4];
				FEE_RTOS_struct.H_PES.US[1] = pesBuff[5];
				
				/*pesBuff[6] = 0xFF; // Khong dung den*/
				i_pes = 0;
				byHeadIsTrue = 0;
				FEE_RTOS_struct.H_PES.IsConnected = 1;
				FEE_RTOS_struct.H_PES.Timeout = xTaskGetTickCount();

				if(FEE_RTOS_struct.H_PES.PES[1] == 0xF5)
				{
					HAL_NVIC_SystemReset();
				}
				// TODO: Check khoa DC
			}
		}
	}
	HAL_UART_Receive_IT(UartTransmit, &FEE_RTOS_struct.H_PES.RX_Data[0], 1);
}
/*
 * @brief Send and printf to line 1 or line 2 of SSD1306 Oled.
 * @params line 1 or 2, default 1.
 */

void pesPrintf(uint8_t line, const char* pString, ...){
	uint8_t frame[20] = {0, };
	uint8_t StrBuff[15] = {0, };
	sprintf((char*)&frame[0], "FEE%d%.2d",line, strlen(pString));
	va_list ap;
	va_start(ap, pString);
	vsnprintf((char*)&StrBuff[0], sizeof(StrBuff), pString, ap);
	va_end(ap);

	memcpy(&frame[6], StrBuff, strlen(pString));
	HAL_UART_Transmit(UartTransmit, frame, 11 + strlen(pString), 1000);
}

/*
 * @brief Clear full SSD1306 Oled screen.
 * @param
 */

void pesMonitorClear(void){
	uint8_t frame[3] = {'D', 'E', 'L'};
	HAL_UART_Transmit(UartTransmit, frame, sizeof(frame), 200);
}
