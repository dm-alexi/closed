#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "ft_printf.h"
#include <float.h>

#include <limits.h>

int main()
{
   /* int		l, k;
    char a = 'a', b = 'b';
    //wchar_t a = L'a', b = L'b';
    //l = printf("%%dsdf%+01.5vbn\n", 1335, 78);
    //k = ft_printf("%%dsdf%+01.5vbn\n", 1335, 78);
    l = printf("I am the %s of the %s!", "King", "world");
    printf("\n%i\n", l);
    k = ft_printf("I am the %s of the %s!", "King", "world");
    printf("\n%i\n", k);
    //printf("%%d;", 10000000);
    //printf("%d", sizeof(wchar_t));
    l = printf("1 %-3c 2 %3c", a, b);
    printf("\n%i\n", l);
    k = ft_printf("1 %-3c 2 %3c", a, b);
    printf("\n%i\n", k);
    l = printf("First %d Second %d", 500, -10);
    printf("\n%i\n", l);
    k = ft_printf("First %d Second %d", 500, -10);
    printf("\n%i\n", k);
    l = printf("%Ldt", 4236789);
    printf("\n%i\n", l);
    k = ft_printf("%Ldt", 4236789);
    printf("\n%i\n", k);*/
    float f = 392.6512342346;
    long double d = 392.6512342346L;
    long double dub = 0.01171875;
    long double tmp = -1;
    double nul = -0.0;
    int i;

    //printbin(&dub, 16);
    //printbin(&nul, 12);
    //floatlen(nul, NULL, NULL);

    long double l = LDBL_MIN;
    uint64_t	*man = (uint64_t*)&l;
    uint32_t	*exp = (uint32_t*)(((uint64_t*)&l) + 1);

    //printf("%Lf\n", l);
    //ft_printf("%Lf\n", l);
    //*man = 0xffffffffffffffff;
    //*man = 0;
    //*man = 0x8000000000000000;
    //*exp = 0x00007fff;
    //printbin(man, 8);
    //printbin(exp, 2);
    //ft_printf("%Lf\n", l);
    //printf("%Lf\n", l);

    d = LDBL_MIN;
    //ft_printf("%.5000Lf!\n", d);
    //printf("%.5000Lf!\n", d);
	//d = 0.25234523450;
	//d = 4.25;

    ft_printf("%LE!\n", d);
    ft_printf("%Lg!\n", d);
    ft_printf("%Lf!\n", d);
    printf("---\n");
    printf("%LE!\n", d);
    printf("%Lg!\n", d);
    printf("%Lf!\n", d);
    printf("---\n");/*
    d = 0.25234523450;
    ft_printf("%LE!\n", d);
    ft_printf("%Lg!\n", d);
    ft_printf("%Lf!\n", d);
    printf("---\n");
    printf("%LE!\n", d);
    printf("%Lg!\n", d);
    printf("%Lf!\n", d);
    printf("---\n");*/

    return 0;
}
