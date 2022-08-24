#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;

char s[200], ans[200];

int main()
{
    int len;
    char * p;
    while (gets(s) != NULL)
    {
        memset(ans, 0, sizeof(ans));
        len = strlen(s), p = s;
        while (p - s < len)
        {
            char * ptr = strstr(p, "goo");
            if (ptr == NULL)
            {
                strcat(ans, p);
                break;
            }
            else
            {
                strncat(ans, p, ptr - p);
                p = ptr++;
                while (*ptr == 'o') ++ptr;
                if (*ptr == 'd') strcat(ans, "perfect"), p = ptr + 1;
                else strncat(ans, p, ptr - p), p = ptr;
            }
        }
        puts(ans);
    }
    return 0;
}