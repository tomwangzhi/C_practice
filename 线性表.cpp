#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define LIST_INIT_SIZE 10  /*��ʼ�����Ա�ķ�����*/ 
#define LIST_ADD 5   /*���ӵķ����� */ 
#define OVERFLOW 0
#define ERROP -1
typedef int Status;
typedef int ElemType;
typedef struct{
	
	ElemType *elem;
	Status length;
	int listsize;
}sql;


/*********��������**********/ 


  int  InitList(sql &list);  /*����һ�����Ա�ĺ�������*/
  int    DestroyList(sql &list); 
    int ListInsert(sql &list,int i,int &e);
    int ListDelete(sql &list,int i, int &e);
  
  
  
 /*********��ں���main*************/ 
int main()
{ 
	int a,b,e,d,f;
	sql list1;	
	a=InitList(list1);
	printf("���ص�ֵ�ǣ�%d\n",a);  //���鹹�����Ա��Ƿ�ɹ� 
	printf("�洢�����ǣ�%d\n",list1.listsize);
    b=DestroyList(list1);
	printf("�������Ա�󷵻ص�ֵ�ǣ�%d",b);
    
   
	return 0;
}

/************����ʵ��************/ 
		
		
int InitList(sql &list)  /*����һ���յ����Ա�*/ 
{
	list.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(int));
	if(!list.elem) return OVERFLOW;
	else
	{
		list.length=0;    //�ձ���Ϊ0 
		list.listsize=LIST_INIT_SIZE;  //��ʼ�洢���� 
		return OK;
		}
	
}


int DestroyList(sql &list) /*�������Ա�*/ 
{    
	if(!list.elem)return ERROP;
	 free(list.elem);
	 return OK;
	
}





  int ListInsert(sql &list,int i,int &e)  /*�����Ա�list�еĵ�i��λ�ò���e */
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
		   *(p+1)=*p;  /*����λ�ü�֮���Ԫ������*/ 
		   *q=e;
		      ++list.length;
		      return OK;
		   
		
		}

   int ListDelete(sql &list,int i,int&e)  /*ɾ����i��λ�õ�Ԫ��*/ 
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

 
