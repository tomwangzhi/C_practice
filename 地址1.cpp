#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DENSITY 62.4

int main()
{   float weight,volume;
	int size,letters;
	char str[7]="nih d";
	char name[40];
	printf("请输入你的名字：\n");
	scanf("%s",name);
	printf("%s 你的体重是多少？\n",name);
	scanf("%f",&weight);
	size=sizeof(name);
	letters=strlen(name);
	printf("你的名字有的存储空间有%d bytes\n",size);
	printf("你的名字长度为%d个bytes\n",letters);
	printf("名字的地址是：%d",str[7]);
	return 0;
}


