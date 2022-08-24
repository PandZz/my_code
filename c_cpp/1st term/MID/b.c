#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int a[105];
int main()
{
    int n;
    scanf("%d", &n);
    F(i, 1, n) scanf("%d", a + i);
    printf("a[]={%d", a[n]);
    for (int i = n - 1; i >= 1; --i) printf(",%d", a[i]);
    printf("};");
    return 0;
}