//! VBEGetModeInformation -- 
//! Query the information about a mode
uint16_t VBEGetModeInformation(uint16_t mode_number, uint16_t InfoBlock)
{
	asm("pusha");
	asm("mov ax, 0x4F01");
	asm("mov cx, [bp + 4]");
	asm("and cx, 0xFFF");
	asm("mov di, [bp + 6]");
	asm("int 0x10");
	asm("popa");
	return 0;
}
