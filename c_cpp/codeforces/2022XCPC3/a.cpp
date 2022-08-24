#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
char str[105];
int len;
int ans;
char s[11];

bool myFind()
{
    int i = 1, j = 1;
    for (; i <= len; ++i)
        if (str[i] == s[j])
            ++j;
    return j > 10;
}

void dfs(int x, int state)
{
    if (x > 10)
    {
        ans += myFind();
        return;
    }
    for (int i = 0; i < 10; ++i)
    {
        if (((1 << i) & state) == 0)
        {
            s[x] = i + '0';
            dfs(x + 1, state | (1 << i));
        }
    }
}

int main()
{
    cin >> str + 1;
    len = strlen(str + 1);
    dfs(1, 0);
    cout << ans << endl;
    return 0;
}