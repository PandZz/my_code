#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define F(i, l, r) for (int i = l; i <= r; ++i)
typedef long long LL;
#define N 100000

int n;
char a[N][1005];
int ptr[N], sizeA[N];

int cmp(const void *p1, const void *p2)
{
    return (sizeA[*(int *)p2] - sizeA[*(int *)p1]);
}

int cmp2(const void *p1, const void *p2)
{
    return (*(int *)p1 - *(int *)p2);
}

int main()
{
    int i = 0;
    while (gets(a[i++]) != NULL);
    n = i - 1;
    F(i, 0, n - 1) ptr[i] = i, sizeA[i] = strlen(a[i]);
    qsort(ptr, n, sizeof(int), cmp);
    qsort(ptr, 20, sizeof(int), cmp2);
    F(i, 0, 19) puts(a[ptr[i]]);
    /* printf("\nn = %d\n", n);
    F(i, 0, n - 1) printf("sizeA[%d]=%d\n", i, sizeA[i]);
    F(i, 0, n - 1) printf("%d\n", sizeA[ptr[i]]); */
    return 0;
}