/**************************���,������ȱ�������ʵ��**************************/ 
#include"structnode.h"
void DFS(LGraph *tg,int i)   //������ȱ��� 
{
	int k;
	visited[i]=OK;
	printf("%c",tg->vertices[i].data);
	for(k=Ladjvex(tg,i);k>=0;k=Ladjvex(tg,k))
		if(!visited[k])
			DFS(tg,k);
		printf("�ڽӱ��������ȱ���\n");
		for(i=0;i<tg->vexnum;i++)
			visited[i]=0;
				for(i=0;i<tg->vexnum;i++)
				   if(!visited[i])
				    DFS(tg, i);
	
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
