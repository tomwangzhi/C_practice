/******************************�궨��*******************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define MAX_NUM  20     //ͼ�Ķ�������� 
#define  OK 1
#define ERROR  0
#define  MAX_VERTEX_NUM  20   //��󶥵���� 


/****************************����ͼ��һЩ��ض���ͱߣ��������ṹ*************************/

/***************����ͼ���ڽӾ���ṹ***********************/ 

typedef struct {        
	
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
typedef struct Queue{
	int arry[MAX_NUM ];
	int front,rear;
}Queue;
Queue Q;

/***************************����******************/

 

//typedef struct MGraph{
	
//}MG,*MGraph;

/******************��������*********************************/
void InitQueue();//��ʼ������
int QueueIsEmpty(Queue *Q);  //�ж϶����Ƿ�Ϊ�� 
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
void LBFS(LGraph *tg,int i);  //������ȱ��� 
int visited[MAX_NUM ];   //��������
int Ladjvex(LGraph *tg,int k);   //λ�� 
void  bianli(Mgraph *g);
typedef  int  vextype;
typedef vextype mgraph[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
mgraph G1;
Mgraph g,g1;   //����һ���ڽӾ����ͼ 
LGraph tg;   // �����ڽӱ� 
int n,e;      //����ȫ�ֱ��� 
void creat_mygrap(mgraph G);
void out_mygraph(mgraph G);
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

	int i,v,n;
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
				adj_table_noway(&tg);
				printf("�ڽӱ��������ȱ���\n");
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
					printf("������������\n");
		}
	}while(n!=5);
}

void UDN()   // �������������溯�� 
{

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
			
				
			case 3:
				break;
			case 4:
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
                printf("����������ĵ�һ������\n");
                scanf("%c",&v);
                i=locate_adj_vex(&tg,v);
                 DFS(&tg,i);
				break;
			case 3:
				break;
			default:
				if (n!=4)
					printf("������������\n");
		}
	}while(n!=4);
}

void DN()      //�������������� 
{

	int n;
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
				break;
			case 3:
				break;
			case 4:
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

 void creat_mygrap(mgraph G)    //�����ڽӾ��� 
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
void out_mygraph(mgraph G)     //����ڽӾ��� 
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
void creat_mygraph1(Mgraph *g)      //����ͼ 
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
void creat_hway_graph(Mgraph *g)    //����ͼ 
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
		scanf("%c",&(g->vexs[i]));
		getchar();
		
	}
	for(j=0;j<g->vexnum;j++)
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
		scanf("%d",&(g->arcs[i][j]));
		getchar(); 
			
	}

} 
void bianli(Mgraph *g)
{int i,j;
	for(i=0;i<g->vexnum;i++)
	{   for(j=0;j<g->vexnum;j++)
		printf("�����Ԫ�����Ϊ��%d",g->arcs[i][j]);
		
		}
}

void have_w_net(Mgraph *g)     //������ 
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
		g->arcs[i][j]=1;
		 
		 
		}
	
}
void adj_table_hway(LGraph *tg)
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
int locate_adj_vex(LGraph *tg,char v)
{
	int i;
	for(i=0;tg->vertices[i].data!=v;i++)
	if(i>tg->vexnum)
	printf("Ѱ��ʧ�ܣ�");
	return i;
		
}
void adj_table_noway(LGraph *tg)
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
		tg->vertices[j].firstarc=p;
		q=(arcnode*)malloc(sizeof(arcnode));
		if(!q) printf("����ʧ�ܣ�");
		q->adjvex=j;
		q->arcnext=tg->vertices[i].firstarc;
		tg->vertices[i].firstarc=q; 	
		}
	
	
}
void  adj_table_h_net(LGraph *tg)    //������ 
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
		q=(arcnode*)malloc(sizeof(arcnode));
		if(!q) printf("����ʧ�ܣ�");
		q->adjvex=j;
		q->arcnext=tg->vertices[i].firstarc;
		tg->vertices[i].firstarc=q; 
	    
		}
} 
void adj_table_no_net(LGraph *tg)    //������ 
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
		tg->vertices[j].firstarc=p;
		q=(arcnode*)malloc(sizeof(arcnode));
		if(!q) printf("����ʧ�ܣ�");
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



