#include<stdio.h>
//int main(void)
//{ int x;               //不初始化默认是0 
//	while(x++ < 10)
//{
//if(x == 3)
//{
//continue;                 //continue结束整个循环 
//}
//printf("%d\r\n",x);
//}


//while(x++ < 10)
//{
//if(x == 3)
//{
//break;                  //break结束本次循环开始下一次循环 
//}
//printf("%d\r\n",x);
//}
//}
static int cJSON_strcasecmp(const char *s1,const char *s2);
int main()
{    int a;
    	a=cJSON_strcasecmp("aa","aa");
    	printf("%d",a);
    	return 0;
}

static int cJSON_strcasecmp(const char *s1,const char *s2)
{
	if (!s1) return (s1==s2)?0:1;//if (!s2) return 1;
}
