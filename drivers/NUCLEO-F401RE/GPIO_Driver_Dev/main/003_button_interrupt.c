/*
 * 003_button_interrupt.c
 *
 *  Created on: Apr 30, 2026
 *      Author: riyas
 */


#include <stm32f401xx.h>
#include <string.h>

#define HIGH 				0		// As per STM32f401RE button will be [1] is Low and [0] is High when the button statues
#define BTN_PRESSED 		HIGH

void delay(void)
{
	for (uint32_t i = 0; i < 500000/2; i++);
}


int main(void)
{
	GPIO_Handle_t GPIO_LED, GPIO_BUTTON;

	memset(&GPIO_LED,0,sizeof(GPIO_LED));
	memset(&GPIO_BUTTON,0,sizeof(GPIO_LED));

	//LED configure
	GPIO_LED.pGPIOx = GPIOA;
	GPIO_LED.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	GPIO_LED.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	GPIO_LED.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	GPIO_LED.GPIO_PinConfig.GPIO_PinOPtype = GPIO_OP_TYPE_PP;
	GPIO_LED.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PerClkControl(GPIOA, ENABLE);

	GPIO_Init(&GPIO_LED);

	//button configure
	GPIO_BUTTON.pGPIOx = GPIOC;
	GPIO_BUTTON.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	GPIO_BUTTON.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	GPIO_BUTTON.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_BUTTON.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PerClkControl(GPIOC, ENABLE);

	GPIO_Init(&GPIO_BUTTON);

	GPIO_WriteToOutputPin(GPIOC,GPIO_PIN_NO_13,GPIO_PIN_RESET);
	//IRQ Configurations
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10, NVIC_IRQ_PRIO15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10, ENABLE);

	while(1);
}

void EXTI15_10_IRQHandler(void)
{
	delay();
	GPIO_IRQHandling(GPIO_PIN_NO_13);

	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);

}

