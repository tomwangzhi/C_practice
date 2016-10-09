#include<stdio.h>
int main()
{
	int a[10];
	int i,j,t,k;
	for(i=0;i<10;i++)
	 scanf("%d",&a[i]);
	 for(i=0;i<10;i++)
	    {    k=i;
			for(j=i+1;j<10;j++)
			{
				if(a[k]>a[j])
				k=j;
				t=a[i];
				a[i]=a[k];
				a[k]=t;
				
				
				}
			
			}
			for(i=0;i<10;i++)
			printf("%d \t",a[i]);
	
}
