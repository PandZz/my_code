// pro1:Trie树确定索引位置； 用stopWord除去不该计算的词
// pro2:以文档为单位(N)记录每个单词的频次;
//##data:以结构体{TNkd,DNk,TFkd[pages],IDFk}来记录##每个单词TNkd++,DNk++
// pro3:一篇文档结束后，计算TFkd,TNkd清0,读入文档时记录对应的文档数以及其网页序号;
// pro4:读完所有文档,
// pro5:计算IDFk,计算完计算Sim

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define PageSize 1000
#define WordSize 15000
struct node {
	int TNkd, DNk;
	double TFkd[PageSize];
	double IDFk;
} Words[WordSize];
struct ednode {
	char eno[10];
	double sim;
	int id;
} Pages[PageSize];
struct finode {
	int flag, pos, actual;		//flag标志是否为非stop的word;pos是Words中的位置;flag==1->yes flag==0->no
	struct finode *next[26];
} Trie[42000][26];
int Ks[1005],num_k = 0;
int num_word = 0, pos, num_page = 0;
int TNd[PageSize],NUM;
char arr[1024], s[42000 * 80];
int search(char word[]) {
	int p = 0;
	for (int i = 0; word[i]; i++) {
		int ch = word[i] - 'a';
		if (!Trie[p][ch].pos) {
			return 0;
		}
		p = Trie[p][ch].pos;
	}
	return p;
}
int cmp(const void *a, const void* b)
{
	struct ednode *tmpa = (struct ednode*)a,*tmpb = (struct ednode*)b;
	if(tmpa->sim < tmpb->sim) return 1;
	else if(tmpa->sim > tmpb->sim) return -1;
	else 
	{
		return tmpa->id -tmpb->id; 
	}
}
int main() {
	FILE *dictionary = fopen("dictionary.txt", "r");
	while (fscanf(dictionary, "%s", arr) != EOF) {
		int p = 0, i;
		for (i = 0; arr[i] != '\0'; i++) {
			int ch = arr[i] - 'a';
			if (!Trie[p][ch].pos) {
				Trie[p][ch].pos = ++pos;
			}
			p = Trie[p][ch].pos;
		}
		printf("%d\n", pos);
		Trie[p][0].flag = 1;
	}
	fclose(dictionary);
	printf("%d\n", pos);
	return 0;
	
	
	FILE *stopwords = fopen("stopwords.txt", "r");
	while (fscanf(stopwords, "%s", arr) != EOF) {
		int index = search(arr);
		if (Trie[index][0].flag)
			Trie[index][0].flag = 0;
	}
	fclose(stopwords);

	
	scanf("%d",&NUM);
	char K[80];
	do{
		int laji;
		memset(K,'\0',sizeof(K));
		laji = scanf("%s",K);
		if(laji == EOF) break;
		int index = search(K);
		if(Trie[index][0].flag == 1)
		{
			Ks[num_k++] = Trie[index][0].actual;
		}
	}while(1);
	
	
	FILE *article = fopen("article.txt", "r");
	fread(s, sizeof(char), 420000 * 80, article);
	fclose(article);
	
	
	char word[80];
	for (int i = 0; s[i] != '\0'; i++) {
		if (i == 0) {
			int j;
			for (j = i; s[j] != '\n'; j++) {
				Pages[num_page].eno[j-i] = s[j];
			}
			Pages[num_page].id = num_page+1;
		} else if (isalpha(s[i])) {
			int j;
			for (j = i; isalpha(s[j]); j++) {
				word[j - i] = tolower(s[j]);
			}
			i = j - 1;
			int index = search(word);
			if (Trie[index][0].flag == 1) {
				Trie[index][0].flag = 2;
				Trie[index][0].actual = num_word++;
				Words[Trie[index][0].actual].TNkd++;
				Words[Trie[index][0].actual].DNk++;
				TNd[num_page]++;
			} else if (Trie[index][0].flag == 2) {
				Words[Trie[index][0].actual].TNkd++;
				Words[Trie[index][0].actual].DNk++;
				TNd[num_page]++;
			}
			memset(word, '\0', sizeof(word));
		} else if (s[i] == '\f') {
			for(int j = 0; j < num_word;j++)
			{
				Words[j].TFkd[num_page] = 100.0*Words[j].TNkd/TNd[num_page];
				Words[j].TNkd = 0;
			}
			num_page++;
			for(int j = i+1; s[j] != '\n';j++)
			{
				Pages[num_page].eno[j-i-1] = s[j];
			}
			Pages[num_page].id = num_page+1;
		}
	}
	num_page++;
	
	
	for(int i = 0; i < num_word;i++)
	{
		Words[i].IDFk = log10(1.0*num_page/Words[i].DNk);
	}
	for(int i=0;i< num_page;i++){
		for(int j = 0; j< num_k;j++)
		{
			Pages[i].sim += 1.0*Words[Ks[j]].TFkd[i]*Words[Ks[j]].IDFk;
		}
	}
	
	
	FILE *results = fopen("results.txt","w");
	qsort(Pages,num_page,sizeof(Pages[0]),cmp);
	for(int i = 0 ; i <NUM && i < num_page;i++)
	{
		fprintf(results,"%.6lf %s %d\n",Pages[i].sim,Pages[i].eno,Pages[i].id);
	}
	for(int i = 0; i < 5;i++)
	{
		printf("%.6lf %s %d\n",Pages[i].sim,Pages[i].eno,Pages[i].id);
	}
	return 0;
}
