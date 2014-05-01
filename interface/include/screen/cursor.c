//! Cursor stuff
void bios_move_cursor(uint8_t x, uint8_t Y)
{	
	asm("pusha");
	asm("mov bh, 0x00");
	asm("mov ah, 0x00");
	asm("mov dl, [bp + 4]");
	asm("mov dh, [bp + 8]");
	asm("int 0x10");
	asm("popa");
	asm("ret");
}