uint8_t getch()
{
	asm("mov ah, 0x00");
	asm("int 0x16");
	asm("mov al, ah");
}