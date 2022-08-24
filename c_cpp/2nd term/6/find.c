#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define NHASH 3001
#define MUTL 37
typedef long long LL;

struct
{
    int st, num;
} my_index[26];

struct data
{
    char *str;
    struct data *next;
} *HASH[NHASH];

int dictN, way, times;
char dict[3505][25], word[25];

unsigned int hash(char *str)
{
    unsigned int h = 0;
    char *p;
    for (p = str; *p != '\0'; p++)
        h = MUTL * h + *p;
    h = h % NHASH;
    return h;
}

int find();
int seq_search();
int bin_search(int, int);
int hash_search();
void insert_hash(struct data *, char *);

int main()
{
    FILE *fp = fopen("dictionary3000.txt", "r");
    for (int i = 0; i < NHASH; ++i)
    {
        HASH[i] = malloc(sizeof(struct data));
        HASH[i]->next = NULL, HASH[i]->str = NULL;
    }
    while (~fscanf(fp, "%s ", dict[dictN]))
    {
        if (!my_index[dict[dictN][0] - 'a'].st) my_index[dict[dictN][0] - 'a'].st = dictN;
        my_index[dict[dictN][0] - 'a'].num++;
        insert_hash(HASH[hash(dict[dictN])], dict[dictN]);
        ++dictN;
    }
    // printf("%d\n", dictN);
    my_index[0].st = 0;
    int ans;
    while (~scanf(" %s %d", word, &way))
    {
        // printf("%s %d\n", word, way);
        ans = find();
        printf("%d %d\n", ans, times);
    }
    return 0;
}

void insert_hash(struct data *H, char  *str)
{
    if (H->str == NULL)
    {
        H->str = str;
        return ;
    }
    if (H->next == NULL)
    {
        H->next = malloc(sizeof(struct data));
        H->next->str = NULL, H->next->next = NULL;
    }
    insert_hash(H->next, str);
}

int find()
{
    times = 0;
    switch (way)
    {
        case 1:
            return seq_search();
        case 2:
            return bin_search(0, dictN - 1);
        case 3:
            return bin_search(my_index[word[0] - 'a'].st, my_index[word[0] - 'a'].st + my_index[word[0] - 'a'].num - 1);
        case 4:
            return hash_search();
        default:
            return 0;
    }
}

int seq_search()
{
    int cmp;
    for (int i = 0; i < dictN; ++i)
    {
        cmp = strcmp(word, dict[i]);
        ++times;
        if (cmp < 0) return 0;
        if (cmp == 0) return 1;
    }
    return 0;
}

int bin_search(int l, int r)
{
    int mid, cmp;
    while (l <= r)
    {
        mid = (l + r) / 2;
        cmp = strcmp(word, dict[mid]);
        ++times;
        if (cmp == 0) return 1;
        if (cmp < 0) r = mid - 1;
        else l = mid + 1;
    }
    return 0;
}

int hash_search()
{
    int cmp, h = hash(word);
    struct data *p = HASH[h];
    while (p != NULL)
    {
        cmp = strcmp(word, p->str);
        ++times;
        if (cmp == 0) return 1;
        if (cmp < 0) return 0;
        p = p->next;
    }
    return 0;
}