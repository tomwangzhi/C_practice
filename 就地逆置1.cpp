#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct LNode{
	int length;
	int data;
	struct LNode *next;
}LNode,*LinkList;
LinkList CreatLinkList(LinkList head,int num);
LinkList  daozhiLinklist(LinkList &L);
 void prilinklist(LinkList &L);
 void insertelem(LinkList &L,int n,int elem);
int main()
{
	LinkList L,s,head;
	head=CreatLinkList(L,5);
	insertelem(head,3,8);
	prilinklist(head);
	//s=daozhiLinklist(head);
	//prilinklist(s);
}

LinkList CreatLinkList(LinkList head,int num)
{
	LinkList s;
	int i;
	head=(LinkList)malloc(sizeof(LNode));
	head->next=NULL;
	for(i=0;i<num;i++)
	{
		s=(LinkList)malloc(sizeof(LNode));
		s->next=head->next;
		head->next=s;
		printf("请向链表输入数：");
		scanf("%d",&s->data);
		}
		head->length=num;
		
		return  head;
}

 LinkList daozhiLinklist(LinkList &L)
{
	LinkList p,q;
	p=L;  q=NULL;
	if(p)
	{
		L=L->next;
		p->next=q;
		q=p;
		p=L;
		}
		L=p;
		return L;
}

void prilinklist(LinkList &L)
{
	LinkList p;
	p=L->next;
	while(p)
	{
	 printf("%d\n",&p->data);
		p=p->next;
		}
	
}

void insertelem(LinkList &L,int n,int elem)
{
	LinkList p,q;
	p=L;

	for(int i=0;i<n;i++)
	{
		p=p->next;
		
		}
	q=(LinkList)malloc(sizeof(LNode));
	q->data=elem;
	 q->next=p->next;
	 p->next=q;
	
}






