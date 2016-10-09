/***********************************邻接矩阵的无向图，有向图，有向网，无向网函数实现***************/ 
#include"structnode.h"
void creat_mygraph1(Mgraph *g)      //无向图邻接矩阵 
{
	int i,j,k;
	char v1,v2;
	printf("请输入无向图的顶点数和弧的数:\n");
	scanf("%d %d",&g->vexnum,&g->arcnum);
	getchar();
	for(i=0;i<g->vexnum;i++)
	{
		printf("请向无向图的顶点输入字符：\n");
		scanf("%c",&g->vexs[i]);
		getchar();
		
	}
	for(j=0;j<g->vexnum;j++)
		for(j=0;j<g->vexnum;j++)
			g->arcs[i][j]=0;
	for(k=0;k<g->arcnum;k++)
	{
		printf("请输入已存在的两个顶点字符：\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		i=locatevex(g,v1);
		j=locatevex(g,v2);
		g->arcs[i][j]=g->arcs[j][i]=1;
		 
		 
		}
			
		for(i=0;i<g->vexnum;i++)
		 {
			for(j=0;j<g->vexnum;j++)
		    printf("%d\t",g->arcs[i][j]);
		    printf("\n");
		}
}

void creat_hway_graph(Mgraph *g)    //有向图邻接矩阵 
{
	
	
	int i,j,k;
	char v1,v2;
	printf("请输入有向图的顶点数和弧的数:\n");
	scanf("%d %d",&g->vexnum,&g->arcnum);
	getchar();
	for(i=0;i<g->vexnum;i++)
	{
		printf("请向有向图的顶点输入字符：\n");
		scanf("%c",&g->vexs[i]);
		getchar();
		
	}
	for(j=0;j<g->vexnum;j++)
		for(j=0;j<g->vexnum;j++)
			g->arcs[i][j]=0;
	for(k=0;k<g->arcnum;k++)
	{
		printf("请输入已存在的两个顶点字符：\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		i=locatevex(g,v1);
		j=locatevex(g,v2);
		g->arcs[i][j]=1;
		 
		 
		}
		
		for(i=0;i<g->vexnum;i++)
		 {
			for(j=0;j<g->vexnum;j++)
		    printf("%d\t",g->arcs[i][j]);
		    printf("\n");
		}
	
	
	}
void creat_nonet(Mgraph *g)        //无向网的邻接矩阵 
{
		int i,j,k;
	char v1,v2;
	printf("请输入无向网的顶点数和弧的数:\n");
	scanf("%d %d",&g->vexnum,&g->arcnum);
	getchar();
	for(i=0;i<g->vexnum;i++)
	{
		printf("请向无向网的顶点输入字符：\n");
		scanf("%c",&g->vexs[i]);
		getchar();
		
	}
	for(i=0;i<g->vexnum;i++)
		for(j=0;j<g->vexnum;j++)
			g->arcs[i][j]=0;            //初始化矩阵的值为0 
	for(k=0;k<g->arcnum;k++)
	{   
		printf("请输入已存在的两个顶点字符：\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		i=locatevex(g,v1);
		j=locatevex(g,v2);
		printf("请给无向网输入对应的权值：\n");
		scanf("%d",&g->arcs[i][j]);
		getchar();
		g->arcs[j][i]=g->arcs[i][j];
			
	}
    	
		for(i=0;i<g->vexnum;i++)
		 {
			for(j=0;j<g->vexnum;j++)
		    printf("%d\t",g->arcs[i][j]);
		    printf("\n");
		} 
} 


void have_w_net(Mgraph *g)     //有向网的邻接矩阵 
{
	int i,j,k;
	char v1,v2;
	printf("请输入有向网的顶点数和弧的数:\n");
	scanf("%d %d",&g->vexnum,&g->arcnum);
	getchar();
	for(i=0;i<g->vexnum;i++)
	{
		printf("请向有向网的顶点输入字符：\n");
		scanf("%c",&g->vexs[i]);
		getchar();
		
	}
	for(j=0;j<g->vexnum;j++)
		for(j=0;j<g->vexnum;j++)
			g->arcs[i][j]=0;
	for(k=0;k<g->arcnum;k++)
	{
		printf("请输入已存在的两个顶点字符：\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		i=locatevex(g,v1);
		j=locatevex(g,v2);
		printf("请给这两个相连的字符标上权值：\n");
		scanf("%d",&g->arcs[i][j]);
		getchar();
		 
		 
	}
			
		for(i=0;i<g->vexnum;i++)
		 {
			for(j=0;j<g->vexnum;j++)
		    printf("%d\t",g->arcs[i][j]);
		    printf("\n");
		}
	
}



/*****************************************/
