#include <iostream>
#include <algorithm>
using namespace std;
#define R register int
const int maxn = 1005;
int N, V, ans;
int w[maxn], v[maxn], f[maxn];
int main()
{
    cin >> N >> V;
    for (R i = 1; i <= N; ++i) cin >> v[i] >> w[i];
    for (R i = 1; i <= N; ++i)
        for (R j = V; j >= v[i]; --j)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    for (R i = 1; i <= V; ++i) ans = max(ans, f[i]);
    cout << ans << "\n";
    return 0;
}