/****************************��������ʵ��**************************/ 
#include"structnode.h"
int locatevex(Mgraph *mg,char v)     //�ڽӾ���Ķ���λ��ȷ�� 
{
	int i;
	for(i=0;mg->vexs[i]!=v;i++)
	  if(i>mg->vexnum)
	     printf("ERROR");
	     return i;

}
int locate_adj_vex(LGraph *tg,char v)   //Ѱ��v����ͼ��λ�� 
{
	int i;
	for(i=0;tg->vertices[i].data!=v;i++)
	if(i>tg->vexnum)
	printf("Ѱ��ʧ�ܣ�");
	return i;
		
}
int Ladjvex(LGraph *tg,int k)    //�����±�k���ڽӵ� 
{
   arcnode *p;
   for(p=tg->vertices[k].firstarc;p!=NULL;p=p->arcnext)
   	if(!visited[p->adjvex])
   	   return p->adjvex;
   	    return -1;
}
