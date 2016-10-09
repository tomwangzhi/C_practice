#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 
#include<math.h>
#define MAX_NUM  20     //图的顶点最大数 
#define  OK 1
#define ERROR  0
#define  MAX_VERTEX_NUM  20   //最大顶点个数 


/****************************构造图的一些相关顶点和边（弧）结点结构*************************/

/***************构造图的邻接矩阵结构***********************/ 

typedef struct {        
	
	char vexs[MAX_NUM];         //存放顶点的数组 
	int arcs[MAX_NUM][MAX_NUM];   //邻接矩阵的二维数组 
	int vexnum,arcnum;          //图的当前顶点数和边（弧）的数 
}Mgraph;      //邻接矩阵存储的图 
/************************结束*****************************/


/*******************构造边(弧）的结构************************/ 
typedef struct  arcnode{
	
	int adjvex;    //该弧所指的顶点 
	struct arcnode *arcnext;    //指向下一条弧指针 
	int info;
	

}arcnode;        //弧结点结构 

/**********************结束**************************/



/**********************顶点结构*********************/ 
typedef struct vnode{
	
	char data;            //顶点所存放的数据 
	arcnode *firstarc;     //指向第一条依附该顶点的指针 
}vnode,Adjlist[MAX_NUM];   //存放顶点的邻接表 
/***********************结束*********************/


/*******************声明邻接表存储的图的结构**********************/ 
typedef struct G{
	
   Adjlist vertices;     //包含所有顶点以及顶点和边或弧关系的结构体数组 
	int vexnum,arcnum;

}LGraph;         //邻接表存储的图 
typedef struct Queue{
	int arry[MAX_NUM ];
	int front,rear;
}Queue;
Queue Q;
int locate_adj_vex(LGraph *tg,char v)
{
	int i;
	for(i=0;tg->vertices[i].data!=v;i++)
	if(i>tg->vexnum)
	printf("寻找失败！");
	return i;
		
}
void disp(LGraph *tg)
{
	arcnode *p;
	p=(arcnode*)malloc(sizeof(arcnode));
	int i;
	for(i=0;i<tg->vexnum;i++)
	{
		p=tg->vertices[i].firstarc;
		while(!p)
		{
			printf("%d %c",i,&p->adjvex);
			p=p->arcnext;
		}
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
		scanf("%c",&(tg->vertices[i].data));
		getchar();
		tg->vertices[i].firstarc=NULL;
	}
	for(k=0;k<tg->arcnum;k++)
	{
	
		
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

int main()
{int i;
	LGraph tg;   // 声明邻接表 
	adj_table_noway(&tg);
	for(i=0;i<tg.vexnum;i++)
	printf("%c\n",tg.vertices[i].data);
	 disp(&tg);
	return 0;
}
