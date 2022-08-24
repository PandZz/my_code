#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;

int che[22][22];

int check(int x, int y)
{
    int c = che[x][y], f = 1;
    F(i, 1, 3)
    if (che[x][y + i] != c)
    {
        f = 0;
        break;
    }
    if (f == 1 && (che[x][y - 1] == 0 || che[x][y + 4] == 0))
        return 1;
    f = 1;
    F(i, 1, 3)
    if (che[x + i][y] != c)
    {
        f = 0;
        break;
    }
    if (f == 1 && (che[x - 1][y] == 0 || che[x + 4][y] == 0))
        return 1;
    f = 1;
    F(i, 1, 3)
    if (che[x + i][y + i] != c)
    {
        f = 0;
        break;
    }
    if (f == 1 && (che[x - 1][y - 1] == 0 || che[x + 4][y + 4] == 0))
        return 1;
    f = 1;
    F(i, 1, 3)
    if (che[x + i][y - i] != c)
    {
        f = 0;
        break;
    }
    if (f == 1 && (che[x - 1][y + 1] == 0 || che[x + 4][y - 4] == 0))
        return 1;
    return 0;
}

int main()
{
    F(i, 1, 19)
    F(j, 1, 19)
    scanf("%d", &che[i][j]);
    F(j, 0, 20)
    che[0][j] = che[20][j] = 3;
    F(i, 0, 20)
    che[i][0] = che[i][20] = 3;
    /*
        F(i, 0, 20)
        {
            F(j, 0, 20)
            printf("%d ", che[i][j]);
            printf("\n");
        }
    */
    F(i, 1, 19)
    F(j, 1, 19)
    if (che[i][j] && check(i, j))
    {
        printf("%d:%d,%d\n", che[i][j], i, j);
        return 0;
    }
    puts("No");
    return 0;
}