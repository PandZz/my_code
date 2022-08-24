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
#define N 16005
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
    double sim;
    struct TRIE * text;
} page[N];
struct DATA
{
    int num;
    char * id;
    double sim;
} ans[N];
int pageN = 1, ansN, TN[N], n;

int cmp(const void *, const void *);
int ffread_srt(FILE *, char *);
int ffread_id(FILE *, char *);
int search_trie(struct TRIE *, char *);
void insert_trie(struct TRIE *, char *);
void prework();

int main(int argc, char * argv[])
{
    prework();
    for (char * p = argv[1]; *p != '\0'; ++p)
        n = n * 10 + *p - '0';
    fp = fopen("article.txt", "r");
    int end = 0;
    while (~fscanf(fp, "%s", str))
    {
        // printf("%s\n", str);
        page[pageN].num = pageN;
        page[pageN].id = malloc(sizeof(char) * (strlen(str) + 5));
        strcpy(page[pageN].id, str);
        page[pageN].text = malloc(sizeof(struct TRIE)), memset(page[pageN].text, 0, sizeof(struct TRIE));
        while (1)
        {
            end = ffread_srt(fp, str);
            if (str[0] != '\0' && search_trie(dict, str))
            {
                insert_trie(page[pageN].text, str);
                page[pageN].tot_words++;
            }
            if (end == 1 || end == -1) break;
        }
        if (end == 1)
            ++pageN;
        else
            break;
    }
    fclose(fp);
    /*double TF, IDF;
    int DN;
    for (int i = 2; i < argc; ++i)
    {
        DN = 0, IDF = 0;
        for (int j = 1; j <= pageN; ++j)
        {
            TN[j] = search_trie(page[j].text, argv[i]);
            if (TN[j]) ++DN;
        }
        if (!DN) continue;
        for (int j = 1; j <= pageN; ++j)
        {
            if (TN[j])
            {
                TF = (double)TN[j] / (double)(page[j].tot_words) * 100.0;
                IDF = log10((double)pageN / (double)DN);
                page[j].sim += TF * IDF;
            }
        }
    }
    for (int i = 1; i <= pageN; ++i)
        if (abs(page[i].sim) > dps)
        {
            ++ansN;
            ans[ansN].id = page[i].id;
            ans[ansN].num = page[i].num;
            ans[ansN].sim = page[i].sim;
        }
    n = min(n, ansN);
    qsort(ans + 1, ansN, sizeof(struct DATA), cmp);
    for (int i = 1; i <= 5 && i <= ansN; ++i)
        fprintf(stdout, "%.6lf %d %s\n", ans[i].sim, ans[i].num, ans[i].id);
    FILE *fp = fopen("results.txt", "w");
    for (int i = 1; i <= n; ++i)
        fprintf(fp, "%.6lf %d %s\n", ans[i].sim, ans[i].num, ans[i].id);
    fclose(fp);
    return 0;*/
}

void prework()
{
    dict = malloc(sizeof(struct TRIE)), memset(dict, 0, sizeof(struct TRIE));
    stop = malloc(sizeof(struct TRIE)), memset(stop, 0, sizeof(struct TRIE));
    FILE * fp;
    char str[200];
    fp = fopen("stopwords.txt", "r");
    while (~ffread_srt(fp, str))
        insert_trie(stop, str);
    fclose(fp);
    fp = fopen("dictionary.txt", "r");
    while (~ffread_srt(fp, str))
        if (!search_trie(stop, str))
            insert_trie(dict, str);
    fclose(fp);
    /*fp = fopen("article.txt", "r");
    int end = 0;
    while (~fscanf(fp, "%s", str))
    {
        // printf("%s\n", str);
        page[pageN].num = pageN;
        page[pageN].id = malloc(sizeof(char) * (strlen(str) + 5));
        strcpy(page[pageN].id, str);
        page[pageN].text = malloc(sizeof(struct TRIE)), memset(page[pageN].text, 0, sizeof(struct TRIE));
        while (1)
        {
            end = ffread_srt(fp, str);
            if (str[0] != '\0' && search_trie(dict, str))
            {
                insert_trie(page[pageN].text, str);
                page[pageN].tot_words++;
            }
            if (end == 1 || end == -1) break;
        }
        if (end == 1)
            ++pageN;
        else
            break;
    }
    fclose(fp);*/
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
        return ((const struct DATA *)p1)->num - ((const struct DATA *)p2)->num;
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

int ffread_id(FILE * fp, char * str)
{
    int ch = fgetc(fp);
    while (!isgraph(ch))
    {
        if (ch == EOF) return -1;
        ch = fgetc(fp);
    }
    while (isgraph(ch))
    {
        *(str++) = ch;
        ch = fgetc(fp);
    }
    *str = '\0';
    if (ch == EOF) return -1;
    return 0;
}