#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROP -1
#define OVERFLOW 0
typedef  int  ElemType;
 
typedef struct Node{        /*声明一个结点的结构体*/ 
	
	struct Node *next;
	ElemType data;
	int length;
}Lnode,*Linklist;



/***************************函数声明****************/ 
void   CreatLinkList(Linklist &L,ElemType n);
 int GetElem(Linklist &L,ElemType n);
   int Destroylink(Linklist &L ,int i,int &e);


/******************主函数入口***********************/

int main()
{   int elem;
	Linklist link,l;
    CreatLinkList(link, 5);
    elem=GetElem(link,3);
    printf("获得的第三个数是%d\n",elem);

	
	return 0;
} 



void   CreatLinkList(Linklist &L,ElemType n)  /*创建链表*/ 
{   
	L=(Linklist)malloc(sizeof(Lnode));
	L->next=NULL;
	for(int i=n;i>0;--i)
	{    Linklist p;
		p=(Linklist)malloc(sizeof(Lnode));
        printf("请输入你的数:\n");
		scanf("%d/n",&p->data);
		p->next=L->next;L->next=p;
		
		
		}
		L->length=n;
}

  int GetElem(Linklist &L,ElemType n)   /*得到链表的第n个元素*/ 
{    int e;
	Linklist m;
	if(!L)return ERROP;   /*判断所给链表是否为空*/ 
	 m=L->next;          /*让指针指向链表的头指针*/ 
	for(int i=0;i<=n;i++)
	{
		m=m->next;
		}
		e=m->data;
		return e;
}



  int Destroylink(Linklist &L ,int i,int &e)   /*销毁链表*/ 
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
