#include "Bluetooth.h"

/*
放在begin2里面
HAL_UARTEx_ReceiveToIdle_DMA(&huart1, data, sizeof(data));
__HAL_DMA_DISABLE_IT(&hdma_usart1_rx,DMA_IT_HT);
*/

/*示例
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	if(huart == &huart1)
		Bluetooth_scan(Size);
}
*/

uint8_t speed=50;
int judge(uint8_t data[], const char a[], int len)
{
	for (int i = 0; i < len; i++)
	{
		if (data[i] == a[i])
			continue;
		else
			return 0;
	}
	return 1;
}

void Bluetooth_scan(uint16_t Size)
{
	HAL_UART_Transmit_DMA(&huart1, data, Size);
	if(judge(data,"speed",5))
			speed=(data[1]-'0')*100+(data[2]-'0')*10+data[3]-'0';
	if(judge(data,"stop",4))motor_stop();
	if(judge(data,"front",5))motor_gostraight(speed);
	if(judge(data,"left",4))motor_spinclockwise(speed);
	if(judge(data,"right",5))motor_spinanticlockwise(speed);
	if(judge(data,"back",4))motor_gostraight(-speed);
	if(judge(data,"turnl",5))motor_turnleft(speed);
	if(judge(data,"turnr",5))motor_turnright(speed);
	if(judge(data,"antiturnl",9))motor_turnleft(-speed);
	if(judge(data,"antiturnr",9))motor_turnright(-speed);
	if(judge(data,"default",7))speed=80;
	HAL_UARTEx_ReceiveToIdle_DMA(&huart1, data, sizeof(data));
	__HAL_DMA_DISABLE_IT(&hdma_usart1_rx, DMA_IT_HT);
}