#ifndef __BLUETOOTH_H_
#define __BLUETOOTH_H_

#include "stm32f1xx_hal.h"
#include "usart.h"
#include "motor.h"

extern uint8_t data[50];
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;

int judge(uint8_t data[], const char a[], int len);
void Bluetooth_scan(uint16_t Size);

#endif /* __BLUETOOTH_H_ */