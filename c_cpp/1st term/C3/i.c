#include <stdio.h>
#include <string.h>
int main()
{
    int t, len, flag;
    char a[105];
    scanf("%d", &t);
    // printf("t = %d", t);
    while (t--)
    {
        scanf("%s", a + 1);
        // printf("s = %s", a + 1);
        len = strlen(a + 1);
        flag = 0;
        for (int i = 1; i <= len; ++i)
        {
            if ((a[i] - '0') == 0 || (a[i] - '0') == 8)
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            puts("yes");
            continue;
        }
        for (int i = 1; i <= len; ++i)
            for (int j = i + 1; j <= len; ++j)
                if (!((2 * (a[i] - '0') + (a[j] - '0')) % 8))
                {
                    flag = 1;
                    break;
                }
        if (flag)
        {
            puts("yes");
            continue;
        }
        for (int i = 1; i <= len; ++i)
            for (int j = i + 1; j <= len; ++j)
                for (int k = j + 1; k <= len; ++k)
                if (!((4 * (a[i] - '0') + 2 * (a[j] - '0') + (a[k] - '0')) % 8))
                {
                    flag = 1;
                    break;
                }
        if (flag)
        {
            puts("yes");
            continue;
        }
        puts("no");
    }
    return 0;
}