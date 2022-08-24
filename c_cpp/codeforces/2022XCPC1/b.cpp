#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
int t, n, x;
int a[100005];
int main()
{
    scanf("%d", &t);
    int maxa, ans;
    while (t--)
    {
        maxa = ans = 0;
        scanf("%d%d", &n, &x);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", a + i);
            maxa = max(maxa, a[i]);
        }
        if (maxa <= x)
        {
            ans = x / maxa;
            if (x % maxa)
                ++ans;
            printf("%d\n", ans);
        }
        else
        {
            for (int i = 1; i <= n; ++i)
                if (a[i] == x)
                    ans = 1;
            if (!ans)
                ans = 2;
            printf("%d\n", ans);
        }
    }
    return 0;
}