#include <math.h>
#include <stdio.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
#define q(x) ((x) * (x))
typedef long long LL;
int x[3], y[3];

double dis(int a, int b)
{
    return sqrt(q(x[a] - x[b]) + q(y[a] - y[b]));
}

void solve()
{
    double a = dis(0, 1), b = dis(0, 2), c = dis(1, 2), p = (a + b + c) / 2;
    printf("%.3lf %.3lf\n", a + b + c, sqrt(p * (p - a) * (p - b) * (p - c)));
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        F(i, 0, 2) scanf("%d%d", x + i, y + i);
        solve();
    }
    return 0;
}