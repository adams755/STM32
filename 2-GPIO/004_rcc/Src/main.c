
#include "main.h"
#include "stm32f1xx.h"


int main(void)
{
	ADC_TypeDef *pADC;
	RCC_TypeDef *pRCC;
	GPIO_TypeDef *pGPIO;

	pADC = ADC1;
	pRCC = RCC;
	pGPIO = GPIOA;

	// antes de trocar qualquer informação com algum registrador é preciso iniciar o relogio do periferico
	pRCC -> APB2ENR = pRCC -> APB2ENR | (1<<9);
	pRCC -> APB2ENR = pRCC -> APB2ENR | (1<<2);
	pADC -> CR1 = 0x55;
	pGPIO -> ODR = 0x11;

	return 0;
}
