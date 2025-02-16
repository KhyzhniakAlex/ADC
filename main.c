#include "CircularBuffer.h"
#include "delay.h"
#include "ADC.h"
#include "tm1637.h"
// Display Tm 1637 shuld be:GNG-GND, VCC-5v, DIO - B6, CLC - B7

//#define BUF_SIZE_128 128
//#define BUF_SIZE_64  64
//#define BUF_SIZE_16  16
//#define BUF_SIZE_8   8
//#define BUF_SIZE_4   4
//// Two GPIO for SPI emul //GPIO_Pin_6|GPIO_Pin_7;//GPIOB


//A1 - ADC



unsigned int digit_display0 = 0;
unsigned int digit_display2 = 2222;
unsigned int digit_ads = 0007;



int main()
{
	circularBuffer_t *cbptr;
 	ADC_init();

	cbptr = (circularBuffer_t *)malloc (sizeof (circularBuffer_t));     
  createCircularBuffer(cbptr, 5);

  delay_ms(10);
	GPIOC_init_13_o ();
	TM1637_init();	
  TM1637_brightness(BRIGHT_TYPICAL); 
	delay_ms(10);
	TM1637_display_all(digit_display0);
	delay_ms(1000);
 
	
	while (1)
	{
		buffer_add(cbptr, ADC_read());
		delay_ms(500);
    TM1637_display_all(buffer_read(cbptr));
		delay_ms(500);
	}
}


