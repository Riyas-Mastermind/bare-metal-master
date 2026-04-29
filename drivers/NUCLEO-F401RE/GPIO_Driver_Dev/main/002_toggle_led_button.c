/*
 * main.c
 *
 *  Created on: Apr 29, 2026
 *      Author: riyas
 */

#include <stm32f401xx.h>

#define HIGH 				DISABLE
#define BTN_PRESSED 		HIGH

void delay(void)
{
	for (uint32_t i = 0; i < 500000/2; i++);
}


int main(void)
{
	GPIO_Handle_t GPIO_LED, GPIO_BUTTON;

	//LED configure
	GPIO_LED.pGPIOx = GPIOA;
	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GPIO_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_LED.GPIO_PinConfig.GPIO_PinOPtype = GPIO_OP_TYPE_PP;
	GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PerClkControl(GPIOA, ENABLE);

	GPIO_Init(&GPIO_LED);

	//button configure
	GPIO_LED.pGPIOx = GPIOC;
	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIO_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PerClkControl(GPIOC, ENABLE);

	GPIO_Init(&GPIO_BUTTON);

	while(1)
	{
		if(GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == BTN_PRESSED)
		{
			delay();
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		}
	}
	return 0;
}

