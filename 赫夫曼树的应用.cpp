#include<stdio.h>
typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,child;
}HTNode,*Huffmantree;  
typedef char **HuffmanCode;   //��̬��������洢�շ��������

void HuffmanCoding(Huffmantree &HT,HuffmanCode &HC,int *w,int n)
{   //w���n���ַ���Ȩֵ������շ�����HT��������շ�������HC
   if(n<=1)  return;
   int  m=2*n-1;
   HT=(Huffmantree)malloc((m+1)*sizeof(HTnode));//0�ŵ�Ԫδ�� 
    for(Huffmantree p=HT+1,int i=1;i<=n;i++,w++)  *p={*w,0,0,0};
	for(i=n+1;i<=m;i++)    *p={0,0,0,0};
	// 
	Select(HT,i-1,s1,s2);  //��HT[1..i-1]ѡ��parentΪ0��Ȩֵ��С��������� 
} 

 

