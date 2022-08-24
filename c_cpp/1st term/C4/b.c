#include <stdio.h>
int main()
{
    int t, y, m;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &y, &m);
        if (m != 2)
        {
            if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) puts("31");
            else puts("30");
        }
        else
        {
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) puts("29");
            else puts("28");
        }
    }
    return 0;
}