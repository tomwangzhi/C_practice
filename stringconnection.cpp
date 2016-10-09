#include<stdio.h>
int main()
{
	char str1[25],str2[11];
	int i=0,j=0;
	printf("please input string!");
	scanf("%s",str1);
	printf("please input string2:");
	scanf("%s",str2);
	while(str1[i]!='\0')
	i++;
	while(str2[j]!='\0')
	str1[i++]=str2[j++];
	str1[i]='\0';
	printf("%s",str1);
	
	
} 
