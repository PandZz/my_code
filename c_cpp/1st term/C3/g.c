#include <stdio.h>
int a[20001];
int main()
{
    int ls, s = 0;
    for (int i = 1; i <= 20000; ++i)
    {
        ls = i, s = 0;
        while (ls)
        {
            if (ls % 10 == 2 ||ls % 10 == 1 || ls % 10 == 7) ++s;
            ls /= 10;
        }
        if (s == 1 || s == 2 || s == 7) a[i] = 1;
    }
    int n, l, r;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &l, &r);
        for (int i = l; i <= r; ++i)
        {
            if (a[i])
            {
                printf("%d ", i);
                a[i] = 0;
            }
        }
        putchar('\n');
    }
    return 0;
}