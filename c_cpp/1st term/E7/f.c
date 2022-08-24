#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;

int len;
char s[105], ansPtrType[105], ansPtrName[105], ansElemType[105];
//ansPtrType: 1.type* 2.type(*)[num] 3.type** 4.type(*)(...)
//ansPtrName: string
//ansElemType: one "*"/"(*)" less than ansPtrType

char* getBaseType(char **p)
{
    char *ans = (char *)malloc(sizeof(char) * 10);
    memset(ans, 0, sizeof(char) * 10);
    switch (**p)
    {
        case 'i':
            *p += 3;
            strcpy(ans, "int");
            break;
        case 'c':
            *p += 4;
            strcpy(ans, "char");
            break;
        case 'd':
            *p += 6;
            strcpy(ans, "double");
    }
    return ans;
}

char* getName(char **p)
{
    char *ans = (char *)malloc(sizeof(char) * 105);
    memset(ans, 0, sizeof(char) * 105);
    char *ptrAns = ans;
    while (isalpha(**p))
    {
        *ptrAns = **p;
        ptrAns++, (*p)++;
    }
    return ans;
}

char* getNum(char **p)
{
    char *ans = (char *)malloc(sizeof(char) * 105);
    memset(ans, 0, sizeof(char) * 105);
    char *ptrAns = ans;
    *ptrAns = '[', ++ptrAns, ++(*p);
    while (isdigit(**p))
    {
        *ptrAns = **p;
        ptrAns++, (*p)++;
    }
    *ptrAns = ']', ++(*p);
    return ans;
}

int main()
{
    // freopen("std.in", "r", stdin);
    char *p, *tmp;
    while (~scanf("%s", s))
    {
        // puts("fuck");
        memset(ansPtrType, 0, sizeof(ansPtrType));
        memset(ansPtrName, 0, sizeof(ansPtrName));
        memset(ansElemType, 0, sizeof(ansElemType));
        len = strlen(s);
        p = s;
        while (p - s < len)
        {
            tmp = getBaseType(&p);
            strcpy(ansPtrType, tmp);
            strcpy(ansElemType, tmp);
            free(tmp);
            if (*p == '*')
            {
                ++p, strcat(ansPtrType, "*");
                if (*p == '*')
                {
                    strcat(ansElemType, "*");
                    strcat(ansPtrType, "*");
                    ++p;
                }
                tmp = getName(&p);
                strcpy(ansPtrName, tmp);
                free(tmp);
            }
            else
            {
                strcat(ansPtrType, "(*)"), p += 2;
                tmp = getName(&p);
                strcpy(ansPtrName, tmp);
                free(tmp);
                ++p;
                if (*p == '[')
                {
                    while (*p == '[')
                    {
                        tmp = getNum(&p);
                        strcat(ansPtrType, tmp), strcat(ansElemType, tmp);
                        free(tmp);
                    }
                }
                else
                {
                    ++p;
                    strcat(ansPtrType, "("), strcat(ansElemType, "(");
                    if (*p != ')')
                    {
                        tmp = getBaseType(&p);
                        strcat(ansPtrType, tmp), strcat(ansElemType, tmp);
                        free(tmp);
                        while (*p == ',')
                        {
                            strcat(ansPtrType, ","), strcat(ansElemType, ","), ++p;
                            tmp = getBaseType(&p);
                            strcat(ansPtrType, tmp), strcat(ansElemType, tmp);
                            free(tmp);
                        }
                    }
                    strcat(ansPtrType, ")"), strcat(ansElemType, ")");
                    ++p;
                }
            }
        }
        printf("%s %s -> %s\n", ansPtrType, ansPtrName, ansElemType);
        memset(s, 0, sizeof(s));
    }
    return 0;
}