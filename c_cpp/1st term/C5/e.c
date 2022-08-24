#include <stdio.h>

double gpa(int x)
{
    if (x < 60) return 0;
    if (x == 60) return 1;
    x = 100 - x;
    return 4 - 3.0 * x * x / 1600;
}

int main()
{
    int n, x, h;
    double a = 0, b = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d%d", &x, &h);
        a += gpa(x) * h, b += h;
    }
    printf("%.2lf\n", a / b);
    return 0;
}