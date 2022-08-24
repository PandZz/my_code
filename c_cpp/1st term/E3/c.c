#include <stdio.h>
typedef long long LL;
LL n, a[4], b[4], c[4];

int isP(int l1, int l2)
{
    return a[l1] * b[l2] == a[l2] * b[l1] && (a[l1] * c[l2] != a[l2] * c[l1] || b[l1] * c[l2] != b[l2] * c[l1]);
}

int check()
{
    LL  yy1 = (c[1] * a[2] - c[2] * a[1]) * (b[3] * a[2] - b[2] * a[3]),\
        yy2 = (c[3] * a[2] - c[2] * a[3]) * (b[1] * a[2] - b[2] * a[1]),\
        xx1 = (c[1] * b[2] - c[2] * b[1]) * (a[3] * b[2] - a[2] * b[3]),\
        xx2 = (c[3] * b[2] - c[2] * b[3]) * (a[1] * b[2] - a[2] * b[1]);
    return yy1 == yy2 && xx1 == xx2;
}

int main()
{
    LL flag;
    scanf("%lld", &n);
    for (LL i = 1; i <= n; ++i)
    {
        for (LL j = 1; j <= 3; ++j) scanf("%lld%lld%lld", a + j, b + j, c + j);
        if (isP(1, 2) || isP(1, 3) || isP(2, 3))
        {//若有一对直线没有交点，一定是nice data
            puts("A nice test data ~");
            continue;
        }
        if (check()) puts("Could be a bug!");
        else puts("A nice test data ~");
    }
    return 0;
}