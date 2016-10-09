#include<stdio.h>
int main(void)
{
	float x,y;
	printf("请输入x：");
	scanf("%f",&x);
	getchar();
	if(x<=1)
	y=x;
	else if(x<=10 && x>1)
	y=2*x-1;
	else
	y=3*x-11;
	printf("y的值是%f",y);
	
	
	
	
	return 0;
} 
