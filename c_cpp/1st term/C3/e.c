#include <stdio.h>
int main()
{
    unsigned long long a, b;
    scanf("%llu%llu", &a, &b);
    int ans = 0;
    for (int i = 1; i <= 64; ++i)
    {
        ans += ((a & 1) ^ (b & 1));
        a >>= 1, b >>= 1;
    }
    printf("%d", ans);
    return 0;
}