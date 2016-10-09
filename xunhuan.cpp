#include<stdio.h>
#include<math.h>
int main()
{
double sign=1.0,sum=1.0,deno=2.0,term;
while(deno<10000)
 {
		
		sign=(-1)*sign;
		term=sign*(1.0/deno);
		sum=sum+term;
		deno++;
		}
	
	printf("%f",sum);
	return 0;
}
