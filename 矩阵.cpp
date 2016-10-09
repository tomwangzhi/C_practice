#include<stdio.h>
	int a[2][2],b[2][2];
int main()
{

	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			a[i][j]=0;
			b[i][j]=0;
		}
		
	}
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				printf("please add the elem to array:\n");
				scanf("%d %d",&a[i][j],&b[i][j]);
				
			}
		}
			
		for(i=0;i<3;i++)
		{    for(j=0;j<3;j++)
			printf("%d",a[i][j]);
			}	
	return 0;
} 
