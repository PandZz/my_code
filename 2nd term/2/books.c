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
book *indexL[600];
int n = 0, nLib;

void convert(book *, char *);
int cmp(const void *, const void *);
void print(const book *);
void fprint(FILE *, const book *);
//在指标序号l,r之间寻找第一个>=book *b的指标
int lower_bound(book *, int, int);
//在int pre后面插入book *b
void insert(int, book *);
//从int x位置开始找含有char *s的指标，没有返回-1
int find(int, char *);
//删除int x位置的指标
void del(int);

int main()
{
    FILE *fr, *fw;
    fr = fopen("books.txt", "r");
    fw = fopen("ordered.txt", "w");
    if (fr == NULL || fw == NULL)
        return -1;
    char tmpS[200];
    while (fgets(tmpS, 200, fr) != NULL)
    {
        indexL[n] = lib + n;
        convert(indexL[n], tmpS);
        ++n;
    }
    nLib = n;
    qsort(indexL, n, sizeof(book *), cmp);
    int op, x;
    book tmp;
    while (~scanf("%d", &op) && op)
    {
        gets(tmpS);
        switch (op)
        {
        case 1:
            convert(&tmp, tmpS);
            lib[nLib++] = tmp;
            insert(lower_bound(&tmp, 0, n - 1) - 1, &lib[nLib - 1]);
            break;
        case 2:
            x = 0;
            while (~x)
            {
                x = find(x, tmpS);
                if (~x)
                    print(indexL[x]);
            }
            break;
        case 3:
            x = 0;
            while (~x)
            {
                x = find(x, tmpS);
                if (~x)
                    del(x);
            }
            break;
        }
    }
    for (int i = 0; i < n; ++i)
        fprint(fw, indexL[i]);
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

void fprint(FILE *fp, const book *b)
{
    fprintf(fp, "%-50s ", b->name);
    fprintf(fp, "%-20s ", b->author);
    fprintf(fp, "%-30s ", b->press);
    fprintf(fp, "%-10s\n", b->date);
}

//可能找不到，得改
int lower_bound(book *b, int l, int r)
{
    int mid;
    while (l < r)
    {
        mid = (l + r) / 2;
        if (strcmp(indexL[mid]->name, b->name) < 0)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}

void insert(int pre, book *b)
{
    for (int i = n - 1; i > pre; --i)
        indexL[i + 1] = indexL[i];
    indexL[pre + 1] = b;
    ++n;
}

int find(int i, char *s)
{
    for (; i < n; ++i)
        if (strstr(indexL[i]->name, s) != NULL)
            return i;
    return -1;
}

void del(int x)
{
    for (int i = x + 1; i < n; ++i)
        indexL[i - 1] = indexL[i];
    --n;
}
