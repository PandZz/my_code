#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
LL a[2], b[2], c[2];
int main()
{
    scanf("%lld%lld%lld%lld%lld%lld", a, a + 1, b, b + 1, c, c + 1);
    LL A, B, C;
    A = a[0] * a[0] + a[1] * a[1] - a[0] * b[0] * 2 - a[1] * b[1] * 2;
    B = c[0] * c[0] + c[1] * c[1] - c[0] * b[0] * 2 - c[1] * b[1] * 2;
    C = (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    if (A == B && C != 0)
        puts("YES");
    else
        puts("NO");
    return 0;
}