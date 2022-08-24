#include <stdio.h>
#include <string.h>
int main()
{
    char ch[120];
    scanf("%s", ch + 1);
    int len = strlen(ch + 1);
    int i = 1;
    while (ch[i] == 'w') ++i;
    while (ch[i] == 'b') ++i;
    if (i > len) puts("Yes");
    else puts("No");
    return 0;
}