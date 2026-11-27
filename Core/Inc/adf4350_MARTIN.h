/***************************************************************************//**
 *   @file   adf4350.h
 *   @brief  Header file of ADF4350 Driver.
 *   @author DBogdan (dragos.bogdan@analog.com), Modified by A. MARTIN
********************************************************************************
 * Copyright 2012-2015(c) Analog Devices, Inc.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
*******************************************************************************/

#ifndef ADF4350_H_
#define ADF4350_H_

#include "gpio.h"
#include "spi.h"

/* Channels */
#define ADF4350_RX_CHANNEL	0
#define ADF4350_TX_CHANNEL	1

/* Registers */
#define ADF4350_REG0	0
#define ADF4350_REG1	1
#define ADF4350_REG2	2
#define ADF4350_REG3	3
#define ADF4350_REG4	4
#define ADF4350_REG5	5

/* REG0 Bit Definitions */
#define ADF4350_REG0_FRACT(x)					(((x) & 0xFFF) << 3)
#define ADF4350_REG0_INT(x)						(((x) & 0xFFFF) << 15)

/* REG1 Bit Definitions */
#define ADF4350_REG1_MOD(x)						(((x) & 0xFFF) << 3)
#define ADF4350_REG1_PHASE(x)					(((x) & 0xFFF) << 15)
#define ADF4350_REG1_PRESCALER					(1 << 27)

/* REG2 Bit Definitions */
#define ADF4350_REG2_COUNTER_RESET_EN			(1 << 3)
#define ADF4350_REG2_CP_THREESTATE_EN			(1 << 4)
#define ADF4350_REG2_POWER_DOWN_EN				(1 << 5)
#define ADF4350_REG2_PD_POLARITY_POS			(1 << 6)
#define ADF4350_REG2_LDP_6ns					(1 << 7)
#define ADF4350_REG2_LDP_10ns					(0 << 7)
#define ADF4350_REG2_LDF_FRACT_N				(0 << 8)
#define ADF4350_REG2_LDF_INT_N					(1 << 8)
#define ADF4350_REG2_CHARGE_PUMP_CURR_uA(x)		(((((x)-312) / 312) & 0xF) << 9)
#define ADF4350_REG2_DOUBLE_BUFF_EN				(1 << 13)
#define ADF4350_REG2_10BIT_R_CNT(x)				((x) << 14)
#define ADF4350_REG2_RDIV2_EN					(1 << 24)
#define ADF4350_REG2_RMULT2_EN					(1 << 25)
#define ADF4350_REG2_MUXOUT(x)					((x) << 26)
#define ADF4350_REG2_NOISE_MODE(x)				(((x) & 0x3) << 29)

/* REG3 Bit Definitions */
#define ADF4350_REG3_12BIT_CLKDIV(x)			((x) << 3)
#define ADF4350_REG3_12BIT_CLKDIV_MODE(x)		((x) << 15)
#define ADF4350_REG3_12BIT_CSR_EN				(1 << 18)
//#define ADF4351_REG3_CHARGE_CANCELLATION_EN		(1 << 21)
//#define ADF4351_REG3_ANTI_BACKLASH_3ns_EN		(1 << 22)
//#define ADF4351_REG3_BAND_SEL_CLOCK_MODE_HIGH	(1 << 23)

/* REG4 Bit Definitions */
#define ADF4350_REG4_OUTPUT_PWR(x)				((x) << 3)
#define ADF4350_REG4_RF_OUT_EN					(1 << 5)
#define ADF4350_REG4_AUX_OUTPUT_PWR(x)			((x) << 6)
#define ADF4350_REG4_AUX_OUTPUT_EN				(1 << 8)
#define ADF4350_REG4_AUX_OUTPUT_FUND			(1 << 9)
#define ADF4350_REG4_AUX_OUTPUT_DIV				(0 << 9)
#define ADF4350_REG4_MUTE_TILL_LOCK_EN			(1 << 10)
#define ADF4350_REG4_VCO_PWRDOWN_EN				(1 << 11)
#define ADF4350_REG4_8BIT_BAND_SEL_CLKDIV(x)	((x) << 12)
#define ADF4350_REG4_RF_DIV_SEL(x)				((x) << 20)
#define ADF4350_REG4_FEEDBACK_DIVIDED			(0 << 23)	// FEEDBACK_DIVIDED ou FEEDBACK_FUND
#define ADF4350_REG4_FEEDBACK_FUND				(1 << 23)

/* REG5 Bit Definitions */
#define ADF4350_REG5_LD_PIN_MODE_LOW			(0 << 22)
#define ADF4350_REG5_LD_PIN_MODE_DIGITAL		(1 << 22)
#define ADF4350_REG5_LD_PIN_MODE_HIGH			(3 << 22)

/* Specifications */
#define ADF4350_MAX_OUT_FREQ		4400000000ULL /* Hz */
#define ADF4350_MIN_OUT_FREQ		34375000 /* Hz */
#define ADF4350_MIN_VCO_FREQ		2200000000ULL /* Hz */
#define ADF4350_MAX_FREQ_45_PRESC	3000000000ULL /* Hz */
#define ADF4350_MAX_FREQ_PFD		32000000 /* Hz */
#define ADF4350_MAX_BANDSEL_CLK		125000 /* Hz */
#define ADF4350_MAX_FREQ_REFIN		250000000 /* Hz */
#define ADF4350_MAX_MODULUS			4095
#define ADF4350_MAX_R_CNT			1023

/* Default register values*/
/* Register 0
 * INTEGER VALUE : Calculated
 * FRACTIONAL VALUE : Calculated
 */
#define REGISTER0_DEFAULT			ADF4350_REG0_INT(133) \
									+ ADF4350_REG0_FRACT(7) \


/* Register 1
 * PRESCALER : 8/9 (Cf ADISim PLL)		4/5 (3GHz max output)
 * PHASE VALUE : 1 (recommended)
 * MODULUS VALUE : Calculated
 */
#define REGISTER1_DEFAULT			ADF4350_REG1_PHASE(1) \
									+ ADF4350_REG1_MOD(13) \
									+ ADF4350_REG1_PRESCALER

/* Register 2
 * NOISE MODE : LOW NOISE MODE (to justify)
 * MUX_OUT : R Divider (for tests)
 * Reference doubler disabled (REFin directly to R-counter)
 * RDIV2 disabled (divide-by-2 toggle flip-flop between the R counter and PFD disabled)
 * R-counter DRB = 1 (no division)
 * DOUBLE BUFFER disabled
 * Charge pump current : 5000 (to justify)
 * Digital lock detect : fractional–N (to justify)
 * Lock Detect Precision : 6ns (to justify)
 * Phase Detector Polarity : positive (passive loop filter)
 * Power down : disabled
 * Charge Pump Three-State : disabled (To justify)
 * Counter reset : disabled
 */
#define REGISTER2_DEFAULT			ADF4350_REG2_NOISE_MODE(0) \
									+ ADF4350_REG2_MUXOUT(6) \
									+ ADF4350_REG2_10BIT_R_CNT(1) \
									+ ADF4350_REG2_CHARGE_PUMP_CURR_uA(5000) \
									+ ADF4350_REG2_LDP_6ns \
									+ ADF4350_REG2_PD_POLARITY_POS \
									//+ ADF4350_REG2_RDIV2_EN
									//+ ADF4350_REG2_LDF_INT_N
									//+ ADF4350_REG2_RMULT2_EN



/* Register 3
 *	CYCLE SLIP REDUCTION OFF
 *	CLOCK DIVIDER OFF (To justify)
 *	CLOCK DIVIDER VALUE 0 (not used, to justify)
 */
#define REGISTER3_DEFAULT			0 //ADF4350_REG3_12BIT_CLKDIV_MODE(2)
									//+ ADF4350_REG3_12BIT_CLKDIV(4)


/* Register 4
 *  Feedback from the VCO directly (not output dividers)
 *	Divider Select : 4
 *	Band select clock divider : Calculated
 *	VCO power up
 *	Mute Till Lock Detect : OFF (output even if not locked)
 *	AUX Output OFF
 *	RF Output ON
 *	RF output power : -4dBm
*/
#define REGISTER4_DEFAULT			ADF4350_REG4_RF_DIV_SEL(2) \
									+ ADF4350_REG4_8BIT_BAND_SEL_CLKDIV(230) \
									+ ADF4350_REG4_RF_OUT_EN \
									+ ADF4350_REG4_OUTPUT_PWR(1) \
									+ ADF4350_REG4_FEEDBACK_FUND
									//+ ADF4350_REG4_FEEDBACK_DIVIDED
									//+ ADF4350_REG4_VCO_PWRDOWN_EN


/* Register 5
 * LD PIN : DIGITAL MODE
 */
#define REGISTER5_DEFAULT			ADF4350_REG5_LD_PIN_MODE_DIGITAL + (3<<19) //for RESERVED bits 1 1


// Hardware structure definition
typedef struct{
	GPIO_TypeDef *GPIOx;
	uint16_t GPIO_Pin;
	SPI_HandleTypeDef *hspi;
} STM32_Hardware_Struct;

/**
  * @brief  Initialize the Hardware structured depending on hardware used
  * @param  Hardware_struct Hardware structure to fill
  * @param  GPIOx GPIO port for LE
  * @param	GPIO_Pin GPIO pin used for LE
  * @param	hspi pointer to SPI used for DATA
  * @retval 1 = OK
  */
uint8_t Hardware_Setup(STM32_Hardware_Struct *Hardware_struct, GPIO_TypeDef *GPIOx,
		uint16_t GPIO_Pin, SPI_HandleTypeDef *hspi);

/**
  * @brief  Transmit 32bits in blocking mode on SPI bus with LE signal
  * @param  Hardware_struct Hardware structure with GPIO and SPI information
  * @param  pData pointer to data buffer (u8 or u16 data elements)
  * @retval HAL status
  */
HAL_StatusTypeDef SPI_Transmit_32(STM32_Hardware_Struct *Hardware_struct, uint32_t *pData);

/**
  * @brief  Init PLL with Default values
  * @param  Hardware_struct Hardware structure with GPIO and SPI information
  * @retval HAL status
  */
HAL_StatusTypeDef Init_PLL(STM32_Hardware_Struct *Hardware_struct);

#endif // ADF4350_H_
