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

LL dis(LL x, LL y, LL x_, LL y_)
{
    return abs(x - x_) + abs(y - y_);
}

LL x[1005], y[1005];

int main()
{
    LL n, m, k, T, a, b, ans;
    scanf("%lld%lld%lld%lld", &n, &m, &k, &T);
    F(i, 1, k) scanf("%lld%lld", x + i, y + i);
    F(i, 1, T)
    {
        scanf("%lld%lld", &a, &b);
        ans = 1LL << 62;
        F(j, 1, k) ans = min(ans, dis(a, b, x[j], y[j]));
        printf("%lld\n", ans);
    }
    return 0;
}