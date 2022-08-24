#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int l = 1;
char format[20] = "%%";
int main()
{
    int k, x;
    double m;
    scanf("%d%d%lf", &k, &x, &m);
    if (k < 10) format[l++] = k + '0';
    else format[l++] = k / 10 + '0', format[l++] = k % 10 + '0';
    format[l++] = '.';
    if (x < 10) format[l++] = x + '0';
    else format[l++] = '1', format[l++] = '0';
    strcat(format, "lf");
    printf("%s\n", format);
    printf(format, m);
    return 0;
}