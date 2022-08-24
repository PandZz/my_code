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
#define N 100005

int t, n;
LL c[N * 2];

int main()
{
    LL ans;
    scanf("%d", &t);
    int a;
    while (t--)
    {
        ans = 0, memset(c, 0, sizeof c);
        scanf("%d", &n);
        F(i, 1, n) scanf("%d", &a), c[a - i + n]++;
        F(i, 0, 2 * n) ans += c[i] * (c[i] - 1) / 2;
        printf("%lld\n", ans);
    }
    return 0;
}