#include <stdio.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int s[101], maxN = -1, maxI, minN = 101, minI, tot;

int main()
{
    int a, i = 0;
    while (~scanf("%d", &a) && ~a)
    {
        if (0 <= a && a <= 100)
        {
            i++;
            s[a]++;
            tot += a;
            if (a >= maxN) { maxN = a; maxI = i; }
            if (a <= minN) { minN = a; minI = i; }
        }
    }
    printf("count: %d\nave: %.4lf\nmax: %d: %d\nmin: %d: %d\n", i, (double)tot / i, maxI, maxN, minI, minN);
    i = 0;
    for (int j = 0; j <= 100; ++j)
        if (s[j] >= s[i]) i = j;
    printf("mode: %d\n", i);
    return 0;
}