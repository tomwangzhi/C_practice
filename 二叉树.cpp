#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define NULL 0

typedef struct BitNode{
	char node;
	struct BitNode *lchild,*rchild;
	
}Bit,*Bitree;
Bitree Creat(Bitree T);
void Preorder(Bitree T);
void Inorder(Bitree T);
void Postorder(Bitree T);
int main()
{   
	 int choice;
	 Bitree T=NULL;
	 
	 while(1)
	 {
			printf("ѡ�\n");
			printf("******************************************************\n");
			printf("1-����������\n");
			printf("2-�������������\n");
			printf("3-�������������\n");
			printf("4-�������������\n");
			printf("0-�˳�\n");
			printf("******************************************************\n");
			printf("��ѡ��");
			scanf("%d",&choice);
			switch(choice){
		    case 1:
				{
					printf("�����룺\n");
					getchar();
					T=Creat(T);
					printf("�����ɹ�\n");
					break;
					}
			case 2:
				{
				printf("�������������Ϊ��\n");
					Preorder(T);
					break; 
					}
		    case 3:
				{
					printf("�������������\n");
					Inorder(T);
						break;
					}
			case 4:
				{
					printf("�������������\n");
					Postorder(T);
						break;
					}				
					
			case 0:
				{
					break;
					}		
							
				
			}
			if(choice==0);
			break;	
	}
	
	
	 return 0;
}


Bitree Creat(Bitree T)   //���������� 
{   char ch;
    //printf("�������ַ���\n");
    scanf("%c",&ch);
      if(ch==' ')
       exit(1);
       else{
	       T=(Bitree)malloc(sizeof(Bit));
	        if(!T) printf("����ʧ�ܣ�");
	            T->node=ch;
	            T->lchild=Creat(T->lchild);
	            T->rchild=Creat(T->rchild);
	            
			}
			
			return T;
} 


void Preorder(Bitree T)          //������������� 
{if(T!=NULL)
 {
		printf("%c",T->node);
		Preorder(T->lchild);
	     Preorder(T->rchild);
		}
	
}
void Inorder(Bitree T)    //������������� 
{
	if(T!=NULL)
 {
		Inorder(T->lchild);
		printf("%c",T->node);
	    Inorder(T->rchild);
		}
}
void Postorder(Bitree T)   //������������� 
{
	
	if(T!=NULL)
 {
		Postorder(T->lchild);
	    Postorder(T->rchild);
	    printf("%c",T->node);
		}
}
