#include <screen.h>
#include <serial.h>
void putchar(uint8_t c)
{
	if (serial_output == false)
	{
		scr_putchar(c);
	}
	else
	{
		s_putchar(c);
	}
}