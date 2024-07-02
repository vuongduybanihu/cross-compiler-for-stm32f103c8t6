#include "lcd16x2.h"


void lcd_data(unsigned char data)
{
	GPIO_SetBits(LCD_PORT,RS_LCD_PIN);
	GPIO_ResetBits(LCD_PORT,RW_LCD_PIN);
	Delay_us(10);
	GPIO_SetBits(LCD_PORT,EN_LCD_PIN);
	Delay_us(5);
	GPIOA->ODR &= 0xff00;
	GPIOA->ODR |= data;
	Delay_us(10);
	GPIO_ResetBits(LCD_PORT,EN_LCD_PIN);
}
void lcd_cmd(unsigned char data)
{
	GPIO_ResetBits(LCD_PORT,RS_LCD_PIN);
	GPIO_ResetBits(LCD_PORT,RW_LCD_PIN);
	Delay_us(10);
	GPIO_SetBits(LCD_PORT,EN_LCD_PIN);
	Delay_us(5);
	GPIOA->ODR &= 0xff00;
	GPIOA->ODR |= data;
	Delay_us(10);
	GPIO_ResetBits(LCD_PORT,EN_LCD_PIN);
}

void lcd_init(void)
{
	Delay_ms(20);
	lcd_cmd(0x3C); // 8 bit communication mode / 2 lines
	Delay_ms(5);
	lcd_cmd(0x0C); // Display ON
	Delay_ms(5);
	lcd_cmd(0x01); // Clear Display
	Delay_ms(5);
	lcd_cmd(0x02); // Get back to initial address
	Delay_ms(5);
}
void lcd_send( char str[])
{
	int i = 0;
		while(str[i])
		{
			lcd_data(str[i]);
			i++;
			Delay_us(100);
		}

}

void lcd_msg(unsigned char line_1_2, unsigned char pos_0_16, char msg[])
{
	short pos = 0;
	if(line_1_2==1)
	{
		pos = 0;
	}
	else if(line_1_2==2)
	{
		pos = 0x40;
	}
	lcd_cmd(0x80 +pos + pos_0_16);
	Delay_us(100);
	lcd_send(msg);
}

void lcd_clear(void)
{
    lcd_cmd(0x01);// goi lenh dieu khien LCD
    Delay_ms(5);
}



