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
    return *(int*)(b) - *(int*)(a);
}

void print(t_list *elem)
{
    printf("%d ", *(int*)(elem->content));
}

int main()
{
/*
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
	*/
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
*/
    t_list *t = NULL;
    int a[4] = {10, 9, 22, 21};
    ft_lstadd(&t, ft_lstnew(a + 2, 4));
    ft_lstadd(&t, ft_lstnew(a + 1, 4));
    ft_lstadd(&t, ft_lstnew(a, 4));
    ft_lstadd(&t, ft_lstnew(a + 3, 4));
    ft_lstiter(t, print);
    putchar('\n');
    ft_lstsort(&t, cmp);
    ft_lstiter(t, print);

    return 0;
}
