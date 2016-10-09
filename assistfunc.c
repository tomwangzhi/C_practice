/****************************辅助函数实现**************************/ 
#include"structnode.h"
int locatevex(Mgraph *mg,char v)     //邻接矩阵的顶点位置确定 
{
	int i;
	for(i=0;mg->vexs[i]!=v;i++)
	  if(i>mg->vexnum)
	     printf("ERROR");
	     return i;

}
int locate_adj_vex(LGraph *tg,char v)   //寻找v所在图的位置 
{
	int i;
	for(i=0;tg->vertices[i].data!=v;i++)
	if(i>tg->vexnum)
	printf("寻找失败！");
	return i;
		
}
int Ladjvex(LGraph *tg,int k)    //返回下标k的邻接点 
{
   arcnode *p;
   for(p=tg->vertices[k].firstarc;p!=NULL;p=p->arcnext)
   	if(!visited[p->adjvex])
   	   return p->adjvex;
   	    return -1;
}
