#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int t, n, l, r;
LL f[15][110], ans;
int main()
{
    scanf("%d", &t);
    int low, high;
    while (t--)
    {
        scanf("%d%d%d", &n, &l, &r);
        ans = 0;
        memset(f, 0, sizeof(f));
        f[0][0] = 1LL;
        F(i, 1, n)
        {
            low = l * i, high = r * i;
            F(j, low, high)
                F(k, l, r)
                    if (j - k >= 0) f[i][j] += f[i - 1][j - k];
        }
        low = l * n, high = r * n;
        F(i, low, high)
            if (i % 3 == 0) ans += f[n][i];
        printf("%lld\n", ans);
    }
    return 0;
}