#include<stdio.h>

int main(void)
{
    int i,m=0;     //m为标志位
    int k;
    int cost[13];//预支的开销
    int save=0; //每个月之后还剩余的钱
    int  storage=0;  //存到妈妈手上的钱
    for( i=1;i<=12;i++)
    { 
	  scanf("%d",&cost[i]);
	 
	}
    for(i=1;i<=12;i++)
    {
      save+=300;
      save-=cost[i];
      if(save<0)
      {
        m=1;
        break;
         }
      if(save>=100)
      {
          k=save/100;
          save-=k*100;
          storage+=k*100;
      }
      
      
    }
    if(m==1)  printf("%d",-i);
    
    else 
	{
		 printf("%d",(int)(save+storage*1.2));
		}
    
    return 0;
}
