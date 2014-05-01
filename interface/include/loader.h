#ifndef __LOADER_H
#define __LOADER_H
asm("org 0x100");
asm("cli");
asm("push cs");
asm("pop ds");
asm("push ds");
asm("pop es");
asm("push ds");
asm("pop ss");
asm("push es");
asm("pop fs");
asm("jmp _main");
#endif