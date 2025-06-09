/*
 * The content of this file is in the public domain.
 */
#include <stdint-gcc.h>
#include "libc.h"

int abs(int j) {
  if (j < 0)
    return -j;
  else
    return j;
}

int isdigit(int c) {
  return (c >= '0' && c <= '9');
}

void *memcpy(void *d, const void *s, size_t n) {
  void *d0 = d;
  if (s != d)
    for (; 0 != n; --n)
      *(char*)d++ = *(char*)s++;
  return d0;
}

void *memmove(void* d, void* s, size_t n)
{
  char *cd = d;
  char *cs = s;
  if (s < d)
    for (cs += n, cd += n; 0 != n; --n)
      *--cd = *--cs;
  else if (s != d)
    for (; 0 != n; --n)
      *cd++ = *cs++;
  return d;
}

void * __attribute__((weak)) memset(void * dest, int c, size_t n)
{
    unsigned char *s = dest;
    size_t k;

    /* Fill head and tail with minimal branching. Each
     * conditional ensures that all the subsequently used
     * offsets are well-defined and in the dest region. */

    if (!n) return dest;
    s[0] = s[n-1] = c;
    if (n <= 2) return dest;
    s[1] = s[n-2] = c;
    s[2] = s[n-3] = c;
    if (n <= 6) return dest;
    s[3] = s[n-4] = c;
    if (n <= 8) return dest;

    /* Advance pointer to align it at a 4-byte boundary,
     * and truncate n to a multiple of 4. The previous code
     * already took care of any head/tail that get cut off
     * by the alignment. */

    k = -(uintptr_t)s & 3;
    s += k;
    n -= k;
    n &= -4;
    n /= 4;

    uint32_t *ws = (uint32_t *)s;
    uint32_t wc = c & 0xFF;
    wc |= ((wc << 8) | (wc << 16) | (wc << 24));

    /* Pure C fallback with no aliasing violations. */
    for (; n; n--, ws++) *ws = wc;

    return dest;
}

int strcmp(const char *s1, const char *s2) {
  for (; (*s1 != '\0') && (*s1 == *s2); ++s1, ++s2)
    ;
  return (*s1 - *s2);
}

char *strcpy(char *dest, const char *src)
{
  char * tmp = dest;
  for (; (*dest = *src) != 0; ++dest, ++src);
  return tmp;
}

char *strncpy(char *dest, const char *src, size_t n)
{
  if (n != 0) {
    char *d = dest;
    do {
      if ((*d++ = *src++) == 0) {
	while (--n != 0)
	  *d++ = 0;
	break;
      }
    } while (--n != 0);
  }
  return dest;
}

size_t strnlen(const char *s, size_t maxlen) {
  size_t len = 0;
  for (; s[len] != '\0' && len < maxlen; ++len)
    ;
  return len;
}

size_t strlen(const char *s) {
  size_t len = 0;
  for (; s[len] != '\0'; ++len)
    ;
  return len;
}

char *
strrchr (s, c)
     register const char *s;
     int c;
{
  char *rtnval = 0;

  do {
    if (*s == c)
      rtnval = (char*) s;
  } while (*s++);
  return (rtnval);
}

double atof_hop(char *s)
{
  double a = 0.0;
  int e = 0;
  int c;
  while ((c = *s++) != '\0' && isdigit(c)) {
    a = a*10.0 + (c - '0');
  }
  if (c == '.') {
    while ((c = *s++) != '\0' && isdigit(c)) {
      a = a*10.0 + (c - '0');
      e = e-1;
    }
  }
  if (c == 'e' || c == 'E') {
    int sign = 1;
    int i = 0;
    c = *s++;
    if (c == '+')
      c = *s++;
    else if (c == '-') {
      c = *s++;
      sign = -1;
    }
    while (isdigit(c)) {
      i = i*10 + (c - '0');
      c = *s++;
    }
    e += i*sign;
  }
  while (e > 0) {
    a *= 10.0;
    e--;
  }
  while (e < 0) {
    a *= 0.1;
    e++;
  }
  return a;
}

int atoi(char* str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';

    return res;
}
