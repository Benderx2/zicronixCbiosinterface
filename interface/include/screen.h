#ifndef __SCREEN_H
#define __SCREEN_H
#include <stdint.h>
#include <stdbool.h>
typedef uint8_t vga_mode_t;
uint8_t screen_color = 0x07;
bool gfx_mode = false;
typedef struct {
	uint8_t X, Y; 
} cursor_t;
#include <screen/putchar.c>
#include <screen/gfx.c>
#include <screen/setclr.c>
#include <screen/cursor.c>
#endif