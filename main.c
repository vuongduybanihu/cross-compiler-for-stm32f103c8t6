#include "main.h"
//---------------------------KHAI BAO CAC BIEN----------------------------------//
int nhietdo;
char str[20];
//---------------------------HAM MAIN------------------------------------------//

void clock_init();

int main()
	{

	clock_init();
	SystemCoreClockUpdate();
	  Delay_Init(72);	// goi ham khoi tao du lieu cho cac ham delay
		GPIO_Configuration();	// goi ham cau hinh ngo vao ra cho cac PORT
		GPIO_PinRemapConfig (GPIO_Remap_SWJ_JTAGDisable, ENABLE);//bo che do nap JTAGD
		lcd_init();		//goi ham thiet lap LCD
		lcd_msg(1,2,"VUONG DUC DUY");//hien thi chuoi ky tu
		while(1)
		{
			
			nhietdo=(int)(ds18b20_read()*10);
	    Delay_ms(100);
	    sprintf(str,"Nhiet Do %d.%1doC",nhietdo/10,nhietdo%10);
			lcd_msg(2,0,(uint8_t *)str); 
		}
	}

void clock_init()
{
    // Enable HSE and wait until it's ready
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & RCC_CR_HSERDY));

    // Configure Flash wait state and enable prefetch buffer
    FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY_2;

    // Configure PLL
    RCC->CFGR &= ~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL | RCC_CFGR_PPRE1);
    RCC->CFGR |= RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL9 | RCC_CFGR_PPRE1_DIV2;

    // Enable PLL and wait until it's ready
    RCC->CR |= RCC_CR_PLLON;
    while (!(RCC->CR & RCC_CR_PLLRDY));

    // Select PLL as system clock source
    RCC->CFGR &= ~RCC_CFGR_SW;
    RCC->CFGR |= RCC_CFGR_SW_PLL;
    while ((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_PLL);
}

	
	
