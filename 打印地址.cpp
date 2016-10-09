/***********用指针输出二维数组的地址值*********************/

#include<stdio.h>
int main()
{int a[2][3]={2,3,4,6,21,1};
  int *p;
  p=&a[0][0];
  for(int i=0;i<6;i++)
  {
		printf("数组元素的地址为：%p\n",p++);
		}
		return 0;
}
