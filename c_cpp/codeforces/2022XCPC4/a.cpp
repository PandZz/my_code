#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 5005;
int a[N], c[N], n, tagN[N], s[4];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%1d", c + i);
    for (int i = 1; i <= n; ++i)
        scanf("%1d", a + i);
    int tagI;
    for (int i = 1; i <= n; ++i)
    {
        tagI = c[i] + a[i] * 2;
        tagN[i] = tagI;
        s[tagI]++;
    }
    return 0;
}