#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
double x[105], y[105], theta;
int n;
int main()
{
    scanf("%d", &n);
    F(i, 1, n) scanf(" (%lf,%lf)", x + i, y + i);
    scanf(" theta=%lf", &theta);
    double s = sin(theta), c = cos(theta), nx, ny;
    F(i, 1, n)
    {
        nx = x[i] * c + y[i] * s;
        ny = y[i] * c - x[i] * s;
        x[i] = nx, y[i] = ny;
    }
    F(i, 1, n) printf("(%.2lf,%.2lf)\n", x[i], y[i]);
    return 0;
}