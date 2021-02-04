#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Compiler.h"
#include "DIO_interface.h"
#include "led_interface.h"
#include "led_precfg.h"
#include "SPI_interface.h"
#include "SPI_Cfg.h"
#include <avr/delay.h>
#include "avr/io.h"

   int main (){

	   MCAL_SPI_SlaveInit();
	   DIO_LED_VOIDINIT();

	   uint8_t Data_Sent=0;
	   uint8_t Data_Recieved=0;

	   while (1){

		   MCAL_SPI_Slave_DataBusyWait(Data_Sent ,&Data_Recieved);

		   if (Data_Recieved=='A')
		   {
			   LED_ON(LED0);
		   }
		   else if (Data_Recieved=='B')
		   {
			   LED_OFF(LED0);
		   }
		   else {

		   }
	   }
   }
