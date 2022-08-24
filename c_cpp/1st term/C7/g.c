#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int a[200005], n, k;
const int N = 100000;
int main()
{
    scanf("%d%d", &n, &k);
    int tmp, s = 0;
    F(i, 1, k)
    {
        scanf("%d", &tmp);
        a[tmp + N]++;
    }
    tmp = k / n;
    F(i, 0, 200000) s += a[i] > 0;
    if (s <= tmp) printf("%d", s);
    else printf("%d", tmp);
    return 0;
}