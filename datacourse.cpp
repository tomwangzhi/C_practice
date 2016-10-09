#include<stdio.h>
#include<stdlib.h>
#include<malloc.h> 
#include<math.h>
#define MaxSize  100
#define MAX_NUM  20     //ͼ�Ķ�������� 
#define  OK 1
#define ERROR  0
#define  MAX_VERTEX_NUM  20   //��󶥵���� 
#define MAX 10000    //������С���������õ������ 


/****************************����ͼ��һЩ��ض���ͱߣ��������ṹ*************************/

/***************����ͼ���ڽӾ���ṹ***********************/ 

typedef struct M{        
	
	char vexs[MAX_NUM];         //��Ŷ�������� 
	int arcs[MAX_NUM][MAX_NUM];   //�ڽӾ���Ķ�ά���� 
	int vexnum,arcnum;          //ͼ�ĵ�ǰ�������ͱߣ��������� 
}Mgraph;      //�ڽӾ���洢��ͼ 
/************************����*****************************/


/*******************�����(�����Ľṹ************************/ 
typedef struct  arcnode{
	
	int adjvex;    //�û���ָ�Ķ��� 
	struct arcnode *arcnext;    //ָ����һ����ָ�� 
	int info;
	

}arcnode;        //�����ṹ 

/**********************����**************************/



/**********************����ṹ*********************/ 
typedef struct vnode{
	
	char data;            //��������ŵ����� 
	arcnode *firstarc;     //ָ���һ�������ö����ָ�� 
}vnode,Adjlist[MAX_NUM];   //��Ŷ�����ڽӱ� 
/***********************����*********************/


/*******************�����ڽӱ�洢��ͼ�Ľṹ**********************/ 
typedef struct G{
	
   Adjlist vertices;     //�������ж����Լ�����ͱ߻򻡹�ϵ�Ľṹ������ 
	int vexnum,arcnum;

}LGraph;         //�ڽӱ�洢��ͼ 

/** ���ж��弰��ز���(��ȱ������õ���ѭ������) **/
typedef struct LoopQueue{ 
    int data[MAX_NUM];
    int front,rear;
}LoopQueue,*Queue; //���нṹ

//��������Ԫ��   
typedef struct    
{   
    int from;   
    int to;   
   int weight;   
    int flag;   
}ArrayNode;

//�ߵĽṹ 
typedef struct  
{  
    int u;     //�ߵ���ʼ����  
    int v;     //�ߵ���ֹ����  
    int w;     //�ߵ�Ȩֵ  
} edge; 

/***********************************�ؼ�·���йصĽṹ**********************/

typedef int VertexType;  
  
typedef struct Edge {  
    VertexType begin;    //��ʼ�� 
    VertexType end;    //�ߵ�β�� 
    int weight;       //Ȩֵ 
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
Mgraph g,g1;   //����һ���ڽӾ����ͼ 
LGraph tg;   // �����ڽӱ� 
int n,e;      //����ȫ�ֱ��� 


/***************************����******************/

 

//typedef struct MGraph{
	
//}MG,*MGraph;

/******************��������*********************************/
void FindCPath( Graph *g );//�ؼ�·�����Һ���  
void CreateGraph( Graph **g, int nver, int nedg ); 
void InsertSort(edge E[],int n);
void Kruskal(Mgraph *g) ;
void Dispath(int dist[],int path[],int s[],int n,int v); //������·��  
void Ppath(int path[],int i,int v); //ǰ��ݹ����·���ϵĶ���  
void Dijkstra(Mgraph *g,int v);   //�Ͻ�˹���� 
void SetWeight(Mgraph *g ) ;    //����δ�����ߵ�Ȩֵ 
void prim( Mgraph *g,  int *parent );  //����prim�㷨����С������ 
void PrintMST( Mgraph *g, int *parent );  //��ӡ��С������ 
void TopologicalSort(Mgraph *g);   //�������� 
void prim(Mgraph *g, Mgraph *tree);   
void initTree(Mgraph *tree);   
void disp(LGraph *tg);
void BFSTraverse(LGraph *tg);  
void initQueue(Queue &Q);   //������� 
int QueueFull(Queue &Q);   //�����п� 
void EnQueue(Queue &Q,int e);  //��� 
void DeQueue(Queue &Q,int *e);   //���� 
int creat_Graph(Mgraph *mg,LGraph *lg);   //�����ڽӾ�����ڽӱ��ͼ   * 
int locatevex(Mgraph *mg,char v);   //�ҳ�ͼ��ĳ������λ��    * 
void creat_mygraph1(Mgraph *g);   //��������ͼ�ڽӾ���       * 
void adj_table_noway(LGraph *tg);     //����ͼ�ڽӱ� 
void creat_hway_graph(Mgraph *g);  //��������ͼ�ڽӾ���      * 
void adj_table_hway(LGraph *tg);   //����ͼ�ڽӱ�    *
void creat_nonet(Mgraph *g);  //����������    * 
void adj_table_no_net(LGraph *tg);    //�������ڽӱ� 
void have_w_net(Mgraph *g);   //����������     *
void  adj_table_h_net(LGraph *tg);   //�������ڽӱ� 
int locate_adj_vex(LGraph *tg,char v);   //�ڽӱ�Ķ��㶨λ 
void DFS(LGraph *tg,int i);  //������ȱ��� 
void LBFS(LGraph *tg);  //������ȱ��� 
int visited[MAX_NUM ];   //��������
int Ladjvex(LGraph *tg,int k);   //λ�� 


void ShowMainMenu()   //�����潻�� 
{
	printf("\n");
	printf("  ***************ͼ�Ļ���������Ӧ��******************\n");
	printf("  *  1 ����ͼ�Ļ���������Ӧ��                      *\n");
	printf("  *  2 �������Ļ���������Ӧ��                      *\n");
    printf("  *  3 ����ͼ�Ļ���������Ӧ��                      *\n");
	printf("  *  4 �������Ļ���������Ӧ��                      *\n");
	printf("  *  5 �˳�                                        *\n");
	printf("  ***************************************************\n");
}

void UDG()    //����ͼ�������� 
{

	int i,n;
	do
	{
		printf("\n");
		printf("  ***************����ͼ�Ļ���������Ӧ��***************\n");
	     printf("  *  1 ��������ͼ���ڽӾ���                         *\n");
		printf("  *  2 ��������ͼ���ڽӱ�                           *\n");
	     printf("  *  3 ����ͼ��������ȱ���                         *\n");
	     printf("  *  4 ����ͼ�Ĺ�����ȱ���                         *\n");
		printf("  *  5 �˳�                                         *\n");
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
				printf("�ڽӱ��������ȱ���\n");
				for(i=0;i<tg.vexnum;i++)
				visited[i]=0;
				for(i=0;i<tg.vexnum;i++)
				   if(!visited[i])
				    DFS(&tg, i);
				break;
			case 4:
				
			    printf("�ڽӱ�Ĺ�����ȱ�����\n");
			    BFSTraverse(&tg);
				break;
			default:
				if (n!=5)
					printf("������������\n");
		}
	}while(n!=5);
}

void UDN()   // �������������溯�� 
{
	LGraph tree;
	int parent[MAX_NUM ];

	int n;
	do{
		printf("\n");
		printf("  ***************�������Ļ���������Ӧ��***************\n");
	     printf("  *  1 �������������ڽӾ���                         *\n");
		printf("  *  2 �������������ڽӱ�                           *\n"); 
	     printf("  *  3 prim�㷨����С������                         *\n");
		printf("  *  4 kraskal�㷨����С������                      *\n");
		printf("  *  5 �˳�                                         *\n");
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
				 printf("��С������Ϊ��\n");
				 Kruskal(&g); 
				break;
			default:
				if (n!=5)
					printf("������������\n");
		}
	}while(n!=5);
	
}

void DG()    //����ͼ�������� 
{

	int n,v,i;
	do
	{
		printf("\n");
		printf("  ***************����ͼ�Ļ���������Ӧ��***************\n");
	     printf("  *  1 ��������ͼ���ڽӾ���                         *\n");
		printf("  *  2 ��������ͼ���ڽӱ�                           *\n");
	     printf("  *  3 ��������                                     *\n");
		printf("  *  4 �˳�                                         *\n");
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
					printf("������������\n");
		}
	}while(n!=4);
}

void DN()      //�������������� 
{

	int n,i;
     Graph *vg;  
    int VertexNum, EdgeNum;  

	do{
		printf("\n");
		printf("  ***************�������Ļ���������Ӧ��***************\n");
	     printf("  *  1 �������������ڽӾ���                         *\n");
		printf("  *  2 �������������ڽӱ�                           *\n");
	     printf("  *  3 �ؼ�·��                                     *\n");
		printf("  *  4 ��Դ�������·������                         *\n");
		printf("  *  5 �˳�                                         *\n");
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
                printf("������Ҫ������AOE���Ķ������ͱ���:\n");  
                scanf("%d %d", &VertexNum, &EdgeNum); 
				getchar(); 
                CreateGraph( &vg , VertexNum, EdgeNum);  
                FindCPath( vg );  
				break;
			case 4:
				 
				 printf("�����뵥Դ�����:suchas(1-n)\n");
				 scanf("%d",&i);
				 getchar();
				 SetWeight(&g );
				 Dijkstra(&g,i); 
				break;
			case 5:
				break;
			default:
				if (n!=6)
					printf("������������\n");
		}
	}while(n!=6);
	
}

int main()     //��ں��� 
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
					printf("������������\n");
		}
	}while(n!=5);
}

/**********************����ʵ��*******************************/

 

void creat_mygraph1(Mgraph *g)      //����ͼ�ڽӾ��� 
{
	int i,j,k;
	char v1,v2;
	printf("����������ͼ�Ķ������ͻ�����:\n");
	scanf("%d %d",&g->vexnum,&g->arcnum);
	getchar();
	printf("��������ͼ�Ķ��������ַ���\n");
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
		printf("�������Ѵ��ڵ����������ַ���\n");
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
int locatevex(Mgraph *mg,char v)     //�ڽӾ���Ķ���λ��ȷ�� 
{
	int i;
	for(i=0;mg->vexs[i]!=v;i++)
	  if(i>mg->vexnum)
	     printf("ERROR");
	     return i;

}
void creat_hway_graph(Mgraph *g)    //����ͼ�ڽӾ��� 
{
	
	
	int i,j,k;
	char v1,v2;
	printf("����������ͼ�Ķ������ͻ�����:\n");
	scanf("%d %d",&g->vexnum,&g->arcnum);
	getchar();
	for(i=0;i<g->vexnum;i++)
	{
		printf("��������ͼ�Ķ��������ַ���\n");
		scanf("%c",&g->vexs[i]);
		getchar();
		
	}
	for(j=0;j<g->vexnum;j++)
		for(j=0;j<g->vexnum;j++)
			g->arcs[i][j]=0;
	for(k=0;k<g->arcnum;k++)
	{
		printf("�������Ѵ��ڵ����������ַ���\n");
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
void creat_nonet(Mgraph *g)        //���������ڽӾ��� 
{
		int i,j,k;
	char v1,v2;
	printf("�������������Ķ������ͻ�����:\n");
	scanf("%d %d",&g->vexnum,&g->arcnum);
	getchar();
	for(i=0;i<g->vexnum;i++)
	{
		printf("�����������Ķ��������ַ���\n");
		scanf("%c",&g->vexs[i]);
		getchar();
		
	}
	for(i=0;i<g->vexnum;i++)
		for(j=0;j<g->vexnum;j++)
			g->arcs[i][j]=0;            //��ʼ�������ֵΪ0 
	for(k=0;k<g->arcnum;k++)
	{   
		printf("�������Ѵ��ڵ����������ַ���\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		i=locatevex(g,v1);
		j=locatevex(g,v2);
		printf("��������������Ӧ��Ȩֵ��\n");
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


void have_w_net(Mgraph *g)     //���������ڽӾ��� 
{
	int i,j,k;
	char v1,v2;
	printf("�������������Ķ������ͻ�����:\n");
	scanf("%d %d",&g->vexnum,&g->arcnum);
	getchar();
	for(i=0;i<g->vexnum;i++)
	{
		printf("�����������Ķ��������ַ���\n");
		scanf("%c",&g->vexs[i]);
		getchar();
		
	}
	for(j=0;j<g->vexnum;j++)
		for(j=0;j<g->vexnum;j++)
			g->arcs[i][j]=0;
	for(k=0;k<g->arcnum;k++)
	{
		printf("�������Ѵ��ڵ����������ַ���\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		i=locatevex(g,v1);
		j=locatevex(g,v2);
		printf("����������������ַ�����Ȩֵ��\n");
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
void adj_table_hway(LGraph *tg)    //����ͼ���ڽӱ� 
{
		int i,j,k;
	char v1,v2;
	arcnode *p;
	printf("�������ڽӱ�洢����ͼ�Ķ������ͻ�����(ע��vex<=20,arc<=40:\n");
	scanf("%d %d",&tg->vexnum,&tg->arcnum);
	getchar();
		for(i=0;i<tg->vexnum;i++)
	{
		printf("��������ͼ�Ķ��������ַ���\n");
		scanf("%c",&tg->vertices[i].data);
		getchar();
		tg->vertices[i].firstarc=NULL;
	}
	for(k=0;k<tg->arcnum;k++)
	{
	
		
		printf("����������ͼ�������������㣺\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		p=(arcnode*)malloc(sizeof(arcnode));
		if(!p) printf("����ʧ�ܣ�");
		i=locate_adj_vex(tg,v1);
		j=locate_adj_vex(tg,v2); 
		p->adjvex=j;
		p->arcnext=tg->vertices[j].firstarc;
		tg->vertices[j].firstarc=p;
	
		}

}
int locate_adj_vex(LGraph *tg,char v)   //Ѱ��v����ͼ��λ�� 
{
	int i;
	for(i=0;tg->vertices[i].data!=v;i++)
	if(i>tg->vexnum)
	printf("Ѱ��ʧ�ܣ�");
	return i;
		
}
void adj_table_noway(LGraph *tg)       //����ͼ ���ڽӱ�
{
	
	int i,j,k;
	char v1,v2;
	arcnode *p,*q;
	printf("�������ڽӱ�洢����ͼ�Ķ������ͻ�����(ע��vex<=20,arc<=40:\n");
	scanf("%d %d",&tg->vexnum,&tg->arcnum);
	getchar();
		for(i=0;i<tg->vexnum;i++)   
	{
		printf("��������ͼ�Ķ��������ַ���\n");
		scanf("%c",&tg->vertices[i].data);
		getchar();
		tg->vertices[i].firstarc=NULL;
	}
	for(k=0;k<tg->arcnum;k++)
	{
	
		if(!p) printf("����ʧ�ܣ�");
		printf("����������ͼ�������������㣺\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		p=(arcnode*)malloc(sizeof(arcnode));
		if(!p) printf("����ʧ�ܣ�");
		i=locate_adj_vex(tg,v1);
		j=locate_adj_vex(tg,v2); 
		p->adjvex=i;
		p->arcnext=tg->vertices[j].firstarc;
		tg->vertices[j].firstarc=p;   //ͷ�巨����߽�� 
		q=(arcnode*)malloc(sizeof(arcnode));   //����ͼ�����������һ���߽�� 
		if(!q) printf("����ʧ�ܣ�");
		q->adjvex=j;
		q->arcnext=tg->vertices[i].firstarc;
		tg->vertices[i].firstarc=q; 	
		}
	
	
}
void  adj_table_h_net(LGraph *tg)    //������ ���ڽӱ�
{
	int i,j,k;
	char v1,v2;
	arcnode *p,*q;
	printf("�������ڽӱ�洢�������Ķ������ͻ�����(ע��vex<=20,arc<=40:\n");
	scanf("%d %d",&tg->vexnum,&tg->arcnum);
	getchar();
		for(i=0;i<tg->vexnum;i++)
	{
		printf("�����������Ķ��������ַ���\n");
		scanf("%c",&tg->vertices[i].data);
		getchar();
		tg->vertices[i].firstarc=NULL;
	}
	for(k=0;k<tg->arcnum;k++)
	{
	
		if(!p) printf("����ʧ�ܣ�");
		printf("�������������������������㣺\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		p=(arcnode*)malloc(sizeof(arcnode));
		if(!p) printf("����ʧ�ܣ�");
		i=locate_adj_vex(tg,v1);
		j=locate_adj_vex(tg,v2); 
		p->adjvex=j;
		p->arcnext=tg->vertices[j].firstarc;
		tg->vertices[i].firstarc=p;
	    printf("�������������Ȩֵ��\n");
		scanf("%d",&p->info);
		getchar();
	    
		}
} 
void adj_table_no_net(LGraph *tg)    //���������ڽӱ� 
{
    
	int i,j,k;
	char v1,v2;
	arcnode *p,*q;
	printf("�������ڽӱ�洢�������Ķ������ͻ�����(ע��vex<=20,arc<=40:\n");
	scanf("%d %d",&tg->vexnum,&tg->arcnum);
	getchar();
		for(i=0;i<tg->vexnum;i++)
	{
		printf("�����������Ķ��������ַ���\n");
		scanf("%c",&tg->vertices[i].data);
		getchar();
		tg->vertices[i].firstarc=NULL;
	}
	for(k=0;k<tg->arcnum;k++)
	{
	
	
		printf("�������������������������㣺\n");
		scanf("%c %c",&v1,&v2);
		getchar();
		p=(arcnode*)malloc(sizeof(arcnode));
		if(!p) printf("����ʧ�ܣ�");
		i=locate_adj_vex(tg,v1);
		j=locate_adj_vex(tg,v2); 
		p->adjvex=i;    
		p->arcnext=tg->vertices[j].firstarc;
		tg->vertices[j].firstarc=p;
		q=(arcnode*)malloc(sizeof(arcnode));
		if(!q) printf("����ʧ�ܣ�");
		q->adjvex=j;
		q->arcnext=tg->vertices[i].firstarc;
		tg->vertices[i].firstarc=q; 
		printf("�������������Ȩֵ��");
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
int Ladjvex(LGraph *tg,int k)    //�����±�k���ڽӵ� 
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
 * ��β����Ԫ��
 */
void EnQueue(Queue &Q,int e){
    if(!QueueFull(Q)){
        Q->data[Q->rear] = e;
        Q->rear = (Q->rear+1)%MAX_NUM;
    }
}

/**
 * ��ͷɾ��Ԫ��
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
void BFSTraverse(LGraph *tg)    //������ȱ���
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

//��������   
void TopologicalSort(Mgraph *g)   
{   
   int i,j,k=0,m;   
    char vertex[MAX_VERTEX_NUM];   
 
 while(k<g->vexnum){   
     //1.��û����ȵĶ���,��������vertex��   
       for(i=0;i<g->vexnum;i++){   
           for(j=0;j<g->vexnum;j++){   
                if(g->arcs[j][i]!=0)   //�����Ķ��㵽i���� 
                    break;   
            }   
            if(j==g->vexnum){   
               //���g->vertex[i]�Ƿ��Ѿ�����   
                for(m=0;m<k;m++)   
                   if(vertex[m]==g->vexs[i])   
                        break;   
                if(m==k){   
                    vertex[k++]=g->vexs[i];   
                   break;   
               }            
			    }          
				 }   
       //2.û�����Ϊ0�Ķ���   
      if(i==g->vexnum){   
           printf("���ڻ�·!\n");   
            return ;   
     }   
    //3.ɾ���������ĳ���   
    for(j=0;j<g->vexnum;j++)   
            g->arcs[i][j]=0;   
    }   
   //��������Ľ��   
    printf("������������\n");   
    for(i=0;i<k;i++)   
    printf("%-3c",vertex[i]);   
   printf("\n");   
}
//�����ڽӵĶ���֮���Ȩֵ����ΪMAX  
void SetWeight( Mgraph *g )  
{  
    for( int i=0; i<g->vexnum; i++ )  
        for( int j=0; j<g->vexnum; j++ )  
            if( 0 == g->arcs[i][j] )  
                g->arcs[i][j] = MAX;  
}
//����prim�㷨����С������  
void prim( Mgraph *g,  int *parent )  
{  
    int i, j, k;  
    int lowcost[MAX_NUM];  
    int closest[MAX_NUM], used[MAX_NUM];  
    int min;  
  
    for( i=0; i<g->vexnum; i++ ) {          //�Ը�������lowcost��closest���г�ʼ��  
        lowcost[i] = g->arcs[0][i];  
        closest[i] = 0;  
        used[i] = 0;                    //used[i] == 0 ��ʾi������U�У���֮����V-U�С�  
        parent[i] = -1;  
    }  
  
    used[0] = 1;                        //��һ�������Ϊ0�Ķ������U�У�Ҳ��������������  
  
    for( i=0; i<g->vexnum-1; i++ ) {  
        j = 0;  
        min = MAX;  
  
        for( k=1; k<g->vexnum; k++ )        //�ҵ�V-U�е���U�ж�����ɵ���СȨֵ�ıߵĶ�����  
            if( (0==used[k]) && (lowcost[k]<min) ) {  
                min = lowcost[k];  
                j = k;  
            }  
  
        parent[j] = closest[j];  
  
        used[j] = 1;                    //��j�������U��  
  
        for( k=0; k<g->vexnum; k++ )        //����j�������U�У�����lowcost��closest�����е�Ԫ�أ����V-U�еĶ��㵽j�����Ȩֵ�Ƿ��j����U֮ǰ��lowcost�����Ԫ��С  
            if( (0==used[k]) && (g->arcs[k][j]<lowcost[k]) ) {  
                lowcost[k] = g->arcs[k][j];  
                closest[k] = j;         //closest���鱣�����U�е�V-U����СȨֵ�Ķ�����  
            }  
    }  
} 
//��ӡ��С�������ıߺ�MST��Ȩֵ  
void PrintMST( Mgraph *g, int *parent )  
{  
    int weight = 0;  
    printf("MST�ı�Ϊ:\n");  
    for( int i=1; i<g->vexnum; i++ ) {       //VerNum-1����  
        printf("%c--%c\n", g->vexs[parent[i]], g->vexs[i] );  
        weight+=g->arcs[parent[i]][i];      //Ȩֵ֮�� 
    }  
    printf("MST��ȨֵΪ:%d\n", weight);  
}        
void Ppath(int path[],int i,int v)  //ǰ��ݹ����·���ϵĶ���  
{  
    int k;  
    k=path[i];  
    if (k==v)  return;          //�ҵ�������򷵻�  
    Ppath(path,k,v);            //�Ҷ���k��ǰһ������  
    printf("%d,",k);            //�������k  
}  
void Dispath(int dist[],int path[],int s[],int n,int v)  
{  
    int i;  
    for (i=0; i<n; i++)  
        if (s[i]==1)  
        {  
            printf("  ��%d��%d�����·������Ϊ:%d\t·��Ϊ:",v,i,dist[i]);  
            printf("%d,",v);    //���·���ϵ����  
            Ppath(path,i,v);    //���·���ϵ��м��  
            printf("%d\n",i);   //���·���ϵ��յ�  
        }  
        else  printf("��%d��%d������·��\n",v,i);  
}  
void Dijkstra(Mgraph *g,int v) 
{  
    int dist[MAX_NUM],path[MAX_NUM];  
    int s[MAX_NUM];  
    int mindis,i,j,u;  
    for (i=0; i<g->vexnum; i++)  
    {  
        dist[i]=g->arcs[v][i];      //�����ʼ��  
        s[i]=0;                    //s[]�ÿ�  
        if (g->arcs[v][i]<MAX)      //·����ʼ��  
            path[i]=v;  
        else  
            path[i]=-1;  
    }  
    s[v]=1;   //��־λ 
    path[v]=0;              //Դ����v����s��  
    for (i=0; i<g->vexnum; i++)               //ѭ��ֱ�����ж�������·�������  
    {  
        mindis=MAX;                 //mindis����С���ȳ�ֵ  
        for (j=0; j<g->vexnum; j++)       //ѡȡ����s���Ҿ�����С����Ķ���u  
            if (s[j]==0 && dist[j]<mindis)  
            {  
                u=j;  
                mindis=dist[j];  
            }  
        s[u]=1;                     //����u����s��  
        for (j=0; j<g->vexnum; j++)       //�޸Ĳ���s�еĶ���ľ���  
            if (s[j]==0)  
                if (g->arcs[u][j]<MAX && dist[u]+g->arcs[u][j]<dist[j])  
                {  
                    dist[j]=dist[u]+g->arcs[u][j];  
                    path[j]=u;  
                }  
    }  
    Dispath(dist,path,s,g->vexnum,v);     //������·��  
}
void InsertSort(edge E[],int n) //��E[0..n-1]�������������ֱ�Ӳ�������  
{  
    int i,j;  
    edge temp;  
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
  
void Kruskal(Mgraph *g)  
{  
    int i,j,u1,v1,sn1,sn2,k;  
    int vset[MAX_NUM];  
    edge E[MaxSize];    //������б�  
    k=0;                //E������±��0��ʼ��  
    for (i=0; i<g->vexnum; i++)   //��g�����ı߼�E  
        for (j=0; j<g->vexnum; j++)  
            if (g->arcs[i][j]!=0 && g->arcs[i][j]!=MAX)  
            {  
                E[k].u=i;  
                E[k].v=j;  
                E[k].w=g->arcs[i][j];  
                k++;  
            }  
    InsertSort(E,g->arcnum);      //����ֱ�Ӳ��������E���鰴Ȩֵ��������  
    for (i=0; i<g->vexnum; i++)   //��ʼ����������  
        vset[i]=i;  
    k=1;    //k��ʾ��ǰ�����������ĵڼ�����,��ֵΪ1  
    j=0;    //E�бߵ��±�,��ֵΪ0  
    while (k<g->vexnum)       //���ɵı���С��nʱѭ��  
    {  
        u1=E[j].u;  
        v1=E[j].v;      //ȡһ���ߵ�ͷβ����  
        sn1=vset[u1];  
        sn2=vset[v1];   //�ֱ�õ��������������ļ��ϱ��  
        if (sn1!=sn2)   //���������ڲ�ͬ�ļ���  
        {  
            printf("  (%d,%d):%d\n",u1,v1,E[j].w);  
            k++;                     //���ɱ�����1  
            for (i=0; i<g->vexnum; i++)   //��������ͳһ���  
                if (vset[i]==sn2)   //���ϱ��Ϊsn2�ĸ�Ϊsn1  
                    vset[i]=sn1;  
        }  
        j++;               //ɨ����һ����  
    }  
} 
//����AOE��  
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
  
    printf("������AOE���Ķ���:\n");  
    for( i=1; i<=VertexNum; i++ )            //�洢����  
        scanf("%d", &(*g)->ver[i]);  
  
    for( i=1; i<=VertexNum; i++ )            //�������������ʼ��Ϊ0  
        (*g)->In[i] = 0;  
  
    printf("������AOE���ıߵ�ͷ��β��Ȩֵ:\n");  
    for( i=1; i<=EdgeNum; i++ ) {  
        printf("a%d: ", i);  
        scanf("%d %d %d", &((*g)->Edge[i].begin) , &((*g)->Edge[i].end) , &((*g)->Edge[i].weight) );  
        j = (*g)->Edge[i].end;  
        (*g)->In[j]++;  
    }  
}  
  
//�ؼ�·�����Һ���  
void FindCPath( Graph *g )  
{  
    int VertexNum = g->VertexNum ;  
    int EdgeNum = g->EdgeNum ;  
    int end;  
    int TopIndex;  
    int *Top = (int *)malloc(sizeof(int)*(VertexNum+1));    //Top���������洢AOE�����������еı��  
    int *ve = (int *)malloc(sizeof(int)*(VertexNum+1));     //ve[i]��ʾ�¼�Vi�����翪ʼʱ��      
    int *vl = (int *)malloc(sizeof(int)*(VertexNum+1));     //vl[i]��ʾ�¼�Vi����ٿ�ʼʱ��  
    int *e = (int *)malloc(sizeof(int)*(VertexNum+1));      //e[i]��ʾ�ai�����翪ʼʱ��  
    int *l = (int *)malloc(sizeof(int)*(VertexNum+1));      //l[i]��ʾ�ai����ٿ�ʼʱ��  
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
  
    //��ve[i]  
    for( i=1; i<=VertexNum; i++ )    //ve�����ʼ��  
        ve[i] = 0;  
    for( i=1; i<=VertexNum; i++ ) {  
        TopIndex = Top[i];  
        for( j=1; j<=EdgeNum; j++ )  
            if( (g->ver[TopIndex] == g->Edge[j].begin) && (ve[g->Edge[j].end] < ve[TopIndex] + g->Edge[j].weight) )  
                ve[g->Edge[j].end] = ve[TopIndex] + g->Edge[j].weight;  
    }  
  
    //��vl[i]  
    for( i=1; i<=VertexNum; i++ )  
        vl[i] = ve[VertexNum];  
    for( i=VertexNum; i>=1; i-- ) {  
        TopIndex = Top[i];          //��������������vl  
        for( j=1; j<=EdgeNum; j++ )  
            if( (g->Edge[j].end == g->ver[TopIndex]) && (vl[g->Edge[j].begin] > vl[TopIndex] - g->Edge[j].weight) )  
                vl[g->Edge[j].begin] = vl[TopIndex] - g->Edge[j].weight;  
    }  
  
    //��e[i]  
    for( i=1; i<=EdgeNum; i++ )  
        e[i] = ve[g->Edge[i].begin];  
  
    //��l[i]  
    for( i=1; i<=EdgeNum; i++ )  
        l[i] = vl[g->Edge[i].end] - g->Edge[i].weight;  
  
    printf("��AOE���Ĺؼ��Ϊ:\n");  
    for( i=1; i<=EdgeNum; i++ )  
        if( e[i] == l[i] )  
            printf("a%d ", i);  
        printf("\n");  
}     
  

