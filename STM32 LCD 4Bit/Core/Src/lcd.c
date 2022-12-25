/*
 * lcd.c
 *
 *  Created on: Nov 10, 2022
 *      Author: Usman
 */


#include "main.h"
#include "lcd.h"

void LCD_Init_4Bit(void){

	LCD_Send_4Bit(LCD_SOFT_RST, 0);
	HAL_Delay(5);
	LCD_Send_4Bit(LCD_SOFT_RST, 0);
	HAL_Delay(5);
	LCD_Send_4Bit(LCD_SOFT_RST, 0);
	HAL_Delay(5);
	LCD_Send_4Bit(LCD_4BIT_MODE, 0);
	HAL_Delay(10);

	LCD_Command(LCD_CONFIG);
	LCD_Command(LCD_DISP_CMD|LCD_DISP_OFF);
	LCD_Command(LCD_DISP_CLR);
	LCD_Command(LCD_ENTRYMODE);
	LCD_Command(0x0C);


}

void LCD_Cursor_ONOFF(uint8_t OnOff){

	if(OnOff){
	LCD_Command(LCD_DISP_CMD|LCD_DISP_ON|LCD_CUR_ON|LCD_BLINK_ON);
	}
	else{
		LCD_Command(LCD_DISP_CMD|LCD_DISP_ON|LCD_CUR_OFF);
	}
}

void LCD_Cursor(uint8_t Line, uint8_t Col){
	uint8_t Cmd;

	if(Line==1){
		Cmd = 0x80|Col;
	}
	else{
		Cmd = 0xC0|Col;
	}

	LCD_Command(Cmd);
}

void LCD_Command(uint8_t Cmd){

	LCD_Send_4Bit(Cmd, 0);
	LCD_Send_4Bit(Cmd<<4, 0);
	HAL_Delay(5);
}

void LCD_Text(uint8_t* Dat, uint16_t Len){

	for(int i=0;i<Len;i++){
		LCD_Send_4Bit(Dat[i], 1);
		LCD_Send_4Bit(Dat[i]<<4, 1);

	}
}

void LCD_Send_4Bit(uint8_t Dat, uint8_t RS_Pin){

	LCD_DATA_PORT->ODR = Dat;

	//Pin RS
	HAL_GPIO_WritePin(LCD_RS_GPIO_Port, LCD_RS_Pin, RS_Pin);
	//Pulse Pin E
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_SET);
	HAL_Delay(1);
	HAL_GPIO_WritePin(LCD_E_GPIO_Port, LCD_E_Pin, GPIO_PIN_RESET);
}
