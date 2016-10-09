#include<stdio.h>
typedef struct{
	unsigned int weight;
	unsigned int parent,lchild,child;
}HTNode,*Huffmantree;  
typedef char **HuffmanCode;   //动态分配数组存储赫夫曼编码表

void HuffmanCoding(Huffmantree &HT,HuffmanCode &HC,int *w,int n)
{   //w存放n个字符的权值，构造赫夫曼树HT，并求出赫夫曼编码HC
   if(n<=1)  return;
   int  m=2*n-1;
   HT=(Huffmantree)malloc((m+1)*sizeof(HTnode));//0号单元未用 
    for(Huffmantree p=HT+1,int i=1;i<=n;i++,w++)  *p={*w,0,0,0};
	for(i=n+1;i<=m;i++)    *p={0,0,0,0};
	// 
	Select(HT,i-1,s1,s2);  //在HT[1..i-1]选择parent为0且权值最小的两个结点 
} 

 

