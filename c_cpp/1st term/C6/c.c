#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int main()
{
    int n, l, s = 0;
    char type[15];
    scanf("%d%d", &n, &l);
    getchar();
    F(i, 1, n)
    {
        gets(type);
        // puts(type);
        switch (type[0])
        {
            case 'c': s += 1; break;
            case 'i': s += 4; break;
            case 'd': s += 8; break;
            case 'l': s += 8; break;
        }
    }
    printf("%d\n", s * l);
    return 0;
}