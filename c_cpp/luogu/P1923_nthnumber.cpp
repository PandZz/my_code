#include <cstdio>
using namespace std;
const int N = 5e6;
// const int N = 10;
int n, k, a[N + 5];

inline void swap(int &a, int &b)
{
    if (a == b)
        return;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

int find(int l, int r, int k)
{
    if (l == r)
        return a[l];
    int mid = a[(l + r) / 2], i = l, j = r, s;
    while (i <= j)
    {
        while (a[i] < mid)
            ++i;
        while (a[j] > mid)
            --j;
        if (i <= j)
        {
            swap(a[i], a[j]);
            ++i, --j;
        }
    }
    s = j - l + 1;
    if (k <= s)
        return find(l, j, k);
    else
        return find(i, r, k - s);
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    printf("%d\n", find(1, n, k + 1));
    return 0;
}