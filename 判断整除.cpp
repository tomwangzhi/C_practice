#include<stdio.h>
/*******************���100��200��������3����************* ��5.5 */ 
int main(void)
{
	int i;
	for(i=100;i<=200;i++)
	{
		if(i%3==0)
		continue;
		printf("%d\t",i);
	}
		return 0;
	
}
