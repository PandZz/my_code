#include <stdio.h>
#define N 100005
int n;
int s[N], t[N];

void solve()
{
    return ;
}

int main()
{
    int T, ns, nt;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        ns = nt = 0;
        for (int i = 1; i <= n; ++i) scanf("%1d", s + i), ns += s[i];
        for (int i = 1; i <= n; ++i) scanf("%1d", t + i), nt += t[i];
        if (ns != nt) { puts("NO"); continue; }
        solve();
    }
    return 0;
}