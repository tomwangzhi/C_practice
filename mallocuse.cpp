#include<stdio.h>
#include<stdlib.h>   /*rand,malloc,free*/
int main(void)
{
	int i,n;
	char *buffer;
	printf("how long strings do you want?\n" );
	scanf("%d",&i);
	buffer=(char*)malloc(i+1);
  	if(buffer==NULL)  exit(1);
  	for(n=0;n<i;n++)
  	buffer[n]=rand()%26+'a';
  	buffer[i]='\0';
  	printf("the rand of strings is\n %s",buffer);
  	free(buffer);
  	return 0;
  	
	
	
} 
