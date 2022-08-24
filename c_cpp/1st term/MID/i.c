#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int n;
LL a[2005], s[2005], ans, tot;
int main()
{
    scanf("%d", &n);
    F(i, 1, n) scanf("%lld", a + i), a[i + n] = a[i];
    F(i, 1, 2 * n) s[i] = s[i - 1] + a[i];
    F(i, 1, n)
    {
        F(j, i + 1, n + 1)
        {
            if ((s[j] - s[i]) * 2 == s[n]) ++tot;
        }
    }
    // printf("%lld\n", tot);
    ans = tot * (tot - 1) / 2;
    printf("%lld\n", ans);
    return 0;
}