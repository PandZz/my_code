#include <stdio.h>
int main()
{
    int t, n, x, y, ls, f, cnt = 0;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        ls = 2147483647, f = 1, ++cnt;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d%d", &x, &y);
            if (x == ls) f = 0;
            ls = x;
        }
        if (f) printf("Case #%d: Through the star sea.\n", cnt);
        else printf("Case #%d: Stop somewhere.\n", cnt);
    }
    return 0;
}