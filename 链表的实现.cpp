#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROP -1
#define OVERFLOW 0
typedef  int  ElemType;
 
typedef struct Node{        /*����һ�����Ľṹ��*/ 
	
	struct Node *next;
	ElemType data;
	int length;
}Lnode,*Linklist;



/***************************��������****************/ 
void   CreatLinkList(Linklist &L,ElemType n);
 int GetElem(Linklist &L,ElemType n);
   int Destroylink(Linklist &L ,int i,int &e);


/******************���������***********************/

int main()
{   int elem;
	Linklist link,l;
    CreatLinkList(link, 5);
    elem=GetElem(link,3);
    printf("��õĵ���������%d\n",elem);

	
	return 0;
} 



void   CreatLinkList(Linklist &L,ElemType n)  /*��������*/ 
{   
	L=(Linklist)malloc(sizeof(Lnode));
	L->next=NULL;
	for(int i=n;i>0;--i)
	{    Linklist p;
		p=(Linklist)malloc(sizeof(Lnode));
        printf("�����������:\n");
		scanf("%d/n",&p->data);
		p->next=L->next;L->next=p;
		
		
		}
		L->length=n;
}

  int GetElem(Linklist &L,ElemType n)   /*�õ�����ĵ�n��Ԫ��*/ 
{    int e;
	Linklist m;
	if(!L)return ERROP;   /*�ж����������Ƿ�Ϊ��*/ 
	 m=L->next;          /*��ָ��ָ�������ͷָ��*/ 
	for(int i=0;i<=n;i++)
	{
		m=m->next;
		}
		e=m->data;
		return e;
}



  int Destroylink(Linklist &L ,int i,int &e)   /*��������*/ 
{   
	Linklist p,q;
	p=L; int j=0;
	while(p->next && j<i-1)
	p=p->next;++j;
	if(!p->next || j>i-1) return ERROP;
	q=p->next;p->next=q->next;free(q);
	e=p->data;
	return OK;
}
