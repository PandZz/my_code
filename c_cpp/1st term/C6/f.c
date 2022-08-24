#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int a[10][10], flag[10];

int check()
{
    F(i, 1, 9) if (!flag[i]) return 0;
    return 1;
}

int main()
{
    F(i, 1, 9)
        F(j, 1, 9) scanf("%d", &a[i][j]);
    F(i, 1, 9)
    {
        F(j, 1, 9) flag[j] = 0;
        F(j, 1, 9) flag[a[i][j]] = 1;
        if (!check()) { puts("Emergency food! ~>_<~"); return 0; }
    }
    F(i, 1, 9)
    {
        F(j, 1, 9) flag[j] = 0;
        F(j, 1, 9) flag[a[j][i]] = 1;
        if (!check()) { puts("Emergency food! ~>_<~"); return 0; }
    }
    int x, y;
    for (int i = 1; i <= 7; i += 3)
        for (int j = 1; j <= 7; j += 3)
        {
            for (int k = 1; k <= 9; ++k) flag[k] = 0;
            for (int m = 0; m < 3; ++m)
                for (int n = 0; n < 3; ++n)
                {
                    x = i + m, y = j + n;
                    flag[a[x][y]] = 1;
                }
            if (!check()) { puts("Emergency food! ~>_<~"); return 0; }
        }
    puts("Cheers! O(^_^)O");
    return 0;
}