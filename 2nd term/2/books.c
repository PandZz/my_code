#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
typedef long long LL;
typedef struct books
{
    char name[55], author[25], press[35], date[15];
} book;
book lib[600];
book *index[600];
int n = 0;

void convert(book *, char *);
int cmp(const void *, const void *);
void print(const book *);

int main()
{
    FILE *fr, *fw;
    fr = fopen("books.txt", "r");
    fw = fopen("ordered.txt", "w");
    if (fr == NULL || fw == NULL)
        return -1;
    char tmp[200];
    while (fgets(tmp, 200, fr) != NULL)
    {
        index[n] = lib + n;
        convert(index[n], tmp);
        ++n;
    }
    qsort(index, n, sizeof(book *), cmp);
    fclose(fr);
    fclose(fw);
    return 0;
}

void convert(book *b, char *s)
{
    int len = strlen(s);
    char *p[4] = {b->name, b->author, b->press, b->date};
    for (int i = 0, j = 0; i < len; ++i)
    {
        if (s[i] == ' ')
        {
            ++j;
            continue;
        }
        *p[j] = s[i];
    }
}

int cmp(const void *a, const void *b)
{
    return strcmp(((book *)a)->name, ((book *)b)->name);
}

void print(const book *b)
{
    printf("%-50s ", b->name);
    printf("%-20s ", b->author);
    printf("%-30s ", b->press);
    printf("%-10s\n", b->date);
}