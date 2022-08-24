#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int main()
{
    char ch[5];
    int a = 0, b = 0;
    while (~scanf("%s", ch))
    {
        // len = strlen(ch);
        if (ch[0] == 'A') ++a;
        b += ch[0] != 'C';
    }
    printf("%.3lf\n", (double)a / b);
    return 0;
}