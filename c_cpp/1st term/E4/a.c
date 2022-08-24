#include <stdio.h>

int gcd(int a, int b){ return !b ? a : gcd(b, a % b); }

int main()
{
    int n, a, b;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &a, &b);
        printf("%lld\n", (long long)(a / gcd(a, b)) * (long long)b);
    }
    return 0;
}