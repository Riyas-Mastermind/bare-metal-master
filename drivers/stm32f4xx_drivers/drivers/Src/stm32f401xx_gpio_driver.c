/*
 * stm32f401xx_gpio_driver.c
 *
 *  Created on: Apr 27, 2026
 *      Author: riyas
 */


#include <stm32f401xx_gpio_driver.h>


/*****************************************************************************************************************************
*                                               APIs supported by this driver
*                            For more information about the API check the function definitions
******************************************************************************************************************************/


/*
 * Peripheral Clock setup
 */

/**********************************************************************************
 * @fn             --> GPIO_PerClkControl
 *
 * @brief          --> This functions enable or disable peripheral clock for the given GPIO port
 *
 * @param[in]      --> Base address of the GPIO peripheral
 * @param[in]	   --> Enable or Disable macros
 * @param[in]	   --> none
 *
 * @return         --> none
 *
 * @Note           --> none
 *
 */

void GPIO_PerClkControl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI)
{
	if(ENorDI == ENABLE)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}else if (pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}else if (pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}else if (pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}else if (pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}else if (pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
	}
}

/*
 * Init and De-init
 */

void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{

	uint32_t temp = 0;
	//1. configure the mode of GPIO pin

	if (pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//the non-interrupt mode
		temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode << (2 *pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle ->pGPIOx ->MODER &= ~(0x3 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber); //clearing
		pGPIOHandle ->pGPIOx ->MODER |= temp; //setting
	}else
	{
		//this part will code later (interrupt mode)
	}
	temp = 0;

	//2. configure the speed
	temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PinSpeed << (2 *pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle ->pGPIOx ->OSPEEDR &= ~(0x3 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber); //clearing
	pGPIOHandle ->pGPIOx ->OSPEEDR |= temp;

	temp = 0;

	//3. configure the pupd settings
	temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PinPuPdControl << (2 *pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle ->pGPIOx ->PUPDR &= ~(0x3 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber); //clearing
	pGPIOHandle ->pGPIOx ->PUPDR |= temp;

	temp = 0;

	//4. configure the optype
	temp = (pGPIOHandle ->GPIO_PinConfig.GPIO_PinOPtype << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle ->pGPIOx ->OTYPER &= ~(0x1 << pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber); //clearing
	pGPIOHandle ->pGPIOx ->OTYPER |= temp;

	temp = 0;

	//5. configure the alt functionality
	if(pGPIOHandle ->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN)
	{
		//configure the alt function registers
		uint8_t temp1, temp2;

		temp1 = pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber / 8;
		temp2 = pGPIOHandle ->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle ->pGPIOx ->AFR[temp1] &= ~(0xF << (4 * temp2));
		pGPIOHandle ->pGPIOx ->AFR[temp1] |= (pGPIOHandle ->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
	}
}

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{

}

/*
 * Data Read and Write
 */

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

}

uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx)
{

}

void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{

}

void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{

}

void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{

}

/*
 * IRQ Configuration and ISR handling
 */

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI)
{

}

void GPIO_IRQHandling(uint8_t PinNumber)
{

}



