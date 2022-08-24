//�ļ�ѹ��-Huffmanʵ��
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSIZE 32

struct tnode {					//Huffman���ṹ
	char c;		
	int weight;					//���ڵ�Ȩ�أ�Ҷ�ڵ�Ϊ�ַ������ĳ��ִ���
	struct tnode *left,*right;
} ; 
int Ccount[128]={0};			//���ÿ���ַ��ĳ��ִ�������Ccount[i]��ʾASCIIֵΪi���ַ����ִ��� 
struct tnode *Root=NULL; 		//Huffman���ĸ��ڵ�
char HCode[128][MAXSIZE]={{0}}; //�ַ���Huffman���룬��HCode['a']Ϊ�ַ�a��Huffman���루�ַ�����ʽ�� 
int Step=0;						//ʵ�鲽�� 
FILE *Src, *Obj;
	
void statCount();				//����1��ͳ���ļ����ַ�Ƶ��
void createHTree();				//����2������һ��Huffman�������ڵ�ΪRoot 
void makeHCode();				//����3������Huffman������Huffman����
void atoHZIP(); 				//����4������Huffman���뽫ָ��ASCII���ı��ļ�ת����Huffman���ļ�

void print1();					//�������1�Ľ��
void print2(struct tnode *p);	//�������2�Ľ�� 
void print3();					//�������3�Ľ��
void print4();					//�������4�Ľ��

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
	scanf("%d",&Step);					//���뵱ǰʵ�鲽�� 
	
	statCount();						//ʵ�鲽��1��ͳ���ļ����ַ����ִ�����Ƶ�ʣ�
	(Step==1) ? print1(): 1; 			//���ʵ�鲽��1���	
	createHTree();						//ʵ�鲽��2�������ַ�Ƶ��������Ӧ��Huffman��
	(Step==2) ? print2(Root): 2; 		//���ʵ�鲽��2���	
	makeHCode();				   		//ʵ�鲽��3������RootΪ���ĸ���Huffman��������ӦHuffman����
	(Step==3) ? print3(): 3; 			//���ʵ�鲽��3���
	(Step>=4) ? atoHZIP(),print4(): 4; 	//ʵ�鲽��4����Huffman��������ѹ���ļ��������ʵ�鲽��4���	

	fclose(Src);
	fclose(Obj);

    return 0;
} 

//��ʵ�鲽��1����ʼ 

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

//��ʵ�鲽��1������

//��ʵ�鲽��2����ʼ

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

//��ʵ�鲽��2������

//��ʵ�鲽��3����ʼ
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

//��ʵ�鲽��3������

//��ʵ�鲽��4����ʼ

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

//��ʵ�鲽��4������

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
	
	printf("\nԭ�ļ���С��%ldB\n",in_size);
	printf("ѹ�����ļ���С��%ldB\n",out_size);
	printf("ѹ���ʣ�%.2f%%\n",(float)(in_size-out_size)*100/in_size);
}
