#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
char s[1005], s0[1005];
int lenS, lenS0;
int main()
{
    scanf("%s%s", s, s0);
    lenS = strlen(s), lenS0 = strlen(s0);
    int pos, tot = 0, ans = 0;
    for (int i = 0; i < lenS0 - lenS + 1; ++i)
    {
        tot = 0;
        for (int j = 0; j < lenS; ++j)
        {
            pos = i + j;
            tot += s[j] != s0[pos];
        }
        if (tot <= 3) ++ans;
    }
    printf("%d", ans);
    return 0;
}