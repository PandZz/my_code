#include <stdio.h>
int a, k, p;

int myPower()
{
    long long ans = 1;
    while (k)
    {
        if (k & 1) ans = ((long long)ans * a) % p;
        a = ((long long)a * a) % p, k >>= 1;
    }
    return ans;
}

int main()
{
    scanf("%d%d%d", &a, &k, &p);
    printf("%d\n", myPower());
    return 0;
}