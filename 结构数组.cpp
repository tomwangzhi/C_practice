#include<stdio.h>

 
struct stu
{
int num;
char *name;
char sex;
float score;
}boy[5]={
{101,"Li ping","M",45},
{102,"Zhang ping","M",62.5},
{103,"He fang","F",92.5},
{104,"Cheng ling","F",87},
{105,"Wang ming","M",58},
        };
int main()
{printf("%d",boy[1].num);
return 0;
}
