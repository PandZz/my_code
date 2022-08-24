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
int main()
{
    unsigned long long n, ans, tmp[3];
    int m;
    while (~scanf("%llu%d", &n, &m))
    {
        tmp[0] = (((1ULL << (m + 1)) - 1) & n) << (m + 1);
        tmp[1] = (((1ULL << (m + 1)) - 1) << (m + 1)) & n, tmp[1] >>= m + 1;
        tmp[2] = (~((((1ULL << (m + 1)) - 1) & n) | (((1ULL << (m + 1)) - 1) << (m + 1)))) & n;
        ans = tmp[0] | tmp[1] | tmp[2];
        printf("%llu\n", ans);
    }
    return 0;
}