/*! 
	GFX BIOS Interface Calls
!*/
//! Definitions for Mode Numbers, Avoid Magic Constants
#include <stdint.h>
#include <stdbool.h>
#define VGA_40x25 0x01
#define VGA_80x25 0x03
#define VGA_320x200x256 0x0D
#define VGA_640x480x256 0x12
int vga_gfxmode(vga_mode_t mode_number)
{
	if (mode_number == VGA_80x25 || mode_number == VGA_80x25)
	{
		asm("pusha");
		asm("mov al, [bp + 4]");
		asm("mov ah, 0x00");
		asm("int 0x10");
		asm("popa");
		gfx_mode = false;
		asm("leave");
		asm("ret");
	}
	asm("pusha");
	asm("mov al, [bp + 4]");
	asm("mov ah, 0x00");
	asm("int 0x10");
	asm("popa");
	gfx_mode = true;
}