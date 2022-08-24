#include <stdio.h>
int n, m;
long long ans;
int aX[1001], aY[1001], bX[1001], bY[1001], s[1001];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d%d%d", aX + i, aY + i, s + i);
    for (int i = 1; i <= m; ++i) scanf("%d%d", bX + i, bY + i);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (aX[i] == bX[j]) { ans += s[i]; break; }
            if (aY[i] == bY[j]) { ans += s[i]; break; }
        }
    }
    printf("%lld\n", ans);
    return 0;
}