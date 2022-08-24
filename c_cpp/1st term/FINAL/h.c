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
int n, w, h, wo, ho;
char o[10][10], ans[2][3001][3001], ch;

void myCpy(int a1, int a2, int x, int y, int w, int h)
{
    F(i, 0, h - 1)
        F(j, 0, w - 1) ans[a2][x + i][y + j] = ans[a1][i][j];
}

void paintSpace(int a1, int x, int y, int w, int h)
{
    F(i, 0, h - 1)
        F(j, 0, w - 1) ans[a1][x + i][y + j] = ' ';
}

void print(int a1)
{
    F(i, 0, h - 1)
    {
        F(j, 0, w - 1)
        {
            if (isgraph(ans[a1][i][j])) printf("%c", ans[a1][i][j]);
            else putchar(' ');
        }
        printf("\n");
    }
}

int main()
{
    scanf("%d", &n);
    int i = 0;
    getchar();
    while (gets(o[i]) != NULL) ++i;
    ho = i;
    F(j, 0, ho - 1) wo = max(wo, strlen(o[j]));
    F(i, 0, ho - 1)
    {
        F(j, 0, wo - 1)
        {
            if (isgraph(o[i][j])) ch = o[i][j];
            if (ch) break;
        }
        if (ch) break;
    }
    F(i, 0, ho - 1)
        F(j, 0, wo - 1)
        {
            if (isgraph(o[i][j])) ans[0][i][j] = o[i][j];
            else ans[0][i][j] = ' ';
        }
    w = wo, h = ho;
    if (n == 1) { printf("%c\n", ch); return 0; }
    if (n == 2) { print(0); return 0; }
    int last = 0;
    F(k, 3, n)
    {
        F(i, 0, ho - 1)
            F(j, 0, wo - 1)
            {
                if (isgraph(o[i][j])) myCpy(last, last ^ 1, i * h, j * w, w, h);
                else paintSpace(last ^ 1, i * h, j * w, w, h);
            }
        w *= wo, h *= ho, last ^= 1;
    }
    print(last);
    return 0;
}