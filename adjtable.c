/**********************************邻接表存储的无向图，有向图，无向网，有向网函数实现***************/ 
#include"structnode.h"
#include<malloc.h>
void adj_table_hway(LGraph *tg)    //有向图的邻接表 
{
		int i,j,k;
	char v1,v2;
	arcnode *p;
	printf("请输入邻接表存储有向图的顶点数和弧的数(注意vex<=20,arc<=40:\n");
	scanf("%d %d",&tg->vexnum,&tg->arcnum);
	getchar();
		for(i=0;i<tg->vexnum;i++)
	{
		printf("请向有向图的顶点输入字符：\n");
		scanf("%c",&tg->vertices[i].data);
		getchar();
		tg->vertices[i].firstarc=NULL;
	}
	for(k=0;k<tg->arcnum;k++)
	{
	
		
		printf("请输入有向图相连的两个顶点：\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		p=(arcnode*)malloc(sizeof(arcnode));
		if(!p) printf("分配失败！");
		i=locate_adj_vex(tg,v1);
		j=locate_adj_vex(tg,v2); 
		p->adjvex=j;
		p->arcnext=tg->vertices[j].firstarc;
		tg->vertices[j].firstarc=p;
	
		}

}
void adj_table_noway(LGraph *tg)       //无向图 的邻接表
{
	
	int i,j,k;
	char v1,v2;
	arcnode *p,*q;
	printf("请输入邻接表存储无向图的顶点数和弧的数(注意vex<=20,arc<=40:\n");
	scanf("%d %d",&tg->vexnum,&tg->arcnum);
	getchar();
		for(i=0;i<tg->vexnum;i++)   
	{
		printf("请向无向图的顶点输入字符：\n");
		scanf("%c",&tg->vertices[i].data);
		getchar();
		tg->vertices[i].firstarc=NULL;
	}
	for(k=0;k<tg->arcnum;k++)
	{
	
		if(!p) printf("分配失败！");
		printf("请输入无向图相连的两个顶点：\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		p=(arcnode*)malloc(sizeof(arcnode));
		if(!p) printf("分配失败！");
		i=locate_adj_vex(tg,v1);
		j=locate_adj_vex(tg,v2); 
		p->adjvex=i;
		p->arcnext=tg->vertices[j].firstarc;
		tg->vertices[j].firstarc=p;   //头插法插入边结点 
		q=(arcnode*)malloc(sizeof(arcnode));   //无向图所以需另加入一个边结点 
		if(!q) printf("分配失败！");
		q->adjvex=j;
		q->arcnext=tg->vertices[i].firstarc;
		tg->vertices[i].firstarc=q; 	
		}
	
	
}
void  adj_table_h_net(LGraph *tg)    //有向网 的邻接表
{
	int i,j,k;
	char v1,v2;
	arcnode *p,*q;
	printf("请输入邻接表存储有向网的顶点数和弧的数(注意vex<=20,arc<=40:\n");
	scanf("%d %d",&tg->vexnum,&tg->arcnum);
	getchar();
		for(i=0;i<tg->vexnum;i++)
	{
		printf("请向有向网的顶点输入字符：\n");
		scanf("%c",&tg->vertices[i].data);
		getchar();
		tg->vertices[i].firstarc=NULL;
	}
	for(k=0;k<tg->arcnum;k++)
	{
	
		if(!p) printf("分配失败！");
		printf("请输入有向网相连的两个顶点：\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		p=(arcnode*)malloc(sizeof(arcnode));
		if(!p) printf("分配失败！");
		i=locate_adj_vex(tg,v1);
		j=locate_adj_vex(tg,v2); 
		p->adjvex=j;
		p->arcnext=tg->vertices[j].firstarc;
		tg->vertices[i].firstarc=p;
	    printf("请给有向网加入权值：\n");
		scanf("%d",&p->info);
		getchar();
	    
		}
} 
void adj_table_no_net(LGraph *tg)    //无向网的邻接表 
{
    
	int i,j,k;
	char v1,v2;
	arcnode *p,*q;
	printf("请输入邻接表存储无向图的顶点数和弧的数(注意vex<=20,arc<=40:\n");
	scanf("%d %d",&tg->vexnum,&tg->arcnum);
	getchar();
		for(i=0;i<tg->vexnum;i++)
	{
		printf("请向无向图的顶点输入字符：\n");
		scanf("%c",&tg->vertices[i].data);
		getchar();
		tg->vertices[i].firstarc=NULL;
	}
	for(k=0;k<tg->arcnum;k++)
	{
	
	
		printf("请输入无向网相连的两个顶点：\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		p=(arcnode*)malloc(sizeof(arcnode));
		if(!p) printf("分配失败！");
		i=locate_adj_vex(tg,v1);
		j=locate_adj_vex(tg,v2); 
		p->adjvex=i;    
		p->arcnext=tg->vertices[j].firstarc;
		tg->vertices[j].firstarc=p;
		q=(arcnode*)malloc(sizeof(arcnode));
		if(!q) printf("分配失败！");
		q->adjvex=j;
		q->arcnext=tg->vertices[i].firstarc;
		tg->vertices[i].firstarc=q; 
		printf("请给无向网加入权值：");
        scanf("%d",&p->info);
		getchar();
		q->info=p->info;
		
	}	
	
}
