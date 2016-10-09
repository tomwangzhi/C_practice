#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
#include<iostream>
using namespace std;

typedef char** HaffmanCode;

typedef struct
{
        unsigned int weight;
        unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;

void Select(HuffmanTree &HT,int i,int &s1,int &s2)
{
     int n,m=0;
     for(n=1,m=0;n<=i&&m!=2;n++)
     {
          if(HT[n].parent==0)
          {
              if(m==0)
              {
                      s1=n;
                      m=1;
                      continue;
              }
              if(m==1)
              {
                      s2=n;
                      m=2;
                      break;       
              }
          }
          
     }
     n++;
     for(;n<=i;n++)
     {
          if(HT[n].parent==0)
          {
              if(HT[n].weight<HT[s1].weight)
              {
                  if(HT[s1].weight<HT[s2].weight)
                  s2=s1;
                  s1=n;
                  continue;
              }
              if(HT[n].weight<HT[s2].weight)
              {
                  if(HT[s2].weight<HT[s1].weight)
                  s1=s2;
                  s2=n;
              }
          }
     }
     printf("%d   %d\n",s1,s2);
}

void HuffmanCoding(HuffmanTree &HT,HaffmanCode &HC,int *w,int n)
{
     int m,i,s1,s2,start,c,f;
     
     char *cd;
     if(n<=1)return ;
     m=2*n-1;
     
     HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
     
     for(i=1;i<=n;++i)
     {
          HT[i].weight=w[i-1];
          HT[i].parent=0;
          HT[i].lchild=0;
          HT[i].rchild=0;
     }
     for(;i<=m;++i)
     {
          HT[i].weight=0;
          HT[i].parent=0;
          HT[i].lchild=0;
          HT[i].rchild=0;
     }
     for(i=n;i<m;i++)
     {
          Select(HT,i,s1,s2);
          HT[s1].parent=i+1;
          HT[s2].parent=i+1;
          HT[i+1].lchild=s1;
          HT[i+1].rchild=s2;
          HT[i+1].weight=HT[s1].weight+HT[s2].weight;
     }
     /*********************************************/
     HC = (HaffmanCode)malloc((n+1)*sizeof(char*));
     cd = (char *)malloc(n*sizeof(char));
     cd[n-1] = '\0';
     for(i=1;i<=n;++i)
     {
          start = n-1;
          for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
          if(HT[f].lchild==c)cd[--start]='0';
          else cd[--start]='1';
          HC[i] = (char*)malloc((n-start)*sizeof(char));
          strcpy(HC[i],&cd[start]);
          //printf("%s\n",HC[i]);
     }
     free(cd);
}

int main()
{
    HuffmanTree HT;
    HaffmanCode HC;
    int n,i,j;
    int *w;
    printf("请输入赫夫曼数的个数：\n");
    scanf("%d",&n);
    w=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    { 
         printf("请输入第%d个数：",i+1); 
         scanf("%d",&w[i]);  
    } 
    HuffmanCoding(HT,HC,w,n);
    printf("赫夫曼编码为：\n");
    for(i=1;i<=n;i++)
    {
         printf("%s\n",HC[i]);
    }
    system("pause");
    return 0;
}
