#include<stdio.h>
void maoppaixu(int *a,int n);
int main(void)
{
	int arr[7]={3,2,1,7,4,2,8};
	maoppaixu(arr,7);
	return 0;
}

 void maoppaixu(int *arr,int n)
{
   int i,j,temp;
   
	for(i=0;i<n;i++)          //n个数要进行n趟 
	{
		for(j=0;i+j<n-1;j++)      //每一趟都把最大的放到右边 
		{
			if(arr[j]>arr[j+1])
			{    
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
				}
			
			}
		}
	for(i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
		}	
		
		
	
} 



