#include<stdio.h>  
#include<stdlib.h>  
#include <math.h>  
  /*****************ţ�ٵ���***************/ 
int  main()  
{  
    double a,b,c,d,x,xn,f,df;  
    printf("������4��ϵ��: ");  
    scanf("%lf%lf%lf%lf",&a,&b,&c,&d);  
    xn=2;  
    do  
    {  
        x=xn;  
        f=a*pow(x,3)+b*pow(x,2)+c*x+d;  
        df=3*a*pow(x,2)+2*b*x+c;   
        xn=x-f/df;              
    }while(fabs(xn-x)>=(1e-5));  
  
    printf("x=%lf\n",xn);  
    system("pause");  
}  


