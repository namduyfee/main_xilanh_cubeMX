/*******************************    INCLUDES   ********************************/

#include "FEE_UART.h"

/***************************    GLOBAL VARIABLES   ****************************/

int pi = 0;

/***************************       FUNCTIONS       ****************************/
extern int tem; 

void FEE_UART_Innit(void)
{	
for(pi = 0; pi < 64; pi++)
	{	
		FEE_RTOS_struct.H_UART1.rxBuffer[pi] = 0;
		FEE_RTOS_struct.H_UART2.rxBuffer[pi] = 0;
		FEE_RTOS_struct.H_UART3.rxBuffer[pi] = 0;
		FEE_RTOS_struct.H_Remote.DMA_rxBuffer[pi] = 0;	
		
	}
	
	for(pi = 0; pi < 4; pi++)
	{
		FEE_RTOS_struct.H_UART1.CMD1[pi] = 0;
		FEE_RTOS_struct.H_UART1.CMD2[pi] = 0;
		
		FEE_RTOS_struct.H_UART2.CMD1[pi] = 0;
		FEE_RTOS_struct.H_UART2.CMD2[pi] = 0;
		
		FEE_RTOS_struct.H_UART3.CMD1[pi] = 0;
		FEE_RTOS_struct.H_UART3.CMD2[pi] = 0;
		
		FEE_RTOS_struct.H_Remote.CMD1[pi] = 0;
		FEE_RTOS_struct.H_Remote.CMD2[pi] = 0;
	}
	
	
		FEE_RTOS_struct.H_UART1.RX_size = 0;
		FEE_RTOS_struct.H_UART2.RX_size = 0;
		FEE_RTOS_struct.H_UART3.RX_size = 0;
		FEE_RTOS_struct.H_Remote.RX_size = 0;
		
		FEE_RTOS_struct.H_UART1.RX_Done = 0;
		FEE_RTOS_struct.H_UART2.RX_Done = 0;
		FEE_RTOS_struct.H_UART3.RX_Done = 0;
		FEE_RTOS_struct.H_Remote.RX_Done = 0;
		
		FEE_RTOS_struct.H_UART1.TX_size = 0;
		FEE_RTOS_struct.H_UART2.TX_size = 0;
		FEE_RTOS_struct.H_UART3.TX_size = 0;
		FEE_RTOS_struct.H_Remote.TX_size = 0;
		
		FEE_RTOS_struct.H_UART1.TX_Done = 0;
		FEE_RTOS_struct.H_UART2.TX_Done = 0;
		FEE_RTOS_struct.H_UART3.TX_Done = 0;
		FEE_RTOS_struct.H_Remote.TX_Done = 0;
		
		FEE_RTOS_struct.H_UART1.Disconnect = 0;
		FEE_RTOS_struct.H_UART2.Disconnect = 0;
		FEE_RTOS_struct.H_UART3.Disconnect = 0;
		FEE_RTOS_struct.H_Remote.Disconnect = 0;
}

void FEE_UART_Test(void)
{
	FEE_RTOS_struct.H_UART1.txBuffer[0] = 0x11;
	FEE_RTOS_struct.H_UART1.txBuffer[1] = 0x22;
	FEE_RTOS_struct.H_UART1.txBuffer[2] = 0x33;
	FEE_RTOS_struct.H_UART1.txBuffer[3] = 0x44;
	
	//HAL_UART_Transmit(&huart1, FEE_RTOS_struct.H_UART1.txBuffer, 4, 10); 
	//HAL_UART_Transmit(&huart2, FEE_RTOS_struct.H_UART1.txBuffer, 4, 10); 
	//HAL_UART_Transmit(&huart3, FEE_RTOS_struct.H_UART1.txBuffer, 4, 10); 
}

void send_uart(uint8_t data)
{
	tem = 12; 
	HAL_UART_Transmit(&huart2,&data,1,20);
	tem = 13; 
}
void pid_dc1(uint8_t chieu,uint8_t tocdo)
{
	tem = 9; 
	send_uart((chieu<<7)|1);
	send_uart(tocdo);
	send_uart(255);
	
}
void pid_dc2(uint8_t chieu,uint8_t tocdo)
{
	tem = 10; 
	send_uart((chieu<<7)|2);
	send_uart(tocdo);
	send_uart(255);
}

void pid_dc3(uint8_t chieu,uint8_t tocdo)
{
	tem = 11; 
	send_uart((chieu<<7)|3);
	send_uart(tocdo);
	send_uart(255);
}

//void pid_dc8(uint8_t chieu,uint8_t tocdo)
//{
//	send_uart((chieu<<7)|8);
//	send_uart(tocdo);
//	send_uart(255);
//}

//void pid_dc9(uint8_t chieu,uint8_t tocdo)
//{
//	send_uart((chieu<<7)|9);
//	send_uart(tocdo);
//	send_uart(255);
//}

//void pid_dc10(uint8_t chieu,uint8_t tocdo)
//{
//	send_uart((chieu<<7)|10);
//	send_uart(tocdo);
//	send_uart(255);
//}
