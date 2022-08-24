#include <stdio.h>
typedef long long LL;
const LL mod = 1e9 + 7;

LL myPow(LL p)
{
    LL ans = 1, base = 2;
    while (p)
    {
        if (p & 1) ans = ans * base % mod;
        base = base * base % mod, p >>= 1;
    }
    return ans;
}

int main()
{
    LL n, k, m, ans1 = 1, ans2 = 1, ls;
    scanf("%lld%lld%lld", &n, &k, &m);
    for (int i = 0; i < k; ++i)
    {
        ls = m & 1, m >>= 1;
        if (ls)
        {
            ans2 *= (myPow(n) - 1) % mod;
            ans2 %= mod;
        }
        else
        {
            ans1 *= (myPow(n) - 1) % mod;
            ans1 %= mod;
        }
    }
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}