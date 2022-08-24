#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;
int main()
{
    FILE *fp = fopen("bgstations.txt", "r");
    char str[100];
    for (int i = 1; i <= 10; ++i)
    {
        fgets(str, 100, fp);
        puts(str);
    }
    return 0;
}