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
int locate_adj_vex(LGraph *tg,char v)
{
	int i;
	for(i=0;tg->vertices[i].data!=v;i++)
	if(i>tg->vexnum)
	printf("Ѱ��ʧ�ܣ�");
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
		scanf("%c",&(tg->vertices[i].data));
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

int main()
{int i;
	LGraph tg;   // �����ڽӱ� 
	adj_table_noway(&tg);
	for(i=0;i<tg.vexnum;i++)
	printf("%c\n",tg.vertices[i].data);
	 disp(&tg);
	return 0;
}
