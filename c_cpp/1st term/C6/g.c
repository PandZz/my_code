#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int a[1000005], n, m;

int lower_bound(int x)
{
    int l = 1, r = n, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (a[mid] < x) l = mid + 1;
        else r = mid;
    }
    return a[l] >= x ? l : -1;
}

int upper_bound(int x)
{
    int l = 1, r = n, mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (a[mid] <= x) l = mid + 1;
        else r = mid;
    }
    return a[l] > x ? l : -1;
}

int main()
{
    scanf("%d%d", &n, &m);
    F(i, 1, n) scanf("%d", a + i);
    int e;
    F(i, 1, m)
    {
        scanf("%d", &e);
        printf("%d %d\n", lower_bound(e), upper_bound(e));
    }
    return 0;
}