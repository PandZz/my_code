#include <stdio.h>
#define myAbs(x) (x > 0 ? x : -x)
typedef long long LL;
LL a, b, c, d;

LL gcd(LL x, LL y) { return !x ? y : gcd(y % x, x); }
LL lcm(LL x, LL y) { return x / gcd(x, y) * y; }

int main()
{
    LL ls, ca, A, B;
    while (~scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d))
    {
        ls = gcd(a, b), ls = myAbs(ls);
        a /= ls, b /= ls;
        ls = gcd(c, d), ls = myAbs(ls);
        c /= ls, d /= ls;
        B = lcm(b, d);
        ls = B / b;
        A = a * ls;
        ls = B / d;
        A += c * ls;
        ls = gcd(A, B), ls = myAbs(ls);
        A /= ls, B /= ls;
        printf("%lld/%lld\n", A, B);
    }
    return 0;
}