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
LL a[5][5], b[4][4], n, m;

void del(int x, int y)
{
    n = m = 0;
    F(i, 0, 3)
    {
        m = 0;
        if (i == x) continue;
        F(j, 0, 3)
        {
            if (j != y) b[n][m++] = a[i][j];
        }
        ++n;
    }
}

LL cal(int x, int y)
{
    del(x, y);
    LL ans = 0;
    F(i, 0, 2)
    {
        ans += b[0][i % 3] * b[1][(i + 1) % 3] * b[2][(i + 2) % 3];
    }
    F(i, 0, 2)
    {
        ans -= b[0][i % 3] * b[1][(i + 2) % 3] * b[2][(i + 1) % 3];
    }
    return ans;
}

int main()
{
    F(i, 0, 3)
        F(j, 0, 3) scanf("%lld", &a[i][j]);
    // LL ans = 0;
    printf("%lld\n", cal(0, 1));
    printf("%lld\n", cal(3, 2));
    printf("%lld\n", cal(2, 2));
    printf("%lld\n", cal(0, 3));
    printf("%lld\n", cal(1, 3));
    printf("%lld\n", cal(2, 2));
    printf("%lld\n", cal(1, 1));
    printf("%lld\n", cal(3, 0));
    // printf("%lld\n", ans);
    return 0;
}