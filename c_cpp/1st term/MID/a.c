#include <math.h>
#include <stdio.h>
#include <string.h>
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
int main()
{
    char ch;
    scanf("%c", &ch);
    if ('a' <= ch && ch <= 'z') puts("Lowercase letter QAQ..");
    else if ('A' <= ch && ch <= 'Z') puts("Capital! \\^ ^/");
    else if ('0' <= ch && ch <= '9') puts("! Number !");
    else puts("I can't read.");
    return 0;
}