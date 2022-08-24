#include <stdio.h>
#define maxn 5000005
int n, a[maxn], l, b[maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &b[i]);
        if (!l || a[l] == b[i]) a[++l] = b[i];
        else --l;
    }
    if (!l) puts("Not Found");
    else
    {
        int s = 0, ls = a[l];
        for (int i = 1; i <= n; ++i) s += ls == b[i];
        if (s >= (n - 1) / 2 + 1) printf("%d\n", ls);
        else puts("Not Found");
    }
    return 0;
}