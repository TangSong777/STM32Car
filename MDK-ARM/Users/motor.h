#ifndef __MOTOR_H_
#define __MOTOR_H_

#include "stm32f1xx_hal.h"
#include "main.h"
#include "tim.h"

#define defaultspeed 70

void motor_leftspeed(int8_t speed);
void motor_rightspeed(int8_t speed);
void motor_stop();
void motor_speed(int8_t leftspeed,int8_t rightspeed);
void motor_gostraight(int8_t speed);
void motor_turnleft(int8_t speed);
void motor_turnright(int8_t speed);
void motor_spinclockwise(int8_t speed);
void motor_spinanticlockwise(int8_t speed);
#endif /* __MOTOR_H_ */