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
#define mod 10007
#define N 10000

int f[N + 3][2], n;

int main()
{
    f[0][0] = f[0][1] = 1;
    f[1][0] = 1;
    f[2][0] = 2;
    F(i, 3, N)
    {
        f[i][0] = (f[i - 1][0] + f[i - 2][0] + f[i - 1][1] + f[i - 2][1]) % mod;
        f[i][1] = f[i - 3][0] % mod;
    }
    while (~scanf("%d", &n)) printf("%d\n", (f[n][0] + f[n][1]) % mod);
    return 0;
}