#include <stdio.h>
typedef long long LL;
const LL mod = 998244353;

LL myPow(LL x, LL p)
{
    LL ans = 1;
    while (p)
    {
        if (p & 1) ans *= x, ans %= mod;
        x = (x * x) % mod, p >>= 1;
    }
    return ans;
}

int main()
{
    LL a ,b;
    scanf("%lld%lld", &a, &b);
    printf("%lld\n", myPow(a, myPow(a, b)));
    return 0;
}