#include <stdio.h>
#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"
#include <float.h>

#include <limits.h>


int wchar2utf8(char *const str, const wchar_t c);

int main()
{
   /* int		m, k;
    char a = 'a', b = 'b';
    m = printf("%%dsdf%+01.5vbn\n", 1335, 78);
    k = ft_printf("%%dsdf%+01.5vbn\n", 1335, 78);
    m = printf("I am the %s of the %s!", "King", "world");
    printf("\n%i\n", m);
    k = ft_printf("I am the %s of the %s!", "King", "world");
    printf("\n%i\n", k);
    printf("%%d;", 10000000);
    printf("%d", sizeof(wchar_t));
    m = printf("1 %-3c 2 %3c", a, b);
    printf("\n%i\n", m);
    k = ft_printf("1 %-3c 2 %3c", a, b);
    printf("\n%i\n", k);
    m = printf("First %d Second %d", 500, -10);
    printf("\n%i\n", m);
    k = ft_printf("First %d Second %d", 500, -10);
    printf("\n%i\n", k);
    m = printf("%lldt", 4236789ll);
    printf("\n%i\n", m);
    k = ft_printf("%lldt", 4236789ll);
    printf("\n%i\n", k);*/

    long double d = 392.6512342346L;
    long double l = LDBL_MIN;
    uint64_t	*man = (uint64_t*)&l;
    uint32_t	*exp = (uint32_t*)(((uint64_t*)&l) + 1);

    //*man = 0xffffffffffffffff;
    //*man = 0;
    //*man = 0x8000000000000000;
    //*exp = 0x00007fff;
    //printf("%llu %u\n", *man, *exp);
    //printbin(man, 8);
    //printbin(exp, 2);

    wchar_t s[5];
    s[0] = L'€';
    s[1] = L'€';
    s[2] = L'€';
    s[3] = L'€';
    s[4] = 0;
    //s = L"ABCD";
    ft_printf("%d\n", ft_printf("%ls", s));
    wchar_t c = 0x10160;
    s[0] = c;
    printbin(&c, 4);
    printbin(s, 4);
    ft_printf("%ls", s);
    return 0;
}
