#include <stdio.h>

long long f(long long x)
{
    long long s = 0;
    while (x)
    {
        s += x & 1;
        x >>= 1;
    }
    return s;
}

int main()
{
    long long n;
    while (~scanf("%lld", &n))
        printf("%lld\n", f(f(f(n))));
    return 0;
}