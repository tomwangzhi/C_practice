#include<stdio.h>
void huan(int *a, int *b)
{
	int *t;
	t=a;
	a=b;
	b=t;
	return;
}
int  main()
{
	int a=3;
	int b=5;
	huan(&a,&b);
	printf("a=%d,b=%d\n",a,b);
	getchar();
	return 0;
	

	
} 
