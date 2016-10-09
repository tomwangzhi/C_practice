#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define LIST_INIT_SIZE 10  /*初始化线性表的分配量*/ 
#define LIST_ADD 5   /*增加的分配量 */ 
#define OVERFLOW 0
#define ERROP -1
typedef int Status;
typedef int ElemType;
typedef struct{
	
	ElemType *elem;
	Status length;
	int listsize;
}sql;


/*********函数声明**********/ 


  int  InitList(sql &list);  /*构造一个线性表的函数声明*/
  int    DestroyList(sql &list); 
    int ListInsert(sql &list,int i,int &e);
    int ListDelete(sql &list,int i, int &e);
  
  
  
 /*********入口函数main*************/ 
int main()
{ 
	int a,b,e,d,f;
	sql list1;	
	a=InitList(list1);
	printf("返回的值是：%d\n",a);  //检验构造线性表是否成功 
	printf("存储容量是：%d\n",list1.listsize);
    b=DestroyList(list1);
	printf("销毁线性表后返回的值是：%d",b);
    
   
	return 0;
}

/************函数实现************/ 
		
		
int InitList(sql &list)  /*构造一个空的线性表*/ 
{
	list.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!list.elem) return OVERFLOW;
	else
	{
		list.length=0;    //空表长度为0 
		list.listsize=LIST_INIT_SIZE;  //初始存储容量 
		return OK;
		}
	
}


int DestroyList(sql &list) /*销毁线性表*/ 
{    
	if(!list.elem)return ERROP;
	 free(list.elem);
	 return OK;
	
}





  int ListInsert(sql &list,int i,int &e)  /*在线性表list中的第i个位置插入e */
  {        int *q=&(list.elem[i-1]);
           ElemType *newbase,*p;
           
			if(i<1 || i>list.length)return OVERFLOW;
		  if(list.length>=list.listsize)
		   {newbase=(ElemType*)malloc(LIST_ADD*sizeof(ElemType));
		   if(!newbase)return OVERFLOW;
		   list.elem=newbase;
		   list.listsize+=LIST_ADD+list.listsize;
		   }
		   for(p=&(list.elem[list.length-1]);p>=q;--p)
		   *(p+1)=*p;  /*插入位置及之后的元素右移*/ 
		   *q=e;
		      ++list.length;
		      return OK;
		   
		
		}

   int ListDelete(sql &list,int i,int&e)  /*删除第i个位置的元素*/ 
   {     int *p,*q;
		if(i<1 || i>list.length)return ERROP;
		p=&(list.elem[i-1]);
		e=*p;
		q=list.elem+list.length-1;
		for(++p;p<=q;++p)
		*(p-1)=*p;
		--list.length;
		return OK; 
		}

 
