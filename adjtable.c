/**********************************�ڽӱ�洢������ͼ������ͼ��������������������ʵ��***************/ 
#include"structnode.h"
#include<malloc.h>
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
