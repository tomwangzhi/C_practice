#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define DENSITY 62.4

int main()
{   float weight,volume;
	int size,letters;
	char str[7]="nih d";
	char name[40];
	printf("������������֣�\n");
	scanf("%s",name);
	printf("%s ��������Ƕ��٣�\n",name);
	scanf("%f",&weight);
	size=sizeof(name);
	letters=strlen(name);
	printf("��������еĴ洢�ռ���%d bytes\n",size);
	printf("������ֳ���Ϊ%d��bytes\n",letters);
	printf("���ֵĵ�ַ�ǣ�%d",str[7]);
	return 0;
}


