#include <stdio.h>
#define mod -2

void solve(int x)
{
    if (!x) return ;
    int temp = x % mod;
    if (temp < 0)
    {
        temp -= mod;
        solve(x / mod + 1);
        printf("%d", temp);
    }
    else
    {
        solve(x / mod);
        printf("%d", temp);
    }
    return ;
}

int main()
{
    int n, t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        if (!n) { puts("0"); continue; }
        solve(n);
        putchar('\n');
    }
    return 0;
}