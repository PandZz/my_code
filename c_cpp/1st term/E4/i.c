#include <math.h>
#include <stdio.h>
typedef long long LL;

LL solve(LL x)
{
    LL i = 2LL, ans = 1LL;
    while (i <= (LL)sqrt(x))
    {
        if (!(x % i))
        {
            // printf("i=%d\n", i);
            ans *= (i - 1);
            x /= i;
            while (!(x % i) && x > 1)
            {
                ans *= i;
                x /= i;
            }
        }
        ++i;
    }
    if (x > 1) ans *= x - 1;
    return ans;
}

int main()
{
    LL n;
    scanf("%lld", &n);
    printf("%lld\n", solve(n));
    return 0;
}