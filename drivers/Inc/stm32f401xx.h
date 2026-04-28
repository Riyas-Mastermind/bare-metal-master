/*
 * stm32401xx.h
 *
 *  Created on: Apr 27, 2026
 *      Author: riyas
 */

#ifndef INC_STM32F401XX_H_
#define INC_STM32F401XX_H_

#include <stdint.h>

#define __vo volatile

/*Memory Address Mapping*/

#define FLASH_BASEADDR     				0x08000000U
#define SRAM1_BASEADDR     				0x20000000U  //96Kb SRAM1
#define ROM_BASEADDR                	0x1FFF0000U
#define SRAM                        	SRAM1_BASEADDR

/*BUS address Mapping*/

#define PERIPH_BASEADDR					0x40000000U
#define APB1PERIPH_BASEADDR				PERIPH_BASEADDR
#define APB2PERIPH_BASEADDR				0x40010000U
#define AHB1PERIPH_BASEADDR				0x40020000U
#define AHB2PERIPH_BASEADDR				0x50000000U

/*AHP1 Bus line for peripherals*/

#define GPIOA_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR					(AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR 					(AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOH_BASEADDR					(AHB1PERIPH_BASEADDR + 0x1C00)
#define RCC_BASEADDR					(AHB1PERIPH_BASEADDR + 0x3800)

/*APB1 Bus line for peripherals*/

#define I2C1_BASEADDR					(APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR					(APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR					(APB1PERIPH_BASEADDR + 0x5C00)
#define SPI2_BASEADDR					(APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR					(APB1PERIPH_BASEADDR + 0x3C00)
#define USART2_BASEADDR					(APB1PERIPH_BASEADDR + 0x4400)

/*APB2 Bus line for peripherals*/

#define EXTI_BASEADDR 					(APB2PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR					(APB2PERIPH_BASEADDR + 0x3800)
#define SPI1_BASEADDR 					(APB2PERIPH_BASEADDR + 0x3000)
#define SPI4_BASEADDR					(APB2PERIPH_BASEADDR + 0x3400)
#define USART1_BASEADDR 				(APB2PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR					(APB2PERIPH_BASEADDR + 0x1400)


/***************Periph reg define****************/

typedef struct
{
	__vo uint32_t MODER;        	 	//GPIO port mode register: 0x00
	__vo uint32_t OTYPER;		     	//GPIO port output type register: 0x04
	__vo uint32_t OSPEEDR;			 	//GPIO port output speed register: 0x08
	__vo uint32_t PUPDR;			 	//GPIO port pull-up/pull-down register: 0x0C
	__vo uint32_t IDR;				 	//GPIO port input data register: 0x10
	__vo uint32_t ODR;			     	//GPIO port output data register: 0x14
	__vo uint32_t BSRR;					//GPIO port bit set/reset register: 0x18
	__vo uint32_t LCKR;				 	//GPIO port configuration lock register: 0x1C
	__vo uint32_t AFR[2];			 	//GPIO alternate function low/high register; AFR --> [0] Low reg is 0x20; AFR --> [1] High reg is 0x24;
} GPIO_RegDef_t;


typedef struct
{
	__vo uint32_t CR;					//RCC clock control register: 0x00
	__vo uint32_t PLLCFGR;				//RCC PLL configuration register: 0x04
	__vo uint32_t CFGR;					//RCC clock configuration register: 0x08
	__vo uint32_t CIR;					//RCC clock interrupt register: 0x0C
	__vo uint32_t AHB1RSTR;				//RCC AHB1 peripheral reset register: 0x10
	__vo uint32_t AHB2RSTR;				//RCC AHB2 peripheral reset register: 0x14
	uint32_t Reserved0 [2]; 			//Reserved: 0x18 - 0x1C
	__vo uint32_t APB1RSTR;				//RCC APB1 peripheral reset register: 0x20
	__vo uint32_t APB2RSTR;				//RCC APB2 peripheral reset register: 0x24
	uint32_t Reserved1 [2];				//Reserved: 0x28 - 0x2C
	__vo uint32_t AHB1ENR;				//RCC AHB1 peripheral clock enable register: 0x30
	__vo uint32_t AHB2ENR;				//RCC AHB2 peripheral clock enable register: 0x34
	uint32_t Reserved2 [2];				//Reserved: 0x38 - 0x3C
	__vo uint32_t APB1ENR;				//RCC APB1 peripheral clock enable register: 0x40
	__vo uint32_t APB2ENR;				//RCC APB2 peripheral clock enable register: 0x44
	uint32_t Reserved3 [2];				//Reserved: 0x48 - 0x4C
	__vo uint32_t AHB1LPENR;			//RCC AHB1 peripheral clock enable in low power mode register: 0x50
	__vo uint32_t AHB2LPENR;			//RCC AHB2 peripheral clock enable in low power mode register: 0x54
	uint32_t Reserved4 [2];				//Reserved: 0x58 - 0x5C
	__vo uint32_t APB1LPENR;			//RCC APB1 peripheral clock enable in low power mode register: 0x60
	__vo uint32_t APB2LPENR;			//RCC APB2 peripheral clock enabled in low power mode register: 0x64
	uint32_t Reserved5 [2];				//Reserved: 0x68 - 0x6C
	__vo uint32_t BDCR;					//RCC Backup domain control register: 0x70
	__vo uint32_t CSR;					//RCC clock control & status register: 0x74
	uint32_t Reserved6 [2];				//Reserved: 0x78 - 0x7C
	__vo uint32_t SSCGR;				//RCC spread spectrum clock generation register: 0x80
	__vo uint32_t PLLI2SCFGR;			//RCC PLLI2S configuration register: 0x84
	uint32_t Reserved7;					//Reserved: 0x88
	__vo uint32_t DCKCFGR;				//RCC Dedicated Clocks Configuration Register: 0x8C

} RCC_RegDef_t;


/*
 * peripheral definitions (Peripheral base addresses typecasted to xx_RegDef_t)
 */

#define GPIOA							((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB							((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC							((GPIO_RegDef_t*)GPIOC_BASEADDR)
#define GPIOD							((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE							((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOH							((GPIO_RegDef_t*)GPIOH_BASEADDR)
#define RCC								((RCC_RegDef_t*)RCC_BASEADDR)

/*
 * Clock Enable Macro for GPIOx Peripherals
 */

#define GPIOA_PCLK_EN()					(RCC -> AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()					(RCC -> AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()					(RCC -> AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()					(RCC -> AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()					(RCC -> AHB1ENR |= (1 << 4))
#define GPIOH_PCLK_EN()					(RCC -> AHB1ENR |= (1 << 7))

/*
 * Clock Enable Macro for I2Cx Peripherals
 */

#define I2C1_PCLK_EN()					(RCC -> APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()					(RCC -> APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()					(RCC -> APB1ENR |= (1 << 23))

/*
 * Clock Enable Macro for SPIx Peripherals
 */

#define SPI1_PCLK_EN()					(RCC -> APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()					(RCC -> APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()					(RCC -> APB1ENR |= (1 << 15))
#define SPI4_PCLK_EN()					(RCC -> APB2ENR |= (1 << 13))

/*
 * Clock Enable Macro for USARTx Peripherals
 */

#define USART1_PCLK_EN()				(RCC -> APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()				(RCC -> APB1ENR |= (1 << 17))
#define USART6_PCLK_EN()				(RCC -> APB2ENR |= (1 << 5))

/*
 * Clock Enable Macro for SYSCFG Peripherals
 */

#define SYSCFG_PCLK_EN()				(RCC -> APB2ENR |= (1 << 14))

/*
 * Clock Disable Macro for GPIOx Peripherals
 */

#define GPIOA_PCLK_DI()					(RCC -> AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()					(RCC -> AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()					(RCC -> AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()					(RCC -> AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()					(RCC -> AHB1ENR &= ~(1 << 4))
#define GPIOH_PCLK_DI()					(RCC -> AHB1ENR &= ~(1 << 7))

/*
 * Clock Disable Macro for I2Cx Peripherals
 */

#define I2C1_PCLK_DI()					(RCC -> APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()					(RCC -> APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()					(RCC -> APB1ENR &= ~(1 << 23))

/*
 * Clock Disable Macro for SPIx Peripherals
 */

#define SPI1_PCLK_DI()					(RCC -> APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()					(RCC -> APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()					(RCC -> APB1ENR &= ~(1 << 15))
#define SPI4_PCLK_DI()					(RCC -> APB2ENR &= ~(1 << 13))

/*
 * Clock Disable Macro for USARTx Peripherals
 */

#define USART1_PCLK_DI()				(RCC -> APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()				(RCC -> APB1ENR &= ~(1 << 17))
#define USART6_PCLK_DI()				(RCC -> APB2ENR &= ~(1 << 5))

/*
 * Clock Disable Macro for SYSCFG Peripherals
 */

#define SYSCFG_PCLK_DI()				(RCC -> APB2ENR &= ~(1 << 14))

/*
 * Macros for reset GPIOx peripherals
 */

#define GPIOA_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1 << 0)); (RCC -> AHB1RSTR &= ~(1 << 0)); } while(0)
#define GPIOB_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1 << 1)); (RCC -> AHB1RSTR &= ~(1 << 1)); } while(0)
#define GPIOC_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1 << 2)); (RCC -> AHB1RSTR &= ~(1 << 2)); } while(0)
#define GPIOD_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1 << 3)); (RCC -> AHB1RSTR &= ~(1 << 3)); } while(0)
#define GPIOE_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1 << 4)); (RCC -> AHB1RSTR &= ~(1 << 4)); } while(0)
#define GPIOH_REG_RESET()				do{ (RCC -> AHB1RSTR |= (1 << 7)); (RCC -> AHB1RSTR &= ~(1 << 7)); } while(0)

//some generic macros

#define ENABLE                          1
#define DISABLE                         0
#define SET                             ENABLE
#define RESET                           DISABLE
#define GPIO_PIN_SET					SET
#define GPIO_PIN_RESET					RESET

//driver file include
#include <stm32f401xx_gpio_driver.h>

#endif /* INC_STM32F401XX_H_ */
