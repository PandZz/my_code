#include <stdio.h>
#define N 1001
int t, n, a[N];

int solve(int l, int r)
{
    if (l == r) return a[l];
    int mid = (l + r) / 2, L = solve(l, mid), R = solve(mid + 1, r);
    return (L + R) & (L - R);
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", a + i);
        printf("%d\n", solve(1, n));
    }
    return 0;
}