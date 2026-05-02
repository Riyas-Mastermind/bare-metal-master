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

/***********************************************************START: Processor Specific Details************************************************************************************/
/*
 * ARM Cortex M4 Processor NVIC ISERx register addresses
 */

#define NVIC_ISER0						((__vo uint32_t*)0xE000E100)
#define NVIC_ISER1						((__vo uint32_t*)0xE000E104)
#define NVIC_ISER2						((__vo uint32_t*)0xE000E108)
#define NVIC_ISER3						((__vo uint32_t*)0xE000E10C)


/*
 * ARM Cortex M4 Processor NVIC ICERx register addresses
 */

#define NVIC_ICER0						((__vo uint32_t*)0xE000E180)
#define NVIC_ICER1						((__vo uint32_t*)0xE000E184)
#define NVIC_ICER2						((__vo uint32_t*)0xE000E188)
#define NVIC_ICER3						((__vo uint32_t*)0xE000E18C)

/*
 * ARM Cortex M4 Processor Priority Register Address Calculation
 */

#define NVIC_PR_BASEADDR				((__vo uint32_t*)0xE000E400)

/*
 * ARM Cortex M4 Processor number of priority bits implemented in Priority Register
 */
#define NO_PR_BITS_IMPLEMENTED			4


/***********************************************************START: MCU Specific Details**************************************************************************************/

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
 * peripheral register definition structure for EXIT
 */
typedef struct
{
	__vo uint32_t IMR;					//Interrupt mask register: 0x00
	__vo uint32_t EMR;					//Event mask register:0x04
	__vo uint32_t RTSR;					//Rising trigger selection register: 0x08
	__vo uint32_t FTSR;					//Falling trigger selection register: 0x0C
	__vo uint32_t SWIER;				//Software interrupt event register: 0x10
	__vo uint32_t PR;					//Pending register: 0x14

} EXTI_RegDef_t;

/*
 * peripheral register definition structure for SYSCFG_EXTICR
 */

typedef struct{
	__vo uint32_t MEMRMP;				//SYSCFG memory remap register: 0x00
	__vo uint32_t PMC;					//SYSCFG peripheral mode configuration register: 0x04
	__vo uint32_t EXTICR[4];			//SYSCFG external interrupt configuration register 1: 0x08 - 0x14
	uint32_t Reserved[2];				//Reserved register: 0x1C
	__vo uint32_t CMPCR;				//Compensation cell control register: 0x20
}SYSCFG_RegDef_t;

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
#define EXTI							((EXTI_RegDef_t*)EXTI_BASEADDR)
#define SYSCFG							((SYSCFG_RegDef_t*)SYSCFG_BASEADDR)
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

/*
 * returns port code for given GPIOx base address
 */
#define GPIO_BASEADDR_TO_CODE(x)      ( (x == GPIOA) ? 0 :\
                                        (x == GPIOB) ? 1 :\
                                        (x == GPIOC) ? 2 :\
                                        (x == GPIOD) ? 3 :\
                                        (x == GPIOE) ? 4 :\
                                        (x == GPIOH) ? 7 : 0)

/*
 * IRQ (Interrupt Request) Number of STM32F401x MCU
 */
#define IRQ_NO_EXTI0					6
#define IRQ_NO_EXTI1					7
#define IRQ_NO_EXTI2					8
#define IRQ_NO_EXTI3					9
#define IRQ_NO_EXTI4					10
#define IRQ_NO_EXTI9_5					23
#define IRQ_NO_EXTI15_10				40
#define IRQ_NO_EXTI16					1
#define IRQ_NO_EXTI17					41
#define IRQ_NO_EXTI18					42
#define IRQ_NO_EXTI21					2
#define IRQ_NO_EXTI22					3


/*
 * NVIC Priority Macros
 */
#define NVIC_IRQ_PRIO0					0
#define NVIC_IRQ_PRIO1					1
#define NVIC_IRQ_PRIO2					2
#define NVIC_IRQ_PRIO3					3
#define NVIC_IRQ_PRIO4					4
#define NVIC_IRQ_PRIO5					5
#define NVIC_IRQ_PRIO6					6
#define NVIC_IRQ_PRIO7					7
#define NVIC_IRQ_PRIO8					8
#define NVIC_IRQ_PRIO9					9
#define NVIC_IRQ_PRIO10					10
#define NVIC_IRQ_PRIO11					11
#define NVIC_IRQ_PRIO12					12
#define NVIC_IRQ_PRIO13					13
#define NVIC_IRQ_PRIO14					14
#define NVIC_IRQ_PRIO15					15


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
