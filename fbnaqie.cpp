#include<stdio.h>
void fabonaqie();
int main(void)
{
	
  fabonaqie();	
	
	
	return 0;
} 

  void fabonaqie()
{    
	int i,t1=1,t2=1,display,count;
	printf("please enter the digitals:\n");
	scanf("%d",&i);
	printf("%d %d ",t1,t2);
	count=2;
	while(count<i)
	{
		display=t1+t2;
		t1=display;
		t1=t2;
		t2=display;
		printf("%%%d  ",display);
		count++;
		
		}
	
}
