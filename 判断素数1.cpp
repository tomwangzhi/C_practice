#include<stdio.h>
int main()
{
	int i,n,k=0;
	for(n=3;n<100;n++)
	{
		for(i=2;i<n;i++)
		{
			if(n%i==0)  break;
			if(i==n)
			{
				printf("%d4d",n);
				k++;
				if(k%10==0) printf("\n");
				}
			}
		}
		return 0;
} 
