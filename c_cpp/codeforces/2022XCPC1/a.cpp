#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
int n, t;
LL a[200005];
int main()
{
    scanf("%d", &t);
    int l, r;
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%lld", a + i);
        l = 1, r = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] - i > a[l] - l)
            {
                r = i;
                break;
            }
            if (a[i] - i <= a[l] - l)
                l = i;
        }
        if (r)
        {
            printf("YES\n%d %d\n", l, r);
            continue;
        }
        l = 1, r = 0;
        for (int i = 2; i <= n; ++i)
        {
            if (a[i] + i < a[l] + l)
            {
                r = i;
                break;
            }
            if (a[i] + i >= a[l] + l)
                l = i;
        }
        if (r)
        {
            printf("YES\n%d %d\n", l, r);
            continue;
        }
        puts("NO");
    }
    return 0;
}