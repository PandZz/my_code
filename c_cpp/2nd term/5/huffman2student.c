//文件压缩-Huffman实现
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {					//Huffman树结构
	char c;		
	int weight;					//树节点权重，叶节点为字符和它的出现次数
	struct tnode *left,*right;
} ; 
int Ccount[128]={0};			//存放每个字符的出现次数，如Ccount[i]表示ASCII值为i的字符出现次数 
struct tnode *Root=NULL; 		//Huffman树的根节点
char HCode[128][MAXSIZE]={{0}}; //字符的Huffman编码，如HCode['a']为字符a的Huffman编码（字符串形式） 
int Step=0;						//实验步骤 
FILE *Src, *Obj;
	
void statCount();				//步骤1：统计文件中字符频率
void createHTree();				//步骤2：创建一个Huffman树，根节点为Root 
void makeHCode();				//步骤3：根据Huffman树生成Huffman编码
void atoHZIP(); 				//步骤4：根据Huffman编码将指定ASCII码文本文件转换成Huffman码文件

void print1();					//输出步骤1的结果
void print2(struct tnode *p);	//输出步骤2的结果 
void print3();					//输出步骤3的结果
void print4();					//输出步骤4的结果

int main()
{
	if((Src=fopen("input.txt","r"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "input.txt");
		return 1;
	}
	if((Obj=fopen("output.txt","w"))==NULL) {
		fprintf(stderr, "%s open failed!\n", "output.txt");
		return 1;
	}
	scanf("%d",&Step);					//输入当前实验步骤 
	
	statCount();						//实验步骤1：统计文件中字符出现次数（频率）
	(Step==1) ? print1(): 1; 			//输出实验步骤1结果	
	createHTree();						//实验步骤2：依据字符频率生成相应的Huffman树
	(Step==2) ? print2(Root): 2; 		//输出实验步骤2结果	
	makeHCode();				   		//实验步骤3：依据Root为树的根的Huffman树生成相应Huffman编码
	(Step==3) ? print3(): 3; 			//输出实验步骤3结果
	(Step>=4) ? atoHZIP(),print4(): 4; 	//实验步骤4：据Huffman编码生成压缩文件，并输出实验步骤4结果	

	fclose(Src);
	fclose(Obj);

    return 0;
} 

//【实验步骤1】开始 

void statCount()
{
	int ch;
	while ((ch = fgetc(Src)) != EOF)
	{
		if (ch == '\n') continue;
		Ccount[ch]++;
	}
	Ccount[0] = 1;
}

//【实验步骤1】结束

//【实验步骤2】开始

void createHTree()
{
	struct tnode *f[128 * 128], *p, *q;
	int s = 0, t = -1;
	for (int i = 0; i < 128; ++i)
		if (Ccount[i])
		{
			p = malloc(sizeof(struct tnode));
			p->c = i, p->weight = Ccount[i], p->left = p->right = NULL;
			f[++t] = p;
		}
	for (int k = 1; k <= t; ++k)
		for (int i = 0; i <= t - k; ++i)
		{
			if (f[i]->weight > f[i + 1]->weight)
			{
				p = f[i];
				f[i] = f[i + 1];
				f[i + 1] = p;
			}
			else if (f[i]->weight == f[i + 1]->weight && f[i]->c > f[i + 1]->c)
			{
				p = f[i];
				f[i] = f[i + 1];
				f[i + 1] = p;
			}
		}
	while (s < t)
	{
		p = malloc(sizeof(struct tnode));
		p->left = f[s], p->right = f[s + 1], p->c = -1, p->weight = f[s]->weight + f[s + 1]->weight;
		s += 2;
		f[++t] = p;
		for (int i = t; i > s; --i)
		{
			if (f[i]->weight < f[i - 1]->weight)
			{
				p = f[i];
				f[i] = f[i - 1];
				f[i - 1] = p;
			}
			else break;
		}
	}
	Root = f[s];
}

//【实验步骤2】结束

//【实验步骤3】开始
char str[MAXSIZE];
void visitHtree(struct tnode *p, int step)
{
	if (p->left == NULL)
	{
		str[step] = '\0';
		strcpy(HCode[p->c], str);
		return;
	}
	str[step] = '0', visitHtree(p->left, step + 1);
	str[step] = '1', visitHtree(p->right, step + 1);
}

void makeHCode()
{
	visitHtree(Root, 0);
}

//【实验步骤3】结束

//【实验步骤4】开始

void atoHZIP()
{
	char str[8000], ch;
	int n, tmp;
	fseek(Src, 0, SEEK_SET);
	while ((ch = fgetc(Src)) != EOF)
		strcat(str, HCode[ch]);
	strcat(str, HCode[0]);
	n = strlen(str);
	if (n % 8)
	{
		tmp = 8 - n % 8;
		for (int i = 0; i < tmp; ++i) str[n + i] = '0';
		n += tmp, str[n] = '\0';
	}
	for (int i = 0; i < n; i += 8)
	{
		tmp = 0;
		for (int j = 0; j < 8; ++j)
			tmp = (tmp << 1) | (str[i + j] - '0');
		fputc(tmp, Obj);
		printf("%x", tmp);
	}
}

//【实验步骤4】结束

void print1()
{
	int i;
	printf("NUL:1\n");
	for(i=1; i<128; i++)
		if(Ccount[i] > 0)
			printf("%c:%d\n", i, Ccount[i]);
}

void print2(struct tnode *p)
{
	if(p != NULL){
		if((p->left==NULL)&&(p->right==NULL)) 
			switch(p->c){
				case 0: printf("NUL ");break;
				case ' ':  printf("SP ");break;
				case '\t': printf("TAB ");break;
				case '\n':  printf("CR ");break;
				default: printf("%c ",p->c); break;
			}
		print2(p->left);
		print2(p->right);
	}
}

void print3()
{
	int i;
	
	for(i=0; i<128; i++){
		if(HCode[i][0] != 0){
			switch(i){
				case 0: printf("NUL:");break;
				case ' ':  printf("SP:");break;
				case '\t': printf("TAB:");break;
				case '\n':  printf("CR:");break;
				default: printf("%c:",i); break;
			}
			printf("%s\n",HCode[i]);
		}
	}
} 

void print4()
{
	long int in_size, out_size;
	
	fseek(Src,0,SEEK_END);
	fseek(Obj,0,SEEK_END);
	in_size = ftell(Src);
	out_size = ftell(Obj);
	
	printf("\n原文件大小：%ldB\n",in_size);
	printf("压缩后文件大小：%ldB\n",out_size);
	printf("压缩率：%.2f%%\n",(float)(in_size-out_size)*100/in_size);
}
