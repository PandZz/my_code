#include <stdio.h>

int isTri(int a, int b, int c)
{
    return a + b > c && a + c > b && b + c > a;
}

int isIso(int a, int b, int c)
{
    return (a == b) || (a == c) || (b == c);
}

int main()
{
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (isTri(a, b, c))
    {
        if (isIso(a, b, c))
        {
            if (a == b && a == c) puts("equilateral triangle!");
            else puts("isosceles triangle!");
        }
        else puts("regular triangle!");
    }
    else puts("not a triangle!");
    return 0;
}