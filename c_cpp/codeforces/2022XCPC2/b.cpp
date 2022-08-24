#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
int n, a, b;
int fa[1005];

int findFa(int *fa, int x)
{
    return fa[x] == x ? x : fa[x] = findFa(fa, fa[x]);
}

void merge(int *fa, int x, int y)
{
    fa[findFa(fa, x)] = findFa(fa, y);
}

int main()
{
    scanf("%d%d%d", &n, &a, &b);
    return 0;
}