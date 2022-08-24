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

//p += base * x;
void solve(struct bigInt *p, struct bigInt *base, int x)
{
    int tmp = 0, len = max(p->len, base->len);
    F(i, 1, len)
    {
        p->a[i] += base->a[i] * x + tmp;
        tmp = p->a[i] / 10, p->a[i] %= 10;
    }
    while (tmp)
    {
        p->a[++len] = tmp % 10;
        tmp /= 10;
    }
    p->len = len;
}

//p *= x;
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
        p->a[++p->len] = tmp % 10;
        tmp /= 10;
    }
}

void printBigInt(const struct bigInt *p)
{
    for (int i = p->len; i >= 1; --i) printf("%d", p->a[i]);
}

int n, len;
char s[1005];

int main()
{
    scanf("%d%s", &n, s);
    len = strlen(s);
    for (int i = len - 1; i >= 0; --i)
    {
        if (isdigit(s[i]))
        {
            solve(&ans, &base, s[i] - '0');
            mul(&base, n);
        }
        else
        {
            solve(&ans, &base, s[i] - 'A' + 10);
            mul(&base, n);
        }
    }
    printBigInt(&ans);
    return 0;
}