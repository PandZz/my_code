#include <iostream>
#include <algorithm>
#define R register int
using namespace std;
const int maxn = 1000;

struct obj
{
    int v, w;
} b[maxn * 10 + 1];

int n, V, N, ans;
int f[maxn * 10 + 1];
int main()
{
    cin >> n >> V;
    int v, w;
    for (R i = 1; i <= n; ++i)
    { 
        cin >> v >> w;
        while (v <= V)
        {
            N++;
            b[N].v = v, b[N].w = w;
            v += v, w += w;
        }
    }
    for (R i = 1; i <= N; ++i)
    {
        for (R j = V; j >= b[i].v; --j)
        {
            f[j] = max(f[j], f[j - b[i].v] + b[i].w);
            ans = max(ans, f[j]);
        }
    }
    cout << ans << "\n";
    return 0;
}