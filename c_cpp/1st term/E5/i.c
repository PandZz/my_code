#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;

LL c[14][14];
LL g(int n, int m)
{
    if (n <= 13 && m <= 13) return c[n][m];
    return c[n % 13][m % 13] * (g(n / 13, m / 13) % 13) % 13;
}

int main()
{
    LL m, n;
    for (int i = 0; i <= 13; ++i)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % 13;
    }
    while (~scanf("%lld%lld", &n, &m))
    {
        printf("%lld\n", g(n, m));
    }
    return 0;
}