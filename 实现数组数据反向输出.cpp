/*******************������Ԫ�ص�ֵ���з������ʵ��******************************/



 
#include<stdio.h>
#define MAX_SIZE 10


void Chang_elem_arr(int *x,int n);     //������Ԫ�ؽ��з��� 
void Show_elem_arr(int *x);             //������������ӡ����Ļ��


 
int main()
{   
	int arr[MAX_SIZE]={1,4,5,4,82,45,19,9,1,3};
	Chang_elem_arr(arr,MAX_SIZE);
	Show_elem_arr(arr);
	return 0;
}



void Chang_elem_arr(int *x,int n)    //ʵ�ֶ��ṩ��������з������ 
{
	int temp,*p,*q,m;
	m=n/2;       //��¼�����м䲿�ֵ�λ�� 
	p=x;    //ָ������ĵ�һ��Ԫ�� 
	q=x+n-1;     // ָ����������һ��Ԫ�� 
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
		printf("�������Ϊ��%d\n",x[i]);
		}
}

