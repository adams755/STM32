
#include "main.h"
#include "stm32f1xx.h"

//we will switch the clock source to HS.
int main(void)
{
	RCC_TypeDef *pRCC;
	pRCC = RCC;

	pRCC->CFGR |= (1<<26); // liga a saiada MCO para o sysclock PA8

	//1. turn on the HSE Oscillator
	pRCC -> CR |= (1<<16);

	//2. wit until the HSE become stable.
	while ( !(pRCC->CR & (1<<17)));


	//3. Select HSE as the system clock
	pRCC->CFGR &= ~(0x3<<0);
	pRCC->CFGR |= (0x01 <<0);



	return 0;
}
