#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define OVERFLOW -1
#define STACKSIZE 20        /*给栈分配的初始量*/ 
#define STACK_ADD_SIZE 10   /*栈不够时可以添加大小*/ 
#define EEROP -2

typedef int  DataType; 
typedef struct {                      /*构造一个栈的结构体*/ 
	int stacksize;                   /*栈的大小*/ 
    DataType  *top;                  /*栈的顶指针*/ 
	  DataType  *base;               /*栈的底指针*/ 
	  
}Stack;


/**************函数的声明********************/     

DataType InitStack(Stack &L);     /*构造一个空栈L*/
int DestoryStack(Stack &L);  /*销毁栈L*/
int	 ClearStack(Stack &L);    /*清空栈L*/
   bool StackEmpty(Stack &L);    //判断是否栈空
  int  StackLength(Stack &L);        //返回栈L的长度
    int   GetTop(Stack &L,DataType &e);   //获得栈顶元素，并用e返回
	int	 Push(Stack &L,DataType &e);      //插入元素e为栈顶元素
	int	 Pop(Stack &L,DataType &e);           //若栈不空则删除栈顶元素，并用e返回，并返回OK,否则返回EEROP





int main()
{   Stack S;
    int a,d,e;  bool c; 
	InitStack(S);     //在主函数调用构造一个空栈的函数 
   a=StackLength(S);
   printf("分配的栈的长度是：%d\n",a);    
    c=StackEmpty(S);
	 printf("构造的栈的是否为空：%d\n",c);   //打印为空表示栈为空
   d=DestoryStack(S);
   printf("销毁栈之后返回的值：%d",d);	   //返回1表示栈被销毁 
   printf("请输入要插入的栈元素：\n");
   scanf("%d",&e);
   Push(S,e);
   printf("输入的栈的元素为:%d",*S.top);
   
}
		 
		  



/*********************函数实现*******************************/ 



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
		L.base=(DataType *)realloc(L.base,(L.stacksize+STACK_ADD_SIZE)*sizeof(DataType));     //调用realloc函数添加内存块 
		if(!L.base) return OVERFLOW;   //存储分配失败 
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



 
