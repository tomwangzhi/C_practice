/***********************************�ڽӾ��������ͼ������ͼ��������������������ʵ��***************/ 
#include"structnode.h"
void creat_mygraph1(Mgraph *g)      //����ͼ�ڽӾ��� 
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
			
		for(i=0;i<g->vexnum;i++)
		 {
			for(j=0;j<g->vexnum;j++)
		    printf("%d\t",g->arcs[i][j]);
		    printf("\n");
		}
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



/*****************************************/
