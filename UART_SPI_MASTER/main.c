#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "Compiler.h"
#include "LCD_interface.h"
#include "LCD_PreCFG.h"
#include "UART_interface.h"
#include "UART_Cfg.h"
#include "SPI_interface.h"
#include "SPI_Cfg.h"
#include <avr/delay.h>
#include "avr/io.h"

	int main ()

   {

	uint8_t Data_Sent , loop1 = 0 ;

	uint8_t loop2=0;

	uint8_t Data_Recieved = 0;

	uint8_t Data_UART[]="ENTER OPERATION";

	str_UartConfg_t Uart_init_STRUC;

	Uart_init_STRUC.u32_BaudRate=9600;

	Uart_init_STRUC.u8_DataBits=UART_8_BIT_MODE;

	Uart_init_STRUC.u8_FlagAction=UART_POLLING;

	MCAL_UART_init(&Uart_init_STRUC);

    MCAL_SPI_MasterInit(SPI_MASTER_FREQUENCY_4);

    HAL_LCD_voidInit();


		while(Data_UART[loop1] != '\0')
		{
			MCAL_UART_sendByteBusyWait(Data_UART[loop1]);

			loop1 ++ ;
		}

		while (1)
		{

			MCAL_UART_recieveByteBusyWait(&Data_Sent);

			if ((Data_Sent>='0'&&Data_Sent<='9')|| (Data_Sent>='A'&&Data_Sent<='Z')||(Data_Sent>='a'&&Data_Sent<='z'))
			{

				if (loop2<=15)
				{

					HAL_LCD_MoveCursor(0 , loop2);

					HAL_LCD_voidWriteCharacter((uint8_t)Data_Sent);

					MCAL_SPI_Master_DataBusyWait(Data_Sent, &Data_Recieved);

					loop2++;

				}

				else if ((loop2>15)&&(loop2<32))
				{
					HAL_LCD_MoveCursor(1 , (loop2-16));

					HAL_LCD_voidWriteCharacter((uint8_t)Data_Sent);

					MCAL_SPI_Master_DataBusyWait(Data_Sent, &Data_Recieved);

					loop2++;

				}
				else
				{
					HAL_LCD_voidClearAll();

					loop2=0;

					HAL_LCD_MoveCursor(0 , loop2);

					HAL_LCD_voidWriteCharacter((uint8_t)Data_Sent);

					MCAL_SPI_Master_DataBusyWait(Data_Sent, &Data_Recieved);

					loop2++;

				}
			}
			else
			{

			}

		}
   }

