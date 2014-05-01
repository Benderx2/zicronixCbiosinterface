Zicronix C BIOS Interface
======================

Zicronix C BIOS Interface is written in SmallerC to provide an interface between lowlevel BIOS functions and C.
Primarily written for Zicronix Loader, Zicronix C BIOS interface provides a wrapper over BIOS functions as well as some
functions like printf, serial output, string functions etc. It's written for bootloader developers. 
Some stuff like Disk I/O is remaining, it should be done by this weekend. Hopefully, till then you can have a look at "example.c" which shows some of the examples.
