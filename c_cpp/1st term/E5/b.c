#include <stdio.h>
long long f[45];
int main()
{
    int n, p, q, A, B, C;
    scanf("%d%d%d%d%d%d", &n, &p, &q, &A, &B, &C);
    f[1] = p, f[2] = q;
    for (int i = 3; i <= n; ++i)
    {
        f[i] = f[i - 1] * A + f[i - 2] * B + C;
    }
    printf("%lld\n",  f[n]);
    return 0;
}