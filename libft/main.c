#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <limits.h>
#include "libft.h"

void plusone(char *s) { ++*s; }
void plusodd(unsigned int i, char *s) { *s += i % 2; }

int cmp(const void *a,const void *b)
{
    return *(int*)(a) - *(int*)(b);
}
/*
static void memswap(void *a, void *b, size_t size)
{
    unsigned char *s;
    unsigned char *t;
    size_t i;

    s = a;
    t = b;
    i = 0;
    while (i < size)
    {
        *(s + i) ^= *(t + i);
        *(t + i) ^= *(s + i);
        *(s + i) ^= *(t + i);
        ++i;
    }
}
*/
int main()
{
	printf("%d\n", ft_atoi("0"));
    printf("%d\n", ft_atoi("20"));
    printf("%d\n", ft_atoi("25389"));
    printf("%d\n", ft_atoi("-25389"));
    printf("%d\n", ft_atoi("2147483647"));
    printf("%d\n", ft_atoi("99999999999999999999999999"));
    printf("%d\n", atoi("99999999999999999999999999"));
    printf("%d\n", ft_atoi("-99999999999999999999999999"));
    printf("%d\n", atoi("-99999999999999999999999999"));
	printf("%d\n", ft_atoi("-47-5"));
/*
    char szNumbers[] = "2001 60c0c0 -1101110100110100100000 0x6fffff";
  char * pEnd;
  long int li1, li2, li3, li4, li5;
  li1 = strtol (szNumbers,&pEnd,10);
  li2 = strtol (pEnd,&pEnd,16);
  li3 = strtol (pEnd,&pEnd,2);
  li4 = strtol (pEnd,NULL,0);
  printf ("The decimal equivalents are: %ld, %ld, %ld and %ld.\n", li1, li2, li3, li4);
  li5 = strtol("0x6fffff", NULL, 0);
  printf("%ld\n", li5);
  int a = 0;
  printf("%d", a);

    int arr[] = {50, 16, 11, -2, 0, 34, 0, 34, 99, 4, 8, 1};
    ft_qsort(arr, 12, 4, cmp);
    unsigned char *l = (unsigned char*)arr, *r = l + 4 * (12 - 1);

    for (int i = 0; i < 12; ++i)
        printf("%d ", arr[i]);
*/
    return 0;
}
