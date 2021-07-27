#include <bits/stdc++.h>
using namespace std;
#define R register int

const int N = 1e5 + 1;
const double dep = 1e-5;

int n, p;
int a[N], b[N];
double t[N], ans;

inline bool check(double lim)
{
    double s = 0;
    for (R i = 1; i <= n; ++i)
        if (t[i] < lim) s += a[i] * (lim - t[i]);
    return s <= lim ? true : false;
}

void solve()
{
    double l = 0, r = N, mid;
    while (r - l > dep)
    {
        mid = (r + l) / double(2);
        if (check(mid)) l = mid;
        else r = mid;
    }
    ans = l;
}

int main()
{
    scanf("%d %d", &n, &p);
    for (R i = 1; i <= n; ++i)
    {
        scanf("%d %d", a + i, b + i);
        t[i] = double(b[i]) / double(a[i]);
    }
    bool flag = true;
    for (R i = 1; i <= n; ++i)
        if (a[i] >= p) {flag = false; break;}
    if (n == 1 && a[1] == p) flag = true;
    if (flag)
    {
        puts("-1");
        return 0;
    }
    solve();
    printf("%lf", ans);
    return 0;
}