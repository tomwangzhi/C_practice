#include<stdio.h>
#define MAXNUM  100
void QuickSort(int a[],int left,int right);
int main()
{    
	int i,n;
	int arr[MAXNUM];
	printf("����������Ԫ����Ŀ\n");
	scanf("%d",&n);
	getchar();
	printf("����������Ԫ��\n");
	for(i=0;i<n;i++)
	scanf("%d",&arr[i]);
	QuickSort(arr,0,n-1);
	for(i=0;i<n;i++)
	printf("%d\n",arr[i]);
	
	
	return 0;
}
void QuickSort(int a[],int left,int right)
{
	int i,j,temp,t;
	i=left;     //����ڱ� 
	j=right;    //�ұ��ڱ� 
	temp=a[left];
	if(i>j)
	return;
	while(i!=j)
	{
		while(i<j && a[j]>=temp)
     	j--;
	    while(i<j && a[i]<=temp)
	    i++;
	    if(i<j)
	    {
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			
			}
			
	    
    }
    a[left]=a[i];
    a[i]=temp;
     QuickSort(a,left,i-1);
     QuickSort(a,i+1,right);
    
}
