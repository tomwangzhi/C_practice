#include<stdio.h>
#include<math.h>
int main()
{
	double f,df,x,xn;
	xn=1.5;
	do{
		x=xn;
		f=2*pow(x,3)-4*pow(x,2)+3*x-6;
		df=6*pow(x,2)-8*x+3;
		xn=x-f/df;
		
		}while(fabs(xn-x)<1e-5);
		printf("%f",xn); 
}
