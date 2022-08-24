#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 3e5;
int n, a[N + 5], m, q[N + 5];
LL tot;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i), tot += a[i];
    scanf("%d", &m);
    for (int i = 1; i <= m; ++i)
        scanf("%d", q + i);
    sort(a + 1, a + 1 + n, greater<int>());
    for (int i = 1; i <= m; ++i)
        printf("%lld\n", tot - a[q[i]]);
    return 0;
}