#include<stdio.h>
/*******************输出100到200不能整除3的数************* 例5.5 */ 
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
