#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
#define swap(a, b) (a ^= b, b ^= a, a ^= b)
typedef long long LL;
LL n, s, a[1001], b[1001];
int main()
{
    scanf("%lld%lld", &n, &s);
    F(i, 1, n) scanf("%lld%lld", a + i, b + i);
    F(i, 1, n)
    {
        F(j, 1, n - i)
        {
            if (a[j] * b[j] > a[j + 1] * b[j + 1]) swap(a[j], a[j + 1]), swap(b[j], b[j + 1]);
            else if (a[j] * b[j] == a[j + 1] * b[j + 1] && b[j] > b[j + 1]) swap(a[j], a[j + 1]), swap(b[j], b[j + 1]);
        }
    }
    LL ans = -1, tot = s;
    F(i, 1, n)
    {
        if (tot * s / b[i] > ans) ans = tot / b[i];
        tot *= a[i];
    }
    printf("%lld\n", ans);
    return 0;
}