#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;
char key[100];
int code[30], flag[30], kn, cn;
int main()
{
    FILE *fr, *fw;
    scanf("%s", key);
    kn = strlen(key);
    // key[kn--] = '\0';
    fr = fopen("encrypt.txt", "r");
    fw = fopen("output.txt", "w");
    if (fr == NULL || fw == NULL)
        return -1;
    for (int i = 0; i < kn; ++i)
    {
        if (!flag[key[i] - 'a'])
        {
            code[cn++] = key[i] - 'a';
            flag[key[i] - 'a'] = 1;
        }
    }
    for (int i = 25; i >= 0; --i)
    {
        if (!flag[i])
        {
            code[cn++] = i;
            flag[i] = 1;
        }
    }
    /* for (int i = 0; i < 26; ++i)
        printf("|%c", i + 'a');
    puts("");
    for (int i = 0; i < 26; ++i)
        printf("|%c", code[i] + 'a'); */
    char ch;
    while ((ch = fgetc(fr)) != EOF)
    {
        // printf("%c", ch);
        if (islower(ch))
            ch = code[ch - 'a'] + 'a';
        fputc(ch, fw);
    }
    fclose(fr);
    fclose(fw);
    return 0;
}