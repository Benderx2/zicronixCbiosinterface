//! Borrowed from SmallerC's implementation https://github.com/alexfru/SmallerC/
/*!
Copyright (c) 2012, Alexey Frunze
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met: 

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution. 

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies, 
either expressed or implied, of the FreeBSD Project.
!*/
#include <screen.h>
#include <string.h>
int vprintf(char* fmt, void* vl)
{
  int* pp = vl;
  int cnt = 0;
  char* p;
  char* phex;
  char s[12];
  char* pc;
  int n, sign, msign;
  int minlen = 0, len;

  for (p = fmt; *p != '\0'; p++)
  {
    if (*p != '%' || p[1] == '%')
    {
      putchar(*p);
      p = p + (*p == '%');
      cnt++;
      continue;
    }
    p++;
    minlen = 0;
    msign = 0;
    if (*p == '+') { msign = 1; p++; }
    else if (*p == '-') { msign = -1; p++; }
    if (isdigit(*p))
    {
      while (isdigit(*p))
        minlen = minlen * 10 + *p++ - '0';
      if (msign < 0)
        minlen = -minlen;
      msign = 0;
    }
    if (!msign)
    {
      if (*p == '+') { msign = 1; p++; }
      else if (*p == '-') { msign = -1; p++; }
    }
    phex = "0123456789abcdef";
    switch (*p)
    {
    case 'c':
      while (minlen > 1) { putchar(' '); cnt++; minlen--; }
      putchar(*pp++);
      while (-minlen > 1) { putchar(' '); cnt++; minlen++; }
      cnt++;
      break;
    case 's':
      pc = *pp++;
      len = 0;
      if (pc)
        len = strlen(pc);
      while (minlen > len) { putchar(' '); cnt++; minlen--; }
      if (len)
        while (*pc != '\0')
        {
          putchar(*pc++); 
          cnt++;
        }
      while (-minlen > len) { putchar(' '); cnt++; minlen++; }
      break;
    case 'i':
    case 'd':
      pc = &s[sizeof s - 1];
      *pc = '\0';
      len = 0;
      n = *pp++;
      sign = 1 - 2 * (n < 0);
      do
      {
        *--pc = '0' + (n - n / 10 * 10) * sign;
        n = n / 10;
        len++;
      } while (n);
      if (sign < 0)
      {
        *--pc = '-';
        len++;
      }
      else if (msign > 0)
      {
        *--pc = '+';
        len++;
        msign = 0;
      }
      while (minlen > len) { putchar(' '); cnt++; minlen--; }
      while (*pc != '\0')
      {
        putchar(*pc++); 
        cnt++;
      }
      while (-minlen > len) { putchar(' '); cnt++; minlen++; }
      break;
    case 'u':
      pc = &s[sizeof s - 1];
      *pc = '\0';
      len = 0;
      n = *pp++;
      do
      {
        unsigned nn = n;
        *--pc = '0' + nn % 10;
        n = nn / 10;
        len++;
      } while (n);
      if (msign > 0)
      {
        *--pc = '+';
        len++;
        msign = 0;
      }
      while (minlen > len) { putchar(' '); cnt++; minlen--; }
      while (*pc != '\0')
      {
        putchar(*pc++); 
        cnt++;
      }
      while (-minlen > len) { putchar(' '); cnt++; minlen++; }
      break;
    case 'X':
      phex = "0123456789ABCDEF";
      // fallthrough
    case 'p':
    case 'x':
      pc = &s[sizeof s - 1];
      *pc = '\0';
      len = 0;
      n = *pp++;
      do
      {
        unsigned nn = n;
        *--pc = phex[nn & 0xF];
        n = nn >> 4;
        len++;
      } while (n);
      while (minlen > len) { putchar(' '); cnt++; minlen--; }
      while (*pc != '\0')
      {
        putchar(*pc++); 
        cnt++;
      }
      while (-minlen > len) { putchar(' '); cnt++; minlen++; }
      break;
    case 'o':
      pc = &s[sizeof s - 1];
      *pc = '\0';
      len = 0;
      n = *pp++;
      do
      {
        unsigned nn = n;
        *--pc = '0' + (nn & 7);
        n = nn >> 3;
        len++;
      } while (n);
      while (minlen > len) { putchar(' '); cnt++; minlen--; }
      while (*pc != '\0')
      {
        putchar(*pc++); 
        cnt++;
      }
      while (-minlen > len) { putchar(' '); cnt++; minlen++; }
      break;
    default:
      return -1;
    }
  }

  return cnt;
}

int printf(char* fmt, ...)
{
  void** pp = &fmt;
  return vprintf(fmt, pp + 1);
}