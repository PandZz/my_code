#include <stdio.h>
typedef long long LL;
LL n, ans;
int main()
{
    scanf("%lld", &n);
    for (LL i = 1; i < n; ++i)
    {
        ans += n / i - !(n % i);
    }
    printf("%lld", ans);
    return 0;
}