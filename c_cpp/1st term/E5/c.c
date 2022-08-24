#include <stdio.h>
#define N 1005
typedef long long LL;
int n, m;
LL a[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
    LL ls, ans = m;
    for (int i = 1; i < n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (a[i] < a[j])
            {
                ls = m + m / a[i] * (a[j] - a[i]);
                if (ls > ans) ans = ls;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}