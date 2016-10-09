#include<stdio.h>
#include<stdlib.h>
struct node 
{
	int num;
	struct node * next;
};

int main()
{
	
	struct node * head,* p,* q;
	int a;
	head=(struct node *)malloc(sizeof(struct node ));
	p=q=head;
	scanf("%d",&a);
	while (a!=0)
	{
		p=(struct node * )malloc(sizeof(struct node ));
		p->num=a;
		q->next=p;
		q=p;
		scanf("%d",&a);
	}
	p->next=NULL;
	
	p=head->next;
	while (p!=NULL)
	{
		printf("->%d",p->num);
		p=p->next;
	}
	printf("\n");
	
}

