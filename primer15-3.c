/*
  编写一个函数，该函数接受一个int参数，并返回这个参数中打开的位的数量。在程序中测试该
函数。
*/
#include <stdio.h>

int count_on(int n);

int main(void)
{

  return 0;
}

int count_on(int n)
{
  int count = 0;

  //累计打开位
  while(n/2)
  {
      count += n%2;
      n = n >> 1;
  }

  count += n%2;
  return count;
}
