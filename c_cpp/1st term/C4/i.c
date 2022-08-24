#include <stdio.h>

int f[10001];

int main()
{
    int n, k, tot, pos, i, ls;
    scanf("%d%d", &n, &k);
    tot = n, pos = n - 2;
    while (tot > 1)
    {
        for (i = 1; i < k; ++i)
        {
            ls = (pos + 1) % n;
            while (f[ls]) ls = (ls + 1) % n;
            pos = ls;
        }
        f[pos] = 1, --tot;
        ls = (pos + 1) % n;
        while (f[ls]) ls = (ls + 1) % n;
        pos = ls;
    }
    printf("%d\n", pos + 1);
    return 0;
}