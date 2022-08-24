#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define abs(a) (a > 0 ? a : -(a))
#define alpha(a) (a - 'a')
#define lower(a) ('A' <= a && a <= 'Z' ? a - 'A' + 'a' : a)
#define N 20005
#define dps 1e-9
typedef long long LL;

struct TRIE
{
    int cnt;
    struct TRIE * next[26];
} *dict, *stop;
struct PAGE
{
    int num, tot_words;
    char * id;
    struct PAGE * next;
    struct TRIE * text;
} *head;
struct DATA
{
    double sim;
    struct PAGE * p;
} ans[N];
int pageN = 0, ansN, TN[N];

int cmp(const void *, const void *);
int ffread_srt(FILE *, char *);
int search_trie(struct TRIE *, char *);
void insert_trie(struct TRIE *, char *);
void prework();

int main(int argc, char * argv[])
{
    prework();
    for (int i = 2; i < argc; ++i)
        for (char * p = argv[i]; *p != '\0'; ++p) *p = lower(*p);
    for (char * p = argv[1]; *p != '\0'; ++p)
        ansN = ansN * 10 + *p - '0';
    for (struct PAGE * p = head; p != NULL; p = p->next)
        ans[p->num].sim = 0, ans[p->num].p = p;
    double TF, IDF;
    int DN;
    for (int i = 2; i < argc; ++i)
    {
        DN = 0, IDF = 0;
        for (struct PAGE * p = head; p != NULL; p = p->next)
        {
            TN[p->num] = search_trie(p->text, argv[i]);
            if (TN[p->num]) DN++;
        }
        for (struct PAGE * p = head; p != NULL; p = p->next)
        {
            if (DN && TN[p->num])
            {
                TF = (double)TN[p->num] / (double)(p->tot_words) * 100.0;
                IDF = log10((double)pageN / (double)DN);
                ans[p->num].sim += TF * IDF;
            }
        }
    }
    qsort(ans + 1, pageN, sizeof(struct DATA), cmp);
    while (abs(ans[pageN].sim) < dps && pageN > 0) --pageN;
    for (int i = 1; i <= 5 && i <= pageN; ++i)
        fprintf(stdout, "%.6lf %d %s\n", ans[i].sim, ans[i].p->num, ans[i].p->id);
    FILE *fp = fopen("results.txt", "w");
    for (int i = 1; i <= ansN && i <= pageN; ++i)
        fprintf(fp, "%.6lf %d %s\n", ans[i].sim, ans[i].p->num, ans[i].p->id);
    fclose(fp);
    return 0;
}

void prework()
{
    dict = malloc(sizeof(struct TRIE)), memset(dict, 0, sizeof(struct TRIE));
    stop = malloc(sizeof(struct TRIE)), memset(stop, 0, sizeof(struct TRIE));
    head = malloc(sizeof(struct PAGE)), memset(head, 0, sizeof(struct PAGE));
    FILE * fp;
    char str[200];
    fp = fopen("stopwords.txt", "r");
    while (~fscanf(fp, "%s", str))
        insert_trie(stop, str);
    fclose(fp);
    fp = fopen("dictionary.txt", "r");
    while (~fscanf(fp, "%s", str))
        if (!search_trie(stop, str))
            insert_trie(dict, str);
    fclose(fp);
    fp = fopen("article.txt", "r");
    struct PAGE * p = head;
    int end = 0;
    while (~fscanf(fp, "%s", str))
    {
        // printf("%s\n", str);
        p->num = ++pageN;
        p->id = malloc(sizeof(char) * (strlen(str) + 5));
        strcpy(p->id, str);
        p->text = malloc(sizeof(struct TRIE)), memset(p->text, 0, sizeof(struct TRIE));
        while (1)
        {
            end = ffread_srt(fp, str);
            if (str[0] != '\0' && search_trie(dict, str))
            {
                insert_trie(p->text, str);
                p->tot_words++;
            }
            if (end == 1 || end == -1) break;
        }
        if (end == 1)
        {
            p->next = malloc(sizeof(struct PAGE)), memset(p->next, 0, sizeof(struct PAGE));
            p = p->next;
        }
        else break;
    }
    fclose(fp);
}

void insert_trie(struct TRIE * p, char * s)
{
    if (*s == '\0')
    {
        p->cnt++;
        return ;
    }
    if (p->next[alpha(*s)] == NULL)
    {
        p->next[alpha(*s)] = malloc(sizeof(struct TRIE));
        memset(p->next[alpha(*s)], 0, sizeof(struct TRIE));
    }
    insert_trie(p->next[alpha(*s)], s + 1);
}

int search_trie(struct TRIE * p, char * s)
{
    if (*s == '\0')
        return p->cnt;
    if (*s < 'a' || *s > 'z' || p->next[alpha(*s)] == NULL)
        return 0;
    return search_trie(p->next[alpha(*s)], s + 1);
}

int cmp(const void *p1, const void *p2)
{
    double tmp = ((const struct DATA *)p1)->sim - ((const struct DATA *)p2)->sim;
    if (abs(tmp) < dps)
        return ((const struct DATA *)p1)->p->num - ((const struct DATA *)p2)->p->num;
    if (tmp < -dps) return 1;
    else return -1;
}

int ffread_srt(FILE * fp, char * str)
{
    *str = '\0';
    int ch = fgetc(fp);
    while (!isalpha(ch))
    {
        if (ch == EOF) return -1;
        if (ch == '\f') return 1;
        ch = fgetc(fp);
    }
    while (isalpha(ch))
    {
        *str = lower(ch);
        ++str, ch = fgetc(fp);
    }
    *str = '\0';
    if (ch == EOF) return -1;
    if (ch == '\f') return 1;
    return 0;
}
