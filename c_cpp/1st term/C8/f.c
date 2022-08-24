#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
const double t = 0.618, eps = 1e-6;

int n, a[11], L, R;

double f(double x)
{
    double ans = a[0], tmp = x;
    F(i, 1, n) ans += tmp * a[i], tmp *= x;
    return ans;
}

double myAbs(double x) { return x > 0 ? x : -x; }

int main()
{
    scanf("%d", &n);
    for (int i = n; i >= 0; --i) scanf("%d", a + i);
    scanf("%d%d", &L, &R);
    double l = L, r = R, mid, del = r - l, lam = l + (1 - t) * del, miu = l + t * del;
    double fLam, fMiu;
    while (r - l >= eps)
    {
        fLam = f(lam), fMiu = f(miu);
        if (myAbs(fLam - fMiu) <= 1e-9 || fLam < fMiu)
        {
            r = miu, miu = lam;
            del = r - l;
            lam = l + (1 - t) * del;
        }
        else
        {
            l = lam, lam = miu;
            del = r - l;
            miu = l + t * del;
        }
    }
    mid = (l + r) / 2;
    // printf("%.4lf\n", f(-0.4625));
    printf("f(%.4lf)=%.4lf\n", mid, f(mid));
    return 0;
}