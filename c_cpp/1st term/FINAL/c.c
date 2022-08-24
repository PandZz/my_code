#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
char s[1000005], st[5][10] = {"two", "three", "four", "five", "six"};
int main()
{
    gets(s);
    int ans = 0, len = strlen(s);
    // F(i, 0, 4) printf("%s\n", st[i]);
    char *ptr;
    F(i, 0, 4)
    {
        ptr = s;
        while (ptr - s < len && ptr != NULL)
        {
            ptr = strstr(ptr, st[i]);
            // printf("%d\n", ptr - s);
            if (ptr != NULL)
            {
                // printf("%d %d\n", ptr - s, i + 1);
                ans += i + 2;
                ++ptr;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}