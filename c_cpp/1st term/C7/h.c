#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
#define swap(a, b) (a ^= b, b ^= a, a ^= b)
typedef long long LL;
int a[1001][1001], n;
int x[3], y[3], s;

int check(int m1, int n1, int m2, int n2)
{
    swap(a[m1][n1], a[m2][n2]);
    int tmp;
    F(i, 1, n)
    {
        tmp = 0;
        F(j, 1, n) tmp += a[i][j];
        if (tmp != s) { swap(a[m1][n1], a[m2][n2]); return 0; }
    }
    F(j, 1, n)
    {
        tmp = 0;
        F(i, 1, n) tmp += a[i][j];
        if (tmp != s) { swap(a[m1][n1], a[m2][n2]); return 0; }
    }
    return 1;
}

int main()
{
    scanf("%d", &n);
    F(i, 1, n)
        F(j, 1, n) scanf("%d", &a[i][j]);
    int tmp;
    s = n * (1 + n * n) / 2;
    F(i, 1, n)
    {
        if (x[0] > 2) break;
        tmp = 0;
        F(j, 1, n) tmp += a[i][j];
        if (tmp != s) x[++x[0]] = i;
    }
    F(j, 1, n)
    {
        if (y[0] > 2) break;
        tmp = 0;
        F(i, 1, n) tmp += a[i][j];
        if (tmp != s) y[++y[0]] = j;
    }
    if (x[0] == 0)
    {
        F(i, 1, n)
        {
            swap(a[i][y[1]], a[i][y[2]]);
            tmp = 0;
            F(j, 1, n) tmp += a[j][y[1]];
            if (tmp == s)
            {
                printf("%d %d\n%d %d", i, y[1], i, y[2]);
                break;
            }
            swap(a[i][y[1]], a[i][y[2]]);
        }
    }
    else if (y[0] == 0)
    {
        F(j, 1, n)
        {
            swap(a[x[1]][j], a[x[2]][j]);
            tmp = 0;
            F(i, 1, n) tmp += a[x[1]][i];
            if (tmp == s)
            {
                printf("%d %d\n%d %d", x[1], j, x[2], j);
                break;
            }
            swap(a[x[1]][j], a[x[2]][j]);
        }
    }
    else
    {
        if (check(x[1], y[1], x[2], y[2])) printf("%d %d\n%d %d\n", x[1], y[1], x[2], y[2]);
        else if (check(x[1], y[2], x[2], y[1])) printf("%d %d\n%d %d\n", x[1], y[2], x[2], y[1]);
    }
    return 0;
}