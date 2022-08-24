#include <math.h>
#include <stdio.h>
int n, k, a[22];
const double pi = 3.14159265;

void solve()
{
    double aSin = sin(2 * pi / k), S, s = 0;
    S = 50 * aSin * k;
    for (int i = 1; i <= k; ++i)
    {
        s += a[i] * a[i + 1] * aSin / 2;
    }
    printf("%.4lf\n", s / S * 100);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &k);
        for (int j = 1; j <= k; ++j) scanf("%d", a + j);
        a[k + 1] = a[1];
        solve();
    }
    return 0;
}