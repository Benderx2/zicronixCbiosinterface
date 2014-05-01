//! Defines x86 Crap 
int halt(void)
{
	printf("Halt Called. Now Halting.....\n");
	asm("cli");
	asm("hlt");
	asm("jmp $");
}
void outportb(uint16_t port, uint8_t byte)
{
	asm("pusha");
	asm("mov al, [bp + 4]");
	asm("mov dx, [bp + 6]");
	asm("out dx, al");
	asm("popa");
}
uint8_t inportb(uint16_t port)
{
	asm("push dx");
	asm("mov dx, [bp + 4]");
	asm("in al, dx");
	asm("pop dx");
}
