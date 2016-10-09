#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 
#include<math.h>
#define MaxSize  100
#define MAX_NUM  20     //图的顶点最大数 
#define  OK 1
#define ERROR  0
#define  MAX_VERTEX_NUM  20   //最大顶点个数 
#define MAX 10000    //构造最小生成数所用的最大数 


/****************************构造图的一些相关顶点和边（弧）结点结构*************************/

/***************构造图的邻接矩阵结构***********************/ 

typedef struct M{        
	
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

/** 队列定义及相关操作(广度遍历会用到此循环队列) **/
typedef struct LoopQueue{ 
    int data[MAX_NUM];
    int front,rear;
}LoopQueue,*Queue; //队列结构

//辅助数组元素   
typedef struct    
{   
    int from;   
    int to;   
   int weight;   
    int flag;   
}ArrayNode;

//边的结构 
typedef struct  
{  
    int u;     //边的起始顶点  
    int v;     //边的终止顶点  
    int w;     //边的权值  
} edge; 

/***********************************关键路径有关的结构**********************/

typedef int VertexType;  
  
typedef struct Edge {  
    VertexType begin;    //启始点 
    VertexType end;    //边的尾部 
    int weight;       //权值 
}Edgenode;  
  
typedef struct Graph {  
    VertexType *ver;  
    Edgenode *Edge;  
    int VertexNum;  
    int EdgeNum;  
    int *In;  
}Graph; 
/**********************************/  

typedef  int  vextype;
typedef vextype mgraph[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
Mgraph g,g1;   //声明一个邻接矩阵的图 
LGraph tg;   // 声明邻接表 
int n,e;      //定义全局变量 


/***************************结束******************/

 

//typedef struct MGraph{
	
//}MG,*MGraph;

/******************函数声明*********************************/
void FindCPath( Graph *g );//关键路径查找函数  
void CreateGraph( Graph **g, int nver, int nedg ); 
void InsertSort(edge E[],int n);
void Kruskal(Mgraph *g) ;
void Dispath(int dist[],int path[],int s[],int n,int v); //输出最短路径  
void Ppath(int path[],int i,int v); //前向递归查找路径上的顶点  
void Dijkstra(Mgraph *g,int v);   //迪杰斯特拉 
void SetWeight(Mgraph *g ) ;    //设置未相连边的权值 
void prim( Mgraph *g,  int *parent );  //运用prim算法求最小生成树 
void PrintMST( Mgraph *g, int *parent );  //打印最小生成数 
void TopologicalSort(Mgraph *g);   //拓扑排序 
void prim(Mgraph *g, Mgraph *tree);   
void initTree(Mgraph *tree);   
void disp(LGraph *tg);
void BFSTraverse(LGraph *tg);  
void initQueue(Queue &Q);   //构造队列 
int QueueFull(Queue &Q);   //队列判空 
void EnQueue(Queue &Q,int e);  //入队 
void DeQueue(Queue &Q,int *e);   //出队 
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
void LBFS(LGraph *tg);  //广度优先遍历 
int visited[MAX_NUM ];   //访问数组
int Ladjvex(LGraph *tg,int k);   //位置 


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

	int i,n;
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
				printf("邻接表的深度优先遍历\n");
				for(i=0;i<tg.vexnum;i++)
				visited[i]=0;
				for(i=0;i<tg.vexnum;i++)
				   if(!visited[i])
				    DFS(&tg, i);
				break;
			case 4:
				
			    printf("邻接表的广度优先遍历：\n");
			    BFSTraverse(&tg);
				break;
			default:
				if (n!=5)
					printf("错误，重新输入\n");
		}
	}while(n!=5);
}

void UDN()   // 无向网交互界面函数 
{
	LGraph tree;
	int parent[MAX_NUM ];

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
			       adj_table_no_net(&tg);
				
			case 3:
			
				SetWeight(&g );
				 prim(&g,parent );
				  PrintMST(&g,parent );  
				
				break;
			case 4:
				 printf("最小生成树为：\n");
				 Kruskal(&g); 
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
                
               
				break;
			case 3:
			
				TopologicalSort(&g);
				break;
			default:
				if (n!=4)
					printf("错误，重新输入\n");
		}
	}while(n!=4);
}

void DN()      //有向网交互界面 
{

	int n,i;
     Graph *vg;  
    int VertexNum, EdgeNum;  

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
				adj_table_h_net(&tg);
				break;
			case 3:
				
               int VertexNum, EdgeNum;  
                printf("请输入要创建的AOE网的顶点数和边数:\n");  
                scanf("%d %d", &VertexNum, &EdgeNum); 
				getchar(); 
                CreateGraph( &vg , VertexNum, EdgeNum);  
                FindCPath( vg );  
				break;
			case 4:
				 
				 printf("请输入单源点起点:suchas(1-n)\n");
				 scanf("%d",&i);
				 getchar();
				 SetWeight(&g );
				 Dijkstra(&g,i); 
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

 

void creat_mygraph1(Mgraph *g)      //无向图邻接矩阵 
{
	int i,j,k;
	char v1,v2;
	printf("请输入无向图的顶点数和弧的数:\n");
	scanf("%d %d",&g->vexnum,&g->arcnum);
	getchar();
	printf("请向无向图的顶点输入字符：\n");
	for(i=0;i<g->vexnum;i++)
	{
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
int locatevex(Mgraph *mg,char v)     //邻接矩阵的顶点位置确定 
{
	int i;
	for(i=0;mg->vexs[i]!=v;i++)
	  if(i>mg->vexnum)
	     printf("ERROR");
	     return i;

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
int locate_adj_vex(LGraph *tg,char v)   //寻找v所在图的位置 
{
	int i;
	for(i=0;tg->vertices[i].data!=v;i++)
	if(i>tg->vexnum)
	printf("寻找失败！");
	return i;
		
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
	printf("请输入邻接表存储无向网的顶点数和弧的数(注意vex<=20,arc<=40:\n");
	scanf("%d %d",&tg->vexnum,&tg->arcnum);
	getchar();
		for(i=0;i<tg->vexnum;i++)
	{
		printf("请向无向网的顶点输入字符：\n");
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
void DFS(LGraph *tg,int i)
{
	int k;
	visited[i]=OK;
	printf("%c",tg->vertices[i].data);
	for(k=Ladjvex(tg,i);k>=0;k=Ladjvex(tg,k))
		if(!visited[k])
			DFS(tg,k);
	
} 
int Ladjvex(LGraph *tg,int k)    //返回下标k的邻接点 
{
   arcnode *p;
   for(p=tg->vertices[k].firstarc;p!=NULL;p=p->arcnext)
   	if(!visited[p->adjvex])
   	   return p->adjvex;
   	    return -1;
}
void initQueue(Queue &Q){
    Q->front=Q->rear=0;
}

int QueueEmpty(Queue &Q){
    if(Q->front == Q->rear){
        return 1;
    }else{
        return 0;
    }
}

int QueueFull(Queue &Q){
    if((Q->rear+1)%MAX_NUM == Q->front){
        return 1;
    }else{
        return 0;
    }
}

/**
 * 队尾插入元素
 */
void EnQueue(Queue &Q,int e){
    if(!QueueFull(Q)){
        Q->data[Q->rear] = e;
        Q->rear = (Q->rear+1)%MAX_NUM;
    }
}

/**
 * 队头删除元素
 */
void DeQueue(Queue &Q,int *e){
    if(!QueueEmpty(Q)){
        *e = Q->data[Q->front];  
        Q->front = (Q->front+1)%MAX_NUM;
    }
}

void disp(LGraph *tg)
{
	arcnode *p;
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
void BFSTraverse(LGraph *tg)    //深度优先遍历
{  
    int i;  
    Queue Q = (Queue)malloc(sizeof(LoopQueue));  

    for (i=0; i<tg->vexnum; ++i){  
        visited[i] =0; 
    } 
    initQueue(Q);  
    
    for (i=0; i<tg->vexnum; ++i){  
        if(!visited[i]){  
            visited[i] =1;  
            printf("%c ", tg->vertices[i].data);  
            EnQueue(Q, i);  

            while (!QueueEmpty(Q)){  
                DeQueue(Q, &i);  
                arcnode *p; 
					p= tg->vertices[i].firstarc;  
                while (p){  
                    if (!visited[p->adjvex]){  
                        visited[p->adjvex] =1;  
                        printf("%c ", tg->vertices[p->adjvex].data);  
                        EnQueue(Q, p->adjvex);  
                    }  
                    p = p->arcnext;  
                }
            }
        }  
    }    
}

//拓扑排序   
void TopologicalSort(Mgraph *g)   
{   
   int i,j,k=0,m;   
    char vertex[MAX_VERTEX_NUM];   
 
 while(k<g->vexnum){   
     //1.找没有入度的顶点,存入数组vertex中   
       for(i=0;i<g->vexnum;i++){   
           for(j=0;j<g->vexnum;j++){   
                if(g->arcs[j][i]!=0)   //其他的顶点到i顶点 
                    break;   
            }   
            if(j==g->vexnum){   
               //检查g->vertex[i]是否已经遍历   
                for(m=0;m<k;m++)   
                   if(vertex[m]==g->vexs[i])   
                        break;   
                if(m==k){   
                    vertex[k++]=g->vexs[i];   
                   break;   
               }            
			    }          
				 }   
       //2.没有入度为0的顶点   
      if(i==g->vexnum){   
           printf("存在回路!\n");   
            return ;   
     }   
    //3.删除这个顶点的出度   
    for(j=0;j<g->vexnum;j++)   
            g->arcs[i][j]=0;   
    }   
   //输出排序后的结果   
    printf("拓扑排序结果：\n");   
    for(i=0;i<k;i++)   
    printf("%-3c",vertex[i]);   
   printf("\n");   
}
//将不邻接的顶点之间的权值设置为MAX  
void SetWeight( Mgraph *g )  
{  
    for( int i=0; i<g->vexnum; i++ )  
        for( int j=0; j<g->vexnum; j++ )  
            if( 0 == g->arcs[i][j] )  
                g->arcs[i][j] = MAX;  
}
//运用prim算法求最小生成树  
void prim( Mgraph *g,  int *parent )  
{  
    int i, j, k;  
    int lowcost[MAX_NUM];  
    int closest[MAX_NUM], used[MAX_NUM];  
    int min;  
  
    for( i=0; i<g->vexnum; i++ ) {          //对辅助数组lowcost和closest进行初始化  
        lowcost[i] = g->arcs[0][i];  
        closest[i] = 0;  
        used[i] = 0;                    //used[i] == 0 表示i顶点在U中，反之，在V-U中。  
        parent[i] = -1;  
    }  
  
    used[0] = 1;                        //第一步将编号为0的顶点放入U中，也可以是其他顶点  
  
    for( i=0; i<g->vexnum-1; i++ ) {  
        j = 0;  
        min = MAX;  
  
        for( k=1; k<g->vexnum; k++ )        //找到V-U中的与U中顶点组成的最小权值的边的顶点编号  
            if( (0==used[k]) && (lowcost[k]<min) ) {  
                min = lowcost[k];  
                j = k;  
            }  
  
        parent[j] = closest[j];  
  
        used[j] = 1;                    //将j顶点加入U中  
  
        for( k=0; k<g->vexnum; k++ )        //由于j顶点加入U中，更新lowcost和closest数组中的元素，检测V-U中的顶点到j顶点的权值是否比j加入U之前的lowcost数组的元素小  
            if( (0==used[k]) && (g->arcs[k][j]<lowcost[k]) ) {  
                lowcost[k] = g->arcs[k][j];  
                closest[k] = j;         //closest数组保存的是U中到V-U中最小权值的顶点编号  
            }  
    }  
} 
//打印最小生成树的边和MST的权值  
void PrintMST( Mgraph *g, int *parent )  
{  
    int weight = 0;  
    printf("MST的边为:\n");  
    for( int i=1; i<g->vexnum; i++ ) {       //VerNum-1条边  
        printf("%c--%c\n", g->vexs[parent[i]], g->vexs[i] );  
        weight+=g->arcs[parent[i]][i];      //权值之和 
    }  
    printf("MST的权值为:%d\n", weight);  
}        
void Ppath(int path[],int i,int v)  //前向递归查找路径上的顶点  
{  
    int k;  
    k=path[i];  
    if (k==v)  return;          //找到了起点则返回  
    Ppath(path,k,v);            //找顶点k的前一个顶点  
    printf("%d,",k);            //输出顶点k  
}  
void Dispath(int dist[],int path[],int s[],int n,int v)  
{  
    int i;  
    for (i=0; i<n; i++)  
        if (s[i]==1)  
        {  
            printf("  从%d到%d的最短路径长度为:%d\t路径为:",v,i,dist[i]);  
            printf("%d,",v);    //输出路径上的起点  
            Ppath(path,i,v);    //输出路径上的中间点  
            printf("%d\n",i);   //输出路径上的终点  
        }  
        else  printf("从%d到%d不存在路径\n",v,i);  
}  
void Dijkstra(Mgraph *g,int v) 
{  
    int dist[MAX_NUM],path[MAX_NUM];  
    int s[MAX_NUM];  
    int mindis,i,j,u;  
    for (i=0; i<g->vexnum; i++)  
    {  
        dist[i]=g->arcs[v][i];      //距离初始化  
        s[i]=0;                    //s[]置空  
        if (g->arcs[v][i]<MAX)      //路径初始化  
            path[i]=v;  
        else  
            path[i]=-1;  
    }  
    s[v]=1;   //标志位 
    path[v]=0;              //源点编号v放入s中  
    for (i=0; i<g->vexnum; i++)               //循环直到所有顶点的最短路径都求出  
    {  
        mindis=MAX;                 //mindis置最小长度初值  
        for (j=0; j<g->vexnum; j++)       //选取不在s中且具有最小距离的顶点u  
            if (s[j]==0 && dist[j]<mindis)  
            {  
                u=j;  
                mindis=dist[j];  
            }  
        s[u]=1;                     //顶点u加入s中  
        for (j=0; j<g->vexnum; j++)       //修改不在s中的顶点的距离  
            if (s[j]==0)  
                if (g->arcs[u][j]<MAX && dist[u]+g->arcs[u][j]<dist[j])  
                {  
                    dist[j]=dist[u]+g->arcs[u][j];  
                    path[j]=u;  
                }  
    }  
    Dispath(dist,path,s,g->vexnum,v);     //输出最短路径  
}
void InsertSort(edge E[],int n) //对E[0..n-1]按递增有序进行直接插入排序  
{  
    int i,j;  
    edge temp;  
    for (i=1; i<n; i++)  
    {  
        temp=E[i];  
        j=i-1;              //从右向左在有序区E[0..i-1]中找E[i]的插入位置  
        while (j>=0 && temp.w<E[j].w)  
        {  
            E[j+1]=E[j];    //将关键字大于E[i].w的记录后移  
            j--;  
        }  
        E[j+1]=temp;        //在j+1处插入E[i]  
    }  
}  
  
void Kruskal(Mgraph *g)  
{  
    int i,j,u1,v1,sn1,sn2,k;  
    int vset[MAX_NUM];  
    edge E[MaxSize];    //存放所有边  
    k=0;                //E数组的下标从0开始计  
    for (i=0; i<g->vexnum; i++)   //由g产生的边集E  
        for (j=0; j<g->vexnum; j++)  
            if (g->arcs[i][j]!=0 && g->arcs[i][j]!=MAX)  
            {  
                E[k].u=i;  
                E[k].v=j;  
                E[k].w=g->arcs[i][j];  
                k++;  
            }  
    InsertSort(E,g->arcnum);      //采用直接插入排序对E数组按权值递增排序  
    for (i=0; i<g->vexnum; i++)   //初始化辅助数组  
        vset[i]=i;  
    k=1;    //k表示当前构造生成树的第几条边,初值为1  
    j=0;    //E中边的下标,初值为0  
    while (k<g->vexnum)       //生成的边数小于n时循环  
    {  
        u1=E[j].u;  
        v1=E[j].v;      //取一条边的头尾顶点  
        sn1=vset[u1];  
        sn2=vset[v1];   //分别得到两个顶点所属的集合编号  
        if (sn1!=sn2)   //两顶点属于不同的集合  
        {  
            printf("  (%d,%d):%d\n",u1,v1,E[j].w);  
            k++;                     //生成边数增1  
            for (i=0; i<g->vexnum; i++)   //两个集合统一编号  
                if (vset[i]==sn2)   //集合编号为sn2的改为sn1  
                    vset[i]=sn1;  
        }  
        j++;               //扫描下一条边  
    }  
} 
//创建AOE网  
void CreateGraph( Graph **g, int nver, int nedg )  
{  
    int i, j;  
    (*g) = (Graph *)malloc(sizeof(Graph));  
    (*g)->VertexNum = nver;  
    (*g)->EdgeNum = nedg;  
    int EdgeNum = (*g)->EdgeNum;  
    int VertexNum= (*g)->VertexNum ;  
    (*g)->Edge = (Edge *)malloc(sizeof(Edge)*(EdgeNum+1));  
    (*g)->In = (int *)malloc(sizeof(int)*(VertexNum+1));  
    (*g)->ver = (int *)malloc(sizeof(int)*(VertexNum+1));  
  
    printf("请输入AOE网的顶点:\n");  
    for( i=1; i<=VertexNum; i++ )            //存储顶点  
        scanf("%d", &(*g)->ver[i]);  
  
    for( i=1; i<=VertexNum; i++ )            //顶点的入度数组初始化为0  
        (*g)->In[i] = 0;  
  
    printf("请输入AOE网的边的头、尾和权值:\n");  
    for( i=1; i<=EdgeNum; i++ ) {  
        printf("a%d: ", i);  
        scanf("%d %d %d", &((*g)->Edge[i].begin) , &((*g)->Edge[i].end) , &((*g)->Edge[i].weight) );  
        j = (*g)->Edge[i].end;  
        (*g)->In[j]++;  
    }  
}  
  
//关键路径查找函数  
void FindCPath( Graph *g )  
{  
    int VertexNum = g->VertexNum ;  
    int EdgeNum = g->EdgeNum ;  
    int end;  
    int TopIndex;  
    int *Top = (int *)malloc(sizeof(int)*(VertexNum+1));    //Top数组用来存储AOE网的拓扑序列的编号  
    int *ve = (int *)malloc(sizeof(int)*(VertexNum+1));     //ve[i]表示事件Vi的最早开始时间      
    int *vl = (int *)malloc(sizeof(int)*(VertexNum+1));     //vl[i]表示事件Vi的最迟开始时间  
    int *e = (int *)malloc(sizeof(int)*(VertexNum+1));      //e[i]表示活动ai的最早开始时间  
    int *l = (int *)malloc(sizeof(int)*(VertexNum+1));      //l[i]表示活动ai的最迟开始时间  
    int i, j, k;  
  
    for( i=1; i<=VertexNum; i++ )  
        for( j=1; j<=VertexNum; j++ )  
            if( 0 == g->In[j] ) {  
                g->In[j] = -1;  
                Top[i] = j;  
                for( k=1; k<=EdgeNum; k++ )  
                    if( g->Edge[k].begin == g->ver[j] ) {  
                        end = g->Edge[k].end;  
                        g->In[end]--;  
                    }  
                break;  
            }  
  
    //求ve[i]  
    for( i=1; i<=VertexNum; i++ )    //ve数组初始化  
        ve[i] = 0;  
    for( i=1; i<=VertexNum; i++ ) {  
        TopIndex = Top[i];  
        for( j=1; j<=EdgeNum; j++ )  
            if( (g->ver[TopIndex] == g->Edge[j].begin) && (ve[g->Edge[j].end] < ve[TopIndex] + g->Edge[j].weight) )  
                ve[g->Edge[j].end] = ve[TopIndex] + g->Edge[j].weight;  
    }  
  
    //求vl[i]  
    for( i=1; i<=VertexNum; i++ )  
        vl[i] = ve[VertexNum];  
    for( i=VertexNum; i>=1; i-- ) {  
        TopIndex = Top[i];          //用逆拓扑序列求vl  
        for( j=1; j<=EdgeNum; j++ )  
            if( (g->Edge[j].end == g->ver[TopIndex]) && (vl[g->Edge[j].begin] > vl[TopIndex] - g->Edge[j].weight) )  
                vl[g->Edge[j].begin] = vl[TopIndex] - g->Edge[j].weight;  
    }  
  
    //求e[i]  
    for( i=1; i<=EdgeNum; i++ )  
        e[i] = ve[g->Edge[i].begin];  
  
    //求l[i]  
    for( i=1; i<=EdgeNum; i++ )  
        l[i] = vl[g->Edge[i].end] - g->Edge[i].weight;  
  
    printf("该AOE网的关键活动为:\n");  
    for( i=1; i<=EdgeNum; i++ )  
        if( e[i] == l[i] )  
            printf("a%d ", i);  
        printf("\n");  
}     
  

