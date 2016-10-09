#include<stdio.h>

#define  MAX_VERTEX_NUM  20   //最大顶点个数 
typedef  int  vextype;
typedef vextype Mgraph[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
Mgraph G1;
int n,e;
extern void creat_mygrap(Mgraph G);
extern  void out_mygraph(Mgraph G);
int main()
{
	creat_mygrap(G1);
    out_mygraph(G1);
    return 0;
}
