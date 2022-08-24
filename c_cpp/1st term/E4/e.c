#include <stdio.h>
#include <string.h>
int f[100][3], len;
// 0 -> r, 1 -> g, 2 -> b
char a[105];

int min(int a,int b) { return a < b ? a : b; }

int main()
{
    gets(a);
    len = strlen(a) - 1;
    f[0][0] = f[0][1] = f[0][2] = 1;
    switch (a[0])
    {
        case 'r':
            f[0][0] = 0;
            break;
        case 'g':
            f[0][1] = 0;
            break;
        case 'b':
            f[0][2] = 0;
            break;
    }
    for (int i = 1; i < len; ++i)
    {
        switch (a[i])
        {
            case 'r':
                f[i][0] = f[i - 1][0];
                f[i][1] = min(f[i - 1][0] + 1, f[i - 1][1] + 1);
                f[i][2] = min(f[i - 1][0] + 1, min(f[i - 1][1] + 1, f[i - 1][2] + 1));
                break;
            case 'g':
                f[i][0] = f[i - 1][0] + 1;
                f[i][1] = min(f[i - 1][0], f[i - 1][1]);
                f[i][2] = min(f[i - 1][0] + 1, min(f[i - 1][1] + 1, f[i - 1][2] + 1));
                break;
            case 'b':
                f[i][0] = f[i - 1][0] + 1;
                f[i][1] = min(f[i - 1][0] + 1, f[i - 1][1] + 1);
                f[i][2] = min(f[i - 1][0], min(f[i - 1][1], f[i - 1][2]));
                break;
        }
    }
    --len;
    printf("%d\n", min(min(f[len][0], f[len][1]), f[len][2]));
    return 0;
}