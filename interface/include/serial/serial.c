#include <x86.h>
#include <stdint.h>
//! Serial Initialization
void init_serial()
{
   outportb(COM1_PORT + 1, 0x00);    // Disable all interrupts
   outportb(COM1_PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
   outportb(COM1_PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
   outportb(COM1_PORT + 1, 0x00);    //                  (hi byte)
   outportb(COM1_PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
   outportb(COM1_PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
   outportb(COM1_PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
}
// s_putchar -- Serial Putchar 
uint8_t s_putchar(uint8_t c)
{
	asm("mov al, [bp +4]");
	asm("push edx");
	asm("push eax");	
	asm("mov dx, 0x3F8+5");		
	asm(".wait:");
	asm("in al, dx");
	asm("bt ax, 5");		
	asm("jnc .wait");	
	asm("pop eax");		
	asm("mov dx, 0x3F8");	
	asm("out dx, al");		
	asm("pop edx");
	asm("leave");
	asm("ret");
}