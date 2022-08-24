#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;

int len;
char s[105];

int main()
{
    int ans, i, tmp, size;
    while (gets(s) != NULL)
    {
        i = 0, ans = 0, len = strlen(s), size = 4;
        if (s[0] == '&' && s[2] == '+') size = 400;
        while (i < len)
        {
            if (isdigit(s[i]))
            {
                tmp = 0;
                while (isdigit(s[i]))
                {
                    tmp = tmp * 10 + s[i] - '0';
                    ++i;
                }
                ans += tmp * size;
            }
            else ++i;
        }
        // printf("%d ", ans);
        printf("0x%08x\n", ans);
    }
    return 0;
}