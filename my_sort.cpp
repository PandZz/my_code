#include <bits/stdc++.h>
using namespace std;
#define R register int
const int maxn = 1e5;
int n;
int a[maxn + 1], b[maxn + 1];

void my_sort(int beg, int end)
{
    if (beg == end) return ;
    int mid = (beg + end) / 2, len = end - beg + 1;
    my_sort(beg, mid), my_sort(mid + 1, end);
    R i = beg, j = mid + 1, k = 0;
    for (k = 0; k < len && i <= mid && j <= end; ++k)
    {
        if (a[i] <= a[j]) b[k] = a[i], ++i;
        else b[k] = a[j], ++j;
    }
    while (i <= mid) {b[k] = a[i], ++k, ++i;}
    while (j <= end) {b[k] = a[j], ++k, ++j;}
    for (k = 0; k < len; ++k) a[beg + k] = b[k];
    return ;
}

int main()
{
    scanf("%d", &n);
    for (R i = 1; i <= n; ++i) scanf("%d", &a[i]);
    my_sort(1, n);
    for (R i = 1; i <= n; ++i) printf("%d ", a[i]);
    return 0;
}