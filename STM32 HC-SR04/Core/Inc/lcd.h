/*
 * lcd.h
 *
 *  Created on: Nov 10, 2022
 *      Author: Usman
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_

#define	LCD_SOFT_RST		0x30
#define	LCD_4BIT_MODE		0x20
#define	LCD_DISP_CLR		0x01
#define	LCD_CONFIG			0x28
#define	LCD_HOME			0x02
#define	LCD_ENTRYMODE		0x06
#define	LCD_DISP_CMD		0x08
#define	LCD_DISP_OFF		0x00
#define	LCD_DISP_ON			0x04
#define	LCD_CUR_ON			0x02
#define	LCD_CUR_OFF			0x00
#define	LCD_BLINK_ON		0x01
#define	LCD_BLINK_OFF		0x00
#define	LCD_CUR_L			0x10
#define	LCD_CUR_R			0x14
#define	LCD_DISP_L			0x18
#define	LCD_DISP_R			0x1C

#define	LCD_DATA_PORT		GPIOA


void LCD_Init_4Bit(void);
void LCD_Command(uint8_t Cmd);
void LCD_Text(uint8_t* Dat, uint16_t Len);
void LCD_Send_4Bit(uint8_t Dat, uint8_t RS_Pin);
void LCD_Cursor(uint8_t Line, uint8_t Col);
void LCD_Cursor_ONOFF(uint8_t OnOff);

#endif /* INC_LCD_H_ */
