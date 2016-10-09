#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define OVERFLOW -1
#define STACKSIZE 20        /*��ջ����ĳ�ʼ��*/ 
#define STACK_ADD_SIZE 10   /*ջ����ʱ������Ӵ�С*/ 
#define EEROP -2

typedef int  DataType; 
typedef struct {                      /*����һ��ջ�Ľṹ��*/ 
	int stacksize;                   /*ջ�Ĵ�С*/ 
    DataType  *top;                  /*ջ�Ķ�ָ��*/ 
	  DataType  *base;               /*ջ�ĵ�ָ��*/ 
	  
}Stack;


/**************����������********************/     

DataType InitStack(Stack &L);     /*����һ����ջL*/
int DestoryStack(Stack &L);  /*����ջL*/
int	 ClearStack(Stack &L);    /*���ջL*/
   bool StackEmpty(Stack &L);    //�ж��Ƿ�ջ��
  int  StackLength(Stack &L);        //����ջL�ĳ���
    int   GetTop(Stack &L,DataType &e);   //���ջ��Ԫ�أ�����e����
	int	 Push(Stack &L,DataType &e);      //����Ԫ��eΪջ��Ԫ��
	int	 Pop(Stack &L,DataType &e);           //��ջ������ɾ��ջ��Ԫ�أ�����e���أ�������OK,���򷵻�EEROP





int main()
{   Stack S;
    int a,d,e;  bool c; 
	InitStack(S);     //�����������ù���һ����ջ�ĺ��� 
   a=StackLength(S);
   printf("�����ջ�ĳ����ǣ�%d\n",a);    
    c=StackEmpty(S);
	 printf("�����ջ���Ƿ�Ϊ�գ�%d\n",c);   //��ӡΪ�ձ�ʾջΪ��
   d=DestoryStack(S);
   printf("����ջ֮�󷵻ص�ֵ��%d",d);	   //����1��ʾջ������ 
   printf("������Ҫ�����ջԪ�أ�\n");
   scanf("%d",&e);
   Push(S,e);
   printf("�����ջ��Ԫ��Ϊ:%d",*S.top);
   
}
		 
		  



/*********************����ʵ��*******************************/ 



DataType InitStack(Stack &L)      
{
	L.base=(DataType *)malloc(STACKSIZE*(sizeof(DataType)));
	if(!L.base) return OVERFLOW;
	L.top=L.base;
	L.stacksize=STACKSIZE;
	return OK; 
}


 int  ClearStack(Stack &L)
{   
	if(L.base==L.top) return OK;
	for(int i=1;i<=L.stacksize;i++)
	{   DataType *p;    
		L.top--;
		p=L.top;
		free(p);
		}
	 return OK;
} 
 
 
 bool  StackEmpty(Stack &L)
{
	if(L.base==L.top) return true;
	else return false;
}

 int  StackLength(Stack &L)
{
	return L.stacksize;
}
 
 int  GetTop(Stack &L,DataType &e)
{
	if(L.base==L.top)  return EEROP;
	e=*(L.top-1);
	return OK;
}


 int   Push(Stack &L,DataType &e)
{
	if(L.top-L.base>=L.stacksize)
	{
		L.base=(DataType *)realloc(L.base,(L.stacksize+STACK_ADD_SIZE)*sizeof(DataType));     //����realloc��������ڴ�� 
		if(!L.base) return OVERFLOW;   //�洢����ʧ�� 
		L.top=L.base+L.stacksize;
		L.stacksize+=STACK_ADD_SIZE;
		}
		
		*L.top++=e;
		return OK;
		
} 


int DestoryStack(Stack &L)
{
   free(L.base);
   return OK;
}



 
