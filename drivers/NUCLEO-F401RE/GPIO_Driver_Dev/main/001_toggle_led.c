/*
 * main.c
 *
 *  Created on: Apr 28, 2026
 *      Author: riyas
 */

#include <stm32f401xx.h>


void delay(void)
{
	for (uint32_t i = 0; i < 500000/2; i++);
}


int main(void)
{
	GPIO_Handle_t GPIO_LED;

	GPIO_LED.pGPIOx = GPIOA;
	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GPIO_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_LED.GPIO_PinConfig.GPIO_PinOPtype = GPIO_OP_TYPE_PP;
	GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PerClkControl(GPIOA, ENABLE);

	GPIO_Init(&GPIO_LED);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		delay();
	}
	return 0;
}

