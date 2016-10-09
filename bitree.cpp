#include<stdi.h>
#define MAX_NODE_NUM  100

Bitree  Initbtree(Bitree &T);
typedef struct Bitnode{
	int data;
	struct Bitnode *lchild,rchild;
}Bitnode,*Bitree;


{
	int main(void)
	int a,b;
	printf("please input the type digitals:");
	scanf("%d",&a);
	switch(a)
      {
		case 0:
			return;
		case 1:
			Initbtree();
		case 2:
			Find_data_x();
		case 3:
			{ 
				printf("please select a or b to choose scan:");
				scanf("%c",&b);
				
			  	
				}
		case 4:
			Solve_root();
		case 5:
			Print_bitree();
		case 6:
			Caculate_leaf();
		case 7:	
			Caculate_leafnum();
		case 8:
			Caculat_tree_depth();
			
			}
	
	
	
} 

  Bitree  Initbtree(Bitree &T)
  {
		T=(Bitree)=malloc(sizeof(Bitnode));
		if(!T)
		{
		  gInitbtree(T->lchild);
	    }
		
		return T;
   }
   Find_data_x()
   {
	    	
		
		}
		
		
