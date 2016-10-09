#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,k,n=0;
	for(i=101;i<=200;i++)
	{
		k=sqrt(i);
		for(j=2;j<k;j++)
		
			if(i%j==0) break;
			if(j>=k) 
			{printf("%d\t",i);
		    n++;
		     }
		
		}
		printf("素数个数是%d",n);
		return 0;
}
 
