#include <stdint.h>
#include <errno.h>
#include <stdbool.h>
uint16_t reset_disk(uint8_t disk_no)
{
	asm("pusha"); /* Push Registers */
	asm("mov dl, [bp + 4]"); /* DL = Disk Drive */
	asm("mov al, 0x00"); /* AL = Function Number */
	asm("int 0x13");
	asm("jc .error");
	asm("popa");
	errno = ERRNO_OK;
	return 0;
	asm(".error");
	asm("popa");
	errno = ERRNO_ERROR;
	return -1;
}
uint16_t read_sector(uint8_t read_count, uint8_t cylinder, uint8_t sector, uint8_t head, uint8_t drive, PhysicalAddr_t buffer)
{
	asm("pusha");
	asm("mov ah, 0x02");
	asm("
}