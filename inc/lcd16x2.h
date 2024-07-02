#ifndef __LCD16x2_H
#define __LCD16x2_H

#ifdef __cplusplus
 extern "C" {
#endif
#include "main.h"	
//----------KHAI BAO CAC HAM CHO LCD16x2.C
/*
	DINH NGHIA CAC CHAN/PORT
*/
#define LCD_PORT	GPIOA
#define EN_LCD_PIN	GPIO_Pin_10
#define RS_LCD_PIN	GPIO_Pin_8
#define RW_LCD_PIN	GPIO_Pin_9

#define DATA_LCD_PORT	GPIOA
#define D0_LCD				GPIO_Pin_0
#define D1_LCD				GPIO_Pin_1
#define D2_LCD				GPIO_Pin_2
#define D3_LCD				GPIO_Pin_3
#define D4_LCD				GPIO_Pin_4
#define D5_LCD				GPIO_Pin_5
#define D6_LCD				GPIO_Pin_6
#define D7_LCD				GPIO_Pin_7
/*
	KHAI B?O C?C H?M CHO LCD
*/
void lcd_data(unsigned char data);
void lcd_cmd(unsigned char data);
void lcd_init(void);
void lcd_send( char str[]);
void lcd_msg(unsigned char line_1_2, unsigned char pos_0_16, char msg[]);
void lcd_clear(void);

#ifdef __cplusplus
}
#endif

#endif



