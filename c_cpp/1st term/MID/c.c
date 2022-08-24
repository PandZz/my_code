#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int main()
{
    int k, s = 1;
    scanf("%d", &k);
    printf("%d\n", k);
    while (k > 1 && s < 100)
    {
        if (k & 1) k = 3 * k + 1;
        else k >>= 1;
        printf("%d\n", k), s++;
    }
    return 0;
}