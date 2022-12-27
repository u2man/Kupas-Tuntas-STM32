/*
 * hc_sr04.c
 *
 *  Created on: Dec 26, 2022
 *      Author: Usman
 */




#include "main.h"
#include "tim.h"
#include "hc_sr04.h"

uint16_t PulseWidth;
uint8_t EchoState;


float Get_Distance(void){
	uint16_t timeout;

	//Trigger 10 uSec
	HAL_GPIO_WritePin(TRIGGER_GPIO_Port, TRIGGER_Pin, GPIO_PIN_SET);
	Delay_uSec(10);
	HAL_GPIO_WritePin(TRIGGER_GPIO_Port, TRIGGER_Pin, GPIO_PIN_RESET);

	EchoState=0;
	timeout=0;
	while(!EchoState){
		if(timeout++>2000){
			break;
		}

		HAL_Delay(1);
	}

	return (PulseWidth*0.034)/2;

}

void Delay_uSec(uint32_t uDelay){
	 __HAL_TIM_SET_COUNTER(&htim3,0);

	 while((__HAL_TIM_GET_COUNTER(&htim3)<uDelay)){

	 }
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){

	if(HAL_GPIO_ReadPin(ECHO_GPIO_Port,ECHO_Pin)){
		//Rising
		__HAL_TIM_SET_COUNTER(&htim3,0);
	}
	else{
		//Falling
		PulseWidth = __HAL_TIM_GET_COUNTER(&htim3);
		EchoState=1;
	}
}
