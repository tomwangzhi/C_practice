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
			printf("选项：\n");
			printf("******************************************************\n");
			printf("1-构建二叉树\n");
			printf("2-先序遍历二叉树\n");
			printf("3-中序遍历二叉树\n");
			printf("4-后序遍历二叉树\n");
			printf("0-退出\n");
			printf("******************************************************\n");
			printf("请选择：");
			scanf("%d",&choice);
			switch(choice){
		    case 1:
				{
					printf("请输入：\n");
					getchar();
					T=Creat(T);
					printf("构建成功\n");
					break;
					}
			case 2:
				{
				printf("先序遍历二叉树为：\n");
					Preorder(T);
					break; 
					}
		    case 3:
				{
					printf("中序遍历二叉树\n");
					Inorder(T);
						break;
					}
			case 4:
				{
					printf("后序遍历二叉树\n");
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


Bitree Creat(Bitree T)   //二叉树构建 
{   char ch;
    //printf("请输入字符：\n");
    scanf("%c",&ch);
      if(ch==' ')
       exit(1);
       else{
	       T=(Bitree)malloc(sizeof(Bit));
	        if(!T) printf("分配失败！");
	            T->node=ch;
	            T->lchild=Creat(T->lchild);
	            T->rchild=Creat(T->rchild);
	            
			}
			
			return T;
} 


void Preorder(Bitree T)          //先序遍历二叉树 
{if(T!=NULL)
 {
		printf("%c",T->node);
		Preorder(T->lchild);
	     Preorder(T->rchild);
		}
	
}
void Inorder(Bitree T)    //中序遍历二叉树 
{
	if(T!=NULL)
 {
		Inorder(T->lchild);
		printf("%c",T->node);
	    Inorder(T->rchild);
		}
}
void Postorder(Bitree T)   //后序遍历二叉树 
{
	
	if(T!=NULL)
 {
		Postorder(T->lchild);
	    Postorder(T->rchild);
	    printf("%c",T->node);
		}
}
