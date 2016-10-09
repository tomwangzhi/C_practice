/******************************队列函数实现***************************/ 
#include"structnode.h"


int QueueEmpty(Queue Q){
    if(Q->front == Q->rear){
        return 1;
    }else{
        return 0;
    }
}

int QueueFull(Queue Q){
    if((Q->rear+1)%MAX_NUM == Q->front){
        return 1;
    }else{
        return 0;
    }
}

/**
 * 队尾插入元素
 */
void EnQueue(Queue Q,int e){
    if(!QueueFull(Q)){
        Q->data[Q->rear] = e;
        Q->rear = (Q->rear+1)%MAX_NUM;
    }
}

/**
 * 队头删除元素
 */
void DeQueue(Queue Q,int *e){
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
