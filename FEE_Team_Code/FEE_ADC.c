/*******************************    INCLUDES   ********************************/
#include "FEE_ADC.h"

/**************************    GLOBAL VARIABLES    ****************************/
int pk = 0;


/***************************       FUNCTIONS       ****************************/

void FEE_ADC_Innit(void)
{
		for(pk = 0; pk < 8; pk++)
	{
		FEE_RTOS_struct.H_ADC.DMA_adc_value[pk] = 0;
		FEE_RTOS_struct.H_ADC.adc_value_Raw[pk] = 0;
		FEE_RTOS_struct.H_ADC.adc_value_Volt[pk] = 0;
		FEE_RTOS_struct.H_ADC.adc_value_Result[pk] = 0;	
	}
	
	FEE_RTOS_struct.H_ADC.DMA_done = 0;
}

// luu du lieu tu DMA
void FEE_ADC_Get_Raw(void)
{
	FEE_RTOS_struct.H_ADC.adc_value_Raw[0] = FEE_RTOS_struct.H_ADC.DMA_adc_value[0];
	FEE_RTOS_struct.H_ADC.adc_value_Raw[1] = FEE_RTOS_struct.H_ADC.DMA_adc_value[1];
	FEE_RTOS_struct.H_ADC.adc_value_Raw[2] = FEE_RTOS_struct.H_ADC.DMA_adc_value[2];
	FEE_RTOS_struct.H_ADC.adc_value_Raw[3] = FEE_RTOS_struct.H_ADC.DMA_adc_value[3];
	FEE_RTOS_struct.H_ADC.adc_value_Raw[4] = FEE_RTOS_struct.H_ADC.DMA_adc_value[4];
	FEE_RTOS_struct.H_ADC.adc_value_Raw[5] = FEE_RTOS_struct.H_ADC.DMA_adc_value[5];
	FEE_RTOS_struct.H_ADC.adc_value_Raw[6] = FEE_RTOS_struct.H_ADC.DMA_adc_value[6];
	FEE_RTOS_struct.H_ADC.adc_value_Raw[7] = FEE_RTOS_struct.H_ADC.DMA_adc_value[7];
}

// tinh gia tri dien ap tu gia tri tho
void FEE_ADC_Get_Volt(void)
{
	FEE_RTOS_struct.H_ADC.adc_value_Volt[0] = FEE_RTOS_struct.H_ADC.adc_value_Raw[0] * 3300.0 / 65536.0;
	FEE_RTOS_struct.H_ADC.adc_value_Volt[1] = FEE_RTOS_struct.H_ADC.adc_value_Raw[1] * 3300.0 / 65536.0;
	FEE_RTOS_struct.H_ADC.adc_value_Volt[2] = FEE_RTOS_struct.H_ADC.adc_value_Raw[2] * 3300.0 / 65536.0;
	FEE_RTOS_struct.H_ADC.adc_value_Volt[3] = FEE_RTOS_struct.H_ADC.adc_value_Raw[3] * 3300.0 / 65536.0;
	FEE_RTOS_struct.H_ADC.adc_value_Volt[4] = FEE_RTOS_struct.H_ADC.adc_value_Raw[4] * 3300.0 / 65536.0;
	FEE_RTOS_struct.H_ADC.adc_value_Volt[5] = FEE_RTOS_struct.H_ADC.adc_value_Raw[5] * 3300.0 / 65536.0;
	FEE_RTOS_struct.H_ADC.adc_value_Volt[6] = FEE_RTOS_struct.H_ADC.adc_value_Raw[6] * 3300.0 / 65536.0;
	FEE_RTOS_struct.H_ADC.adc_value_Volt[7] = FEE_RTOS_struct.H_ADC.adc_value_Raw[7] * 3300.0 / 65536.0;
}

// tinh toan du lieu tu dien ap do duoc
void FEE_ADC_Get_Result(void)
{
	FEE_RTOS_struct.H_ADC.adc_value_Result[0] = FEE_RTOS_struct.H_ADC.adc_value_Volt[0] * 1000;
	FEE_RTOS_struct.H_ADC.adc_value_Result[1] = FEE_RTOS_struct.H_ADC.adc_value_Volt[1] * 1000;
	FEE_RTOS_struct.H_ADC.adc_value_Result[2] = FEE_RTOS_struct.H_ADC.adc_value_Volt[2] * 1000;
	FEE_RTOS_struct.H_ADC.adc_value_Result[3] = FEE_RTOS_struct.H_ADC.adc_value_Volt[3] * 1000;
	FEE_RTOS_struct.H_ADC.adc_value_Result[4] = FEE_RTOS_struct.H_ADC.adc_value_Volt[4] * 1000;
	FEE_RTOS_struct.H_ADC.adc_value_Result[5] = FEE_RTOS_struct.H_ADC.adc_value_Volt[5] * 1000;
	FEE_RTOS_struct.H_ADC.adc_value_Result[6] = FEE_RTOS_struct.H_ADC.adc_value_Volt[6] * 1000;
	FEE_RTOS_struct.H_ADC.adc_value_Result[7] = FEE_RTOS_struct.H_ADC.adc_value_Volt[7] * 1000;
}


