#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;
int line[10][10], row[10][10], block[10][10], bn[10][10], a[10][10], ns;
struct b
{
    int x, y;
} s[90];
int dfs(int);
int check(int, int, int);
void flag(int, int, int, int);

int main()
{
    for (int i = 1; i <= 9; ++i)
        for (int j = 1; j <= 9; ++j)
        {
            scanf("%d", &a[i][j]);
            if (!a[i][j])
            {
                ++ns;
                s[ns].x = i, s[ns].y = j;
            }
            else
            {
                row[i][a[i][j]] = 1;
                line[j][a[i][j]] = 1;
            }
        }
    int tmp = 0;
    for (int x = 1; x <= 7; x += 3)
        for (int y = 1; y <= 7; y += 3)
        {
            ++tmp;
            for (int i = 0; i < 3; ++i)
                for (int j = 0; j < 3; ++j)
                {
                    bn[x + i][y + j] = tmp;
                    block[tmp][a[x + i][y + j]] = 1;
                }
        }
    dfs(1);
    for (int i = 1; i <= 9; ++i)
    {
        for (int j = 1; j <= 9; ++j)
            printf("%d ", a[i][j]);
        puts("");
    }
    return 0;
}

int check(int n, int x, int y)
{
    if (line[y][n])
        return 0;
    if (row[x][n])
        return 0;
    if (block[bn[x][y]][n])
        return 0;
    return 1;
}

void flag(int c, int n, int x, int y)
{
    line[y][n] = c;
    row[x][n] = c;
    block[bn[x][y]][n] = c;
    a[x][y] = n;
}

int dfs(int step)
{
    if (step > ns)
        return 1;
    int x = s[step].x, y = s[step].y;
    for (int i = 1; i <= 9; ++i)
    {
        if (check(i, x, y))
        {
            flag(1, i, x, y);
            if (dfs(step + 1))
                return 1;
            flag(0, i, x, y);
        }
    }
    return 0;
}
