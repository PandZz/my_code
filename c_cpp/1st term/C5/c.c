#include <math.h>
#include <stdio.h>
#define p(x) ((x) * (x))
int x[5], y[5], z[5];

double dis(int a, int b)
{
    return sqrt(p(x[a] - x[b]) + p(y[a] - y[b]) + p(z[a] - z[b]));
}

int main()
{
    for (int i = 1; i <= 4; ++i) scanf("%d%d%d", x + i, y + i, z + i);
    // for (int i = 1; i <= 4; ++i) printf("%d %d %d\n", x[i], y[i], z[i]);
    printf("%.2lf\n", dis(2, 4));
    printf("%.2lf\n", dis(1, 3));
    printf("%.2lf\n", dis(2, 3));
    printf("%.2lf\n", dis(3, 4));
    printf("%.2lf\n", dis(1, 2));
    printf("%.2lf\n", dis(1, 4));
    return 0;
}