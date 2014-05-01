//! Part of the ZNULIB Project.
//! Defines string functions
#ifndef __STRING_C
#define __STRING_C
#include <stdint.h>
//! strlen - String Length
size_t strlen(string str)
{
    size_t retval;
    for(retval = 0; *str != '\0'; str++) retval++;
    return retval;
}
//! Reverse - Reverse a string
void reverse(string s)
{
   char *j;
   int i = strlen(s);

   strcpy(j,s);
   while (i-- >= 0)
      *(s++) = j[i];
   *s = '\0';
}
//! strcpy - String Copy
void strcpy(char dest[], const char source[]) 
 {
	int i = 0;
    while (1) 
	{
      dest[i] = source[i];
      if (dest[i] == '\0') break;
      i++;
	}
 }
//! memset - Set a chunk of memory
void memset(void *dest, char val, size_t count)
{
    char *temp = (char *)dest;
    while(count != 0)
	{
		*temp++ = val;
		count--;
	}
}
//! memcpy - Copy a chunk of memory
void memcpy(void *dest, const void *src, size_t count)
{
    const char *sp = (const char *)src;
    char *dp = (char *)dest;
    while(count != 0) 
		{
			*dp++ = *sp++;
			count--;
		}
}
//! mesetw(ide) - Set a chunk of memory (wide)
unsigned short memsetw(unsigned short *dest, unsigned short val, size_t count)
{
    unsigned short *temp = (unsigned short *)dest;
    while(count != 0)
	{
		*temp++ = val;
		 count--;
	}
}
//! itoa - Integer to string
void itoa(int n, char *buffer, int base)
{
   char *ptr = buffer;
   int lowbit;

   base >>= 1;
   do
   {
      lowbit = n & 1;
      n = (n >> 1) & 32767;
      *ptr = ((n % base) << 1) + lowbit;
      if (*ptr < 10)
         *ptr +='0';
      else
         *ptr +=55;
      ++ptr;
   }
   while (n /= base);
   *ptr = '\0';
   reverse (buffer);   /* reverse string */
}
//! integer to string
int atoi(char *p) 
{
		int k = 0;
		while (*p) {
        k = (k<<3)+(k<<1)+(*p)-'0';
        p++;
     }
     return k;
}
//! check if digit
int isdigit(int c)
{
	 return c >= '0' && c <= '9';
}
#endif