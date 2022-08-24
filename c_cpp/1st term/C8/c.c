#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
#define N 1000000

int prime[N + 5] = {0, 2, 3, 5}, n = 3, L;

int check(int x)
{
    int lim = sqrt(x) + 1, i = 1;
    while (prime[i] <= lim && i <= n)
    {
        if (x % prime[i] == 0) return 0;
        ++i;
    }
    return 1;
}

int main()
{
    scanf("%d", &L);
    int k = 1, tot = 0, ans = 0, tmp;
    if (L <= 10)
    {
        F(i, 1, 3)
            if (tot + prime[i] <= L) tot += prime[i], ++ans;
        printf("%d\n", ans);
        return 0;
    }
    tot = 10, ans = 3;
    while (tot <= L)
    {
        tmp = k * 6 + 1;
        if (tot + tmp > L) break;
        if (check(tmp)) prime[++n] = tmp, tot += tmp, ++ans;
        tmp = k * 6 + 5;
        if (tot + tmp > L) break;
        if (check(tmp)) prime[++n] = tmp, tot += tmp, ++ans;
        ++k;
    }
    // F(i, 1, n) printf("%d\n", prime[i]);
    printf("%d\n", ans);
    return 0;
}