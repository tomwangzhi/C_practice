#include<stdio.h>
int main(void)
{
	float x,y;
	printf("������x��");
	scanf("%f",&x);
	getchar();
	if(x<=1)
	y=x;
	else if(x<=10 && x>1)
	y=2*x-1;
	else
	y=3*x-11;
	printf("y��ֵ��%f",y);
	
	
	
	
	return 0;
} 
