/******************************宏定义*******************************/ 
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

/***************************结束******************/

 

//typedef struct MGraph{
	
//}MG,*MGraph;

/******************函数声明*********************************/
void InitQueue();//初始化队列
int QueueIsEmpty(Queue *Q);  //判断队列是否为空 
int creat_Graph(Mgraph *mg,LGraph *lg);   //创建邻接矩阵和邻接表的图   * 
int locatevex(Mgraph *mg,char v);   //找出图的某个顶点位置    * 
void creat_mygraph1(Mgraph *g);   //创建无向图邻接矩阵       * 
void adj_table_noway(LGraph *tg);     //无向图邻接表 
void creat_hway_graph(Mgraph *g);  //创建有向图邻接矩阵      * 
void adj_table_hway(LGraph *tg);   //有向图邻接表    *
void creat_nonet(Mgraph *g);  //创建无向网    * 
void adj_table_no_net(LGraph *tg);    //无向网邻接表 
void have_w_net(Mgraph *g);   //创建有向网     *
void  adj_table_h_net(LGraph *tg);   //有向网邻接表 
int locate_adj_vex(LGraph *tg,char v);   //邻接表的顶点定位 
void DFS(LGraph *tg,int i);  //深度优先遍历 
void LBFS(LGraph *tg,int i);  //广度优先遍历 
int visited[MAX_NUM ];   //访问数组
int Ladjvex(LGraph *tg,int k);   //位置 
void  bianli(Mgraph *g);
typedef  int  vextype;
typedef vextype mgraph[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
mgraph G1;
Mgraph g,g1;   //声明一个邻接矩阵的图 
LGraph tg;   // 声明邻接表 
int n,e;      //定义全局变量 
void creat_mygrap(mgraph G);
void out_mygraph(mgraph G);
void ShowMainMenu()   //主界面交互 
{
	printf("\n");
	printf("  ***************图的基本操作及应用******************\n");
	printf("  *  1 无向图的基本操作及应用                      *\n");
	printf("  *  2 无向网的基本操作及应用                      *\n");
    printf("  *  3 有向图的基本操作及应用                      *\n");
	printf("  *  4 有向网的基本操作及应用                      *\n");
	printf("  *  5 退出                                        *\n");
	printf("  ***************************************************\n");
}

void UDG()    //无向图交互界面 
{

	int i,v,n;
	do
	{
		printf("\n");
		printf("  ***************无向图的基本操作及应用***************\n");
	     printf("  *  1 创建无向图的邻接矩阵                         *\n");
		printf("  *  2 创建无向图的邻接表                           *\n");
	     printf("  *  3 无向图的深度优先遍历                         *\n");
	     printf("  *  4 无向图的广度优先遍历                         *\n");
		printf("  *  5 退出                                         *\n");
	     printf("  ****************************************************\n");
		scanf("%d",&n);
		switch(n){
			case 1:
			   //creat_mygrap(G1);
			   creat_mygraph1(&g);
				break;
			case 2:
			 	adj_table_noway(&tg);
				break;
				
			case 3:
				adj_table_noway(&tg);
				printf("邻接表的深度优先遍历\n");
				for(i=0;i<tg.vexnum;i++)
				visited[i]=0;
				for(i=0;i<tg.vexnum;i++)
				   if(!visited[i])
				    DFS(&tg, i);
				break;
			case 4:
				break;
			default:
				if (n!=5)
					printf("错误，重新输入\n");
		}
	}while(n!=5);
}

void UDN()   // 无向网交互界面函数 
{

	int n;
	do{
		printf("\n");
		printf("  ***************无向网的基本操作及应用***************\n");
	     printf("  *  1 创建无向网的邻接矩阵                         *\n");
		printf("  *  2 创建无向网的邻接表                           *\n"); 
	     printf("  *  3 prim算法求最小生成树                         *\n");
		printf("  *  4 kraskal算法求最小生成树                      *\n");
		printf("  *  5 退出                                         *\n");
	     printf("  ****************************************************\n");
		scanf("%d",&n);
		switch(n){
			case 1:
					creat_nonet(&g);
				break;
			case 2:
			
				
			case 3:
				break;
			case 4:
				break;
			default:
				if (n!=5)
					printf("错误，重新输入\n");
		}
	}while(n!=5);
	
}

void DG()    //有向图交互界面 
{

	int n,v,i;
	do
	{
		printf("\n");
		printf("  ***************有向图的基本操作及应用***************\n");
	     printf("  *  1 创建有向图的邻接矩阵                         *\n");
		printf("  *  2 创建有向图的邻接表                           *\n");
	     printf("  *  3 拓扑排序                                     *\n");
		printf("  *  4 退出                                         *\n");
	     printf("  ****************************************************\n");
		scanf("%d",&n);
		switch(n){
			case 1:
				creat_hway_graph(&g); 
				break;
			case 2:
                adj_table_hway(&tg);
                printf("请输入遍历的第一个顶点\n");
                scanf("%c",&v);
                i=locate_adj_vex(&tg,v);
                 DFS(&tg,i);
				break;
			case 3:
				break;
			default:
				if (n!=4)
					printf("错误，重新输入\n");
		}
	}while(n!=4);
}

void DN()      //有向网交互界面 
{

	int n;
	do{
		printf("\n");
		printf("  ***************有向网的基本操作及应用***************\n");
	     printf("  *  1 创建有向网的邻接矩阵                         *\n");
		printf("  *  2 创建有向网的邻接表                           *\n");
	     printf("  *  3 关键路径                                     *\n");
		printf("  *  4 单源顶点最短路径问题                         *\n");
		printf("  *  5 退出                                         *\n");
	     printf("  ****************************************************\n");
		scanf("%d",&n);
		switch(n){
			case 1:
				have_w_net(&g);   
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				if (n!=6)
					printf("错误，重新输入\n");
		}
	}while(n!=6);
	
}

int main()     //入口函数 
{
	int n;
	do{
		ShowMainMenu();
		scanf("%d",&n);
		switch(n){
			case 1:
				UDG();
				break;
			case 2:
                UDN();
				break;
			case 3:
				DG();
				break;
			case 4:
				DN();
				break;
			default:
				if (n!=5)
					printf("错误，重新输入\n");
		}
	}while(n!=5);
}

/**********************函数实现*******************************/

 void creat_mygrap(mgraph G)    //创建邻接矩阵 
 {
		int i,j,k;
	   printf("please input the number of vex and arc:such as(6,7)\n");
	   scanf("%d%d",&n,&e);
	   getchar(); 
	   for(i=0;i<n;i++)
	     {
				for(j=0;j<n;j++)
				G[i][j]=0;
		}
		for(k=0;k<e;k++)
		{
			printf("please input the arc of two vex:such as(2,3)\n");
			scanf("%d%d",&i,&j);
			getchar();
			G[i][j]=1;
		    G[j][i]=1;
			
			}
			void out_mygraph();	
	} 
void out_mygraph(mgraph G)     //输出邻接矩阵 
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("5%d",&G[i][j]);
			}
		}
}
void creat_mygraph1(Mgraph *g)      //无向图 
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
}
int locatevex(Mgraph *mg,char v)     
{
	int i;
	for(i=0;mg->vexs[i]!=v;i++)
	  if(i>mg->vexnum)
	     printf("ERROR");
	     return i;

}
void creat_hway_graph(Mgraph *g)    //有向图 
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
		scanf("%c",&(g->vexs[i]));
		getchar();
		
	}
	for(j=0;j<g->vexnum;j++)
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
		scanf("%d",&(g->arcs[i][j]));
		getchar(); 
			
	}

} 
void bianli(Mgraph *g)
{int i,j;
	for(i=0;i<g->vexnum;i++)
	{   for(j=0;j<g->vexnum;j++)
		printf("矩阵的元素输出为：%d",g->arcs[i][j]);
		
		}
}

void have_w_net(Mgraph *g)     //有向网 
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
		g->arcs[i][j]=1;
		 
		 
		}
	
}
void adj_table_hway(LGraph *tg)
{
		int i,j,k;
	char v1,v2;
	arcnode *p,*q;
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
int locate_adj_vex(LGraph *tg,char v)
{
	int i;
	for(i=0;tg->vertices[i].data!=v;i++)
	if(i>tg->vexnum)
	printf("寻找失败！");
	return i;
		
}
void adj_table_noway(LGraph *tg)
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
		tg->vertices[j].firstarc=p;
		q=(arcnode*)malloc(sizeof(arcnode));
		if(!q) printf("分配失败！");
		q->adjvex=j;
		q->arcnext=tg->vertices[i].firstarc;
		tg->vertices[i].firstarc=q; 	
		}
	
	
}
void  adj_table_h_net(LGraph *tg)    //有向网 
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
		q=(arcnode*)malloc(sizeof(arcnode));
		if(!q) printf("分配失败！");
		q->adjvex=j;
		q->arcnext=tg->vertices[i].firstarc;
		tg->vertices[i].firstarc=q; 
	    
		}
} 
void adj_table_no_net(LGraph *tg)    //无向网 
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
		tg->vertices[j].firstarc=p;
		q=(arcnode*)malloc(sizeof(arcnode));
		if(!q) printf("分配失败！");
		q->adjvex=j;
		q->arcnext=tg->vertices[i].firstarc;
		tg->vertices[i].firstarc=q; 
		
	}	
	
}
void DFS(LGraph *tg,int i)
{
	int k;
	visited[i]=OK;
	printf("%c",tg->vertices[i].data);
	for(k=Ladjvex(tg,i);k>=0;k=Ladjvex(tg,k))
		if(!visited[k])
			DFS(tg,k);
	
} 
int Ladjvex(LGraph *tg,int k)
{
   arcnode *p;
   for(p=tg->vertices[k].firstarc;p!=NULL;p=p->arcnext)
   	if(!visited[p->adjvex])
   	   return p->adjvex;
   	    return -1;
}
void LBFS(LGraph *tg,int i)
{
	
	}



