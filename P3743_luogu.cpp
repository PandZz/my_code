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
    return s <= lim * p ? true : false;
}

void solve()
{
    double l = 0, r = 2500000000, mid;
    while (r - l > dep)
    {
        mid = (r + l) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    ans = l;
}

inline bool special()
{
    double s = 0;
    for (R i = 1; i <= n; ++i) s += a[i];
    if (s <= p)
    {
        puts("-1");
        return true;
    }
    else return false;
}

int main()
{
    scanf("%d %d", &n, &p);
    for (R i = 1; i <= n; ++i)
    {
        scanf("%d %d", a + i, b + i);
        t[i] = double(b[i]) / a[i];
    }
    if (special()) return 0;
    solve();
    printf("%lf", ans);
    return 0;
}