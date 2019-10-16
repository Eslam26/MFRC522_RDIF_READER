/****************************************************************************************************
 * [File Name]        :  < spi.h >                                                                  *
 * [Author Name ]     :  < Eslam EL-Naggar >                                                        *
 * [Date Created]     :  < 15 Oct. , 2019 >                                                         *
 * [File Description] :  < Header file for Atmega16 SPI Driver >                                    *
 ***************************************************************************************************/


/*----------------------------------------INCLUDES-------------------------------------------------*/

#include "micro_config.h"
#include "std_types.h"
#include "common_macros.h"

/*--------------------------------------DEFINITIONS-----------------------------------------------------*/

#define SPI_DIR_PORT DDRB   /* defines direction port of SPI */
#define SPI_SS   PB4        /* defines slave select pin      */
#define SPI_MOSI PB5        /* defines MOSI pin              */
#define SPI_MISO PB6        /* defines MISO select pin       */
#define SPI_SCK  PB7        /* defines SCK select pin        */

/*-----------------------------------------ENUMS--------------------------------------------------------*/

typedef enum {
	OFF, ON
}SPI_Interrupt_Enable;

typedef enum {
	MSB_FIRST, LSB_FIRST
}SPI_Data_Order;

typedef enum {
	SLAVE, MASTER
}SPI_Master_Mode;

typedef enum {
	LEADING_RISING_TRAILING_FALLING, LEADING_FALLING_TRAILING_RISING
}SPI_Clock_Polarity;

typedef enum {
	LEADING_SAMPLE, TRAILING_SETUP
}SPI_Clock_Phase;

typedef enum {
	F_CPU_4, F_CPU_16, F_CPU_64, F_CPU_128, F_CPU_2, F_CPU_8, F_CPU_32
}SPI_Frequency;


/*-------------------------------------STRUCTURES-------------------------------------------------------*/

typedef struct {
	SPI_Interrupt_Enable interruptMode;
	SPI_Data_Order dataOrderMode;
	SPI_Master_Mode masterMode;
	SPI_Clock_Polarity clockPolarityMode;
	SPI_Clock_Phase clockPhaseMode;
	SPI_Frequency frequencySelect;


}SPI_configType;


/*--------------------------------------FUNCTIONS DECLARATIONS------------------------------------------*/

void SPI_init(const SPI_configType  * ); /* declaration of the function that intializes SPI driver */
void SPI_sendByte(const uint8 data);    /* declaration of the function that sends byte            */
uint8 SPI_recieveByte(void);             /* declaration of the function that recieves byte         */


