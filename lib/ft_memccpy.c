#include <stdlib.h>

void    *ft_memccpy(void *dst, const void *src, int c, size_t num)
{
    char    *s;
    char    *e;
    char    *t;

    t = (char*)dst;
    s = (char*)src;
    e = s + num;
    while (s != e && (*t++ = *s++) != c)
        ;
    return (*(t - 1) == c ? (void*)t : NULL);
}
