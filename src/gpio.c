#include "main.h"	
#include "gpio.h"


void GPIO_Configuration(void)
{
 GPIO_InitTypeDef GPIO_InitStructure;
  //Enable clock AFIO
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);	
/*==================================PORTB==========================================*/
	//Enable clock GPIOB
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
//_________________________________OUTPUT__________________________________________
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0|GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4|GPIO_Pin_5|GPIO_Pin_6|GPIO_Pin_7|GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10;	//khai bao c?c ch?n LCD      		
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;			// ng? ra kieu day k?o
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		// thiet lap toc do ngo ra cac chan
 GPIO_Init(GPIOA, &GPIO_InitStructure);

 }
void GPIO_SetState(GPIO_TypeDef* GPIOx,uint16_t GPIO_Pin,GPIOMode_TypeDef GPIO_Mode)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin;	         		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOx, &GPIO_InitStructure);
}
/********************************* END OF FILE ********************************/

