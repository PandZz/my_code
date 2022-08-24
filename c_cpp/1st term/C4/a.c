#include <stdio.h>
int main()
{
    int score;
    scanf("%d", &score);
    if (0 <= score && score < 60) putchar('F');
    else if (60 <= score && score < 70) putchar('D');
    else if (70 <= score && score < 80) putchar('C');
    else if (80 <= score && score < 90) putchar('B');
    else if (90 <= score && score <= 100) putchar('A');
    return 0;
}