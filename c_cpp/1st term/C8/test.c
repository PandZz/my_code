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

struct bigInt
{
    int len, a[2005];
} ans = {0, {}}, base = {1, {0, 1}};

void solve(struct bigInt *p, struct bigInt *base, int x)
{
    int tmp = 0;
    F(i, 1, base->len)
    {
        p->a[i] += base->a[i] * x + tmp;
        tmp = p->a[i] * x / 10;
    }
    p->a[(base->len) + 1] += tmp;
    p->len = max(p->len, base->len);
    F(i, 1, p->len)
    {
        p->a[i + 1] += p->a[i] / 10;
        p->a[i] %= 10;
    }
    while (p->a[(p->len) + 1])
    {
        ++(p->len);
        p->a[(p->len) + 1] += p->a[p->len] / 10;
        p->a[p->len] %= 10;
    }
}

void mul(struct bigInt *p, int x)
{
    int tmp = 0;
    F(i, 1, p->len)
    {
        p->a[i] *= x, p->a[i] += tmp;
        tmp = p->a[i] / 10;
        p->a[i] %= 10;
    }
    while (tmp)
    {
        p->a[++(p->len)] = tmp % 10;
        tmp /= 10;
    }
}

void printBigInt(const struct bigInt *p)
{
    for (int i = p->len; i >= 1; --i) printf("%d", p->a[i]);
}

void convert(struct bigInt *p, int x)
{
    while (x)
    {
        p->a[++(p->len)] = x % 10;
        x /= 10;
    }
}

void clearBigInt(struct bigInt *p)
{
    p->len = 0;
    memset(p->a, 0, sizeof(p->a));
}

int main()
{
    int x;
    while (~scanf("%d", &x))
    {
        mul(&base, x);
        printf("base * x = "), printBigInt(&base), putchar('\n');
    }
    return 0;
}