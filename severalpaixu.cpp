#include<stdio.h>
#define  N  10
void  leitai(int a[]);
void  xuanzhe(int a[]);
void  qipao(int a[]);
int main(void)
{   int i;
     int a[N];
	for(i=0;i<N;i++)
	scanf("%d",&a[i]);
	
	printf("\n");
	leitai(a);
	return 0;
}

void leitai(int a[])
{
	int max,min;
	int i,temp;
	 max=min=a[0];   //ÀÞÌ¨·¨°Ð×Ó 
	for(i=0;i<N;i++)
	{

	   if(a[i]<min)
	   min=a[i];
	   else if(a[i]>max)
	   max=a[i];
    }
	printf("%d %d",min,max);    
}
    
void xuanzhe(int a[])
{
	int i,j,temp,min;
	for(i=0;i<N;i++)
	{
		min=a[i];
		for(j=i;j<N;j++)
		{
			if(a[j]<min)
			
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
				}
			}
		}
	
	
}


	



