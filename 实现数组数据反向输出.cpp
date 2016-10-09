/*******************对数组元素的值进行反向输出实现******************************/



 
#include<stdio.h>
#define MAX_SIZE 10


void Chang_elem_arr(int *x,int n);     //将数组元素进行反向 
void Show_elem_arr(int *x);             //将反向的数组打印到屏幕上


 
int main()
{   
	int arr[MAX_SIZE]={1,4,5,4,82,45,19,9,1,3};
	Chang_elem_arr(arr,MAX_SIZE);
	Show_elem_arr(arr);
	return 0;
}



void Chang_elem_arr(int *x,int n)    //实现对提供的数组进行反向输出 
{
	int temp,*p,*q,m;
	m=n/2;       //记录数组中间部分的位置 
	p=x;    //指向数组的第一个元素 
	q=x+n-1;     // 指向数组的最后一个元素 
	for(int i=0;i<m;i++)   
	{
		temp=*p;
		*p=*q;
		*q=temp;
		p++;
		q--;
		}
	
} 


void Show_elem_arr(int *x)
{
	for(int i=0;i<MAX_SIZE;i++)
	{
		printf("输出的数为：%d\n",x[i]);
		}
}

