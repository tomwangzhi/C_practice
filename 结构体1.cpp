#include"stdio.h"
 



struct stu /*����ṹ*/
{
int num;
char *name;
char sex;
float score;
} boy2,boy1={102,"Zhang ping",'M',78.5};
int main()
{
boy2=boy1;
printf("Number=%d\nName=%s\n",boy2.num,boy2.name);
printf("Sex=%c\nScore=%f\n",boy2.sex,boy2.score);
}

