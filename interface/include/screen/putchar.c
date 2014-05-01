/*
	putchar - Define LL routines for putchar
*/
#include <stdint.h>
#include <stdbool.h>
void scr_putchar(uint8_t c)
{
	if (c == '\n')
	{
		asm("pusha"); /* Push All registers */
		asm("mov bh, 0x00");
		asm("mov al, 13");  /* CR+LF */
		asm("mov ah, 0x0E");
		asm("int 0x10");
		asm("mov al, 10");
		asm("int 0x10");
		asm("popa");
		asm("leave");
		asm("ret");
	}
	else {
			/* If we're in GFX mode configure the color too. */
			if (gfx_mode == true)
				{
					c_printc(c, screen_color);
					asm("leave");
					asm("ret");
				}
		asm("pusha");
		asm("mov al, [bp + 4]");
		asm("mov bh, 0x00");
		asm("mov ah, 0x0E");
		asm("int 0x10");
		asm("popa");
	}
}
void c_printc(uint8_t c, uint16_t color)
{
	asm("pusha");
	asm("mov al, [bp + 4]");
	asm("mov bh, 0x00");
	asm("mov bl, [bp + 6]");
	asm("mov ah, 0x0E");
	asm("int 0x10");
	asm("popa");
}