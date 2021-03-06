#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void printbin(void *p, int n)
{
    char *s = (char*)malloc(n * 8 + 1);
    s[n * 8] = '\0';
    unsigned char t;
    int j = 0;
    while (j < n)
    {
        int i = 8;
        t = *((unsigned char*)p + j);
        while(i > 0)
        {
            s[(n - 1 - j) * 8 + --i] = (t & 1 ? '1' : '0');
            t >>= 1;
        }
        ++j;
    }
    printf("%s\n", s);
    free(s);
}
