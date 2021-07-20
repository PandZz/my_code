#include <bits/stdc++.h>
using namespace std;
#define R register int

const int N = 1e5 + 1;
const double dep = 1e-4;

int n, p;
int a[N], b[N];
double ans;

inline bool check(double lim)
{

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
    for (R i = 1; i <= n; ++i) scanf("%d %d", a + i, b + i);
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