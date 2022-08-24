#include <stdio.h>
#define maxn 100001
int n, k, s, lenAns, lenLs;
int a[maxn], ans[maxn], ls[maxn];

int max(int a, int b){ return a > b ? a : b; }
int min(int a, int b){ return a < b ? a : b; }

int getMax(int l, int r)
{
    int M = -1;
    for (int i = l; i <= r; ++i)
        if (a[i] > M) M = a[i];
    return M;
}

int getMin(int l, int r)
{
    int M = 200;
    for (int i = l; i <= r; ++i)
        if (a[i] < M) M = a[i];
    return M;
}

int main()
{
    int i;
    scanf("%d%d", &n, &k);
    for (i = 1; i <= n; ++i) scanf("%d", a + i);
    while (n >= k)
    {
        lenLs = 0;
        for (i = 1; i + k - 1 <= n; i += k)
        {
            ans[++lenAns] = getMin(i, i + k - 1);
            ls[++lenLs] = getMax(i, i + k - 1);
        }
        if (i <= n)
        {
            ans[lenAns] = min(getMin(i, n), ans[lenAns]);
            ls[lenLs] = max(getMax(i, n), ls[lenLs]);
        }
        for (i = 1; i <= lenLs; ++i) a[i] = ls[i];
        n = lenLs;
    }
    ans[++lenAns] = getMin(1, n);
    for (i = 1; i <= lenAns; ++i) printf("%d\n", ans[i]);
    return 0;
}