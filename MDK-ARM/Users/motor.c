#include "motor.h"

void motor_leftspeed(int8_t speed)
{
	if(speed>0)
	{
		HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,GPIO_PIN_RESET);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,speed);
	}
	else if(speed==0)
	{
		HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,GPIO_PIN_RESET);
	}
	else 
	{
		HAL_GPIO_WritePin(AIN1_GPIO_Port,AIN1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(AIN2_GPIO_Port,AIN2_Pin,GPIO_PIN_SET);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_2,-speed);
	}
}

void motor_rightspeed(int8_t speed)
{
	if(speed>0)
	{
		HAL_GPIO_WritePin(BIN1_GPIO_Port,BIN1_Pin,GPIO_PIN_SET);
		HAL_GPIO_WritePin(BIN2_GPIO_Port,BIN2_Pin,GPIO_PIN_RESET);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,speed);
	}
	else if(speed==0)
	{
		HAL_GPIO_WritePin(BIN1_GPIO_Port,BIN1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BIN2_GPIO_Port,BIN2_Pin,GPIO_PIN_RESET);
	}
	else 
	{
		HAL_GPIO_WritePin(BIN1_GPIO_Port,BIN1_Pin,GPIO_PIN_RESET);
		HAL_GPIO_WritePin(BIN2_GPIO_Port,BIN2_Pin,GPIO_PIN_SET);
		__HAL_TIM_SET_COMPARE(&htim2,TIM_CHANNEL_3,-speed);
	}
}

void motor_stop()
{
	motor_leftspeed(0);
	motor_rightspeed(0);
}
void motor_speed(int8_t leftspeed,int8_t rightspeed)
{
	motor_leftspeed(leftspeed);
	motor_rightspeed(rightspeed);
}

void motor_gostraight(int8_t speed)
{
	motor_leftspeed(speed);
	motor_rightspeed(speed);
}

void motor_turnleft(int8_t speed)
{
	motor_leftspeed(speed);
	motor_rightspeed(0);
}

void motor_turnright(int8_t speed)
{
	motor_leftspeed(0);
	motor_rightspeed(speed);
}

void motor_spinclockwise(int8_t speed)
{
	motor_leftspeed(speed);
	motor_rightspeed(-speed);
}

void motor_spinanticlockwise(int8_t speed)
{
	motor_leftspeed(-speed);
	motor_rightspeed(speed);
}