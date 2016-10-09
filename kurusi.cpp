#include <stdio.h>  
#include <malloc.h>  
#include "graph.h"  
#define MaxSize 100  
typedef struct  
{  
    int u;     //�ߵ���ʼ����  
    int v;     //�ߵ���ֹ����  
    int w;     //�ߵ�Ȩֵ  
} Edge;  
  
void InsertSort(Edge E[],int n) //��E[0..n-1]�������������ֱ�Ӳ�������  
{  
    int i,j;  
    Edge temp;  
    for (i=1; i<n; i++)  
    {  
        temp=E[i];  
        j=i-1;              //����������������E[0..i-1]����E[i]�Ĳ���λ��  
        while (j>=0 && temp.w<E[j].w)  
        {  
            E[j+1]=E[j];    //���ؼ��ִ���E[i].w�ļ�¼����  
            j--;  
        }  
        E[j+1]=temp;        //��j+1������E[i]  
    }  
}  
  
void Kruskal(MGraph g)  
{  
    int i,j,u1,v1,sn1,sn2,k;  
    int vset[MAXV];  
    Edge E[MaxSize];    //������б�  
    k=0;                //E������±��0��ʼ��  
    for (i=0; i<g.n; i++)   //��g�����ı߼�E  
        for (j=0; j<g.n; j++)  
            if (g.edges[i][j]!=0 && g.edges[i][j]!=INF)  
            {  
                E[k].u=i;  
                E[k].v=j;  
                E[k].w=g.edges[i][j];  
                k++;  
            }  
    InsertSort(E,g.e);      //����ֱ�Ӳ��������E���鰴Ȩֵ��������  
    for (i=0; i<g.n; i++)   //��ʼ����������  
        vset[i]=i;  
    k=1;    //k��ʾ��ǰ�����������ĵڼ�����,��ֵΪ1  
    j=0;    //E�бߵ��±�,��ֵΪ0  
    while (k<g.n)       //���ɵı���С��nʱѭ��  
    {  
        u1=E[j].u;  
        v1=E[j].v;      //ȡһ���ߵ�ͷβ����  
        sn1=vset[u1];  
        sn2=vset[v1];   //�ֱ�õ��������������ļ��ϱ��  
        if (sn1!=sn2)   //���������ڲ�ͬ�ļ���  
        {  
            printf("  (%d,%d):%d\n",u1,v1,E[j].w);  
            k++;                     //���ɱ�����1  
            for (i=0; i<g.n; i++)   //��������ͳһ���  
                if (vset[i]==sn2)   //���ϱ��Ϊsn2�ĸ�Ϊsn1  
                    vset[i]=sn1;  
        }  
        j++;               //ɨ����һ����  
    }  
}  
  
int main()  
{  
    MGraph g;  
    int A[6][6]=  
    {  
        {0,6,1,5,INF,INF},  
        {6,0,5,INF,3,INF},  
        {1,5,0,5,6,4},  
        {5,INF,5,0,INF,2},  
        {INF,3,6,INF,0,6},  
        {INF,INF,4,2,6,0}  
    };  
    ArrayToMat(A[0], 6, g);  
    printf("��С����������:\n");  
    Kruskal(g);  
    return 0;  
}  
void ArrayToMat(int *Arr, int n, MGraph &g)
{
    int i,j,count=0;  //count����ͳ�Ʊ������������з�0Ԫ�ظ���
    g.n=n;
    for (i=0; i<g.n; i++)
        for (j=0; j<g.n; j++)
        {
            g.edges[i][j]=Arr[i*n+j]; //��Arr����n��n�Ķ�ά���飬Arr[i*n+j]����Arr[i][j]������洢λ�õĹ����ڴ�Ӧ��
            if(g.edges[i][j]!=0 && g.edges[i][j]!=INF)
                count++;
        }
    g.e=count;
}

