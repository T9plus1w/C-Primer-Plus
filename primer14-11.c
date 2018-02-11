/*
  编写一个transform()函数，它接受4个参数：包含double类型数据的源数组名，double类型的
目标数组名，表示数组元素个数的int变量以及一个函数名(或者，等价的指向函数的指针)。transform()
函数把指定的函数作用于源数组的每个元素，并将返回值放到目标数组中。例如：
    transform(source,target,100,sin);
  这个函数调用把sin(source[0])赋给target[0],等等，共有100个元素。在一个程序中测试该函数，
调用4次transform(),分别使用math.h函数库中的两个函数以及自己设计的两个适合的函数作为参数。
*/
#include <stdio.h>
#include <math.h>

#define M 10

void transform(double [],double [],int,double (*)(double));
double reciprocal(double x);
double negative(double x);

int main(void)
{
  double source[M],target[M];
  int i;
  for(i = 0; i < M;i++)
      source[i] = i;

  printf("sin:\n");
  transform(source, target, M, sin);

  for (i = 0;i < M;i++) {
      printf("%g -> %g,\n",source[i],target[i]);
  }
  return 0;
}

void transform(double source[],double target[],int n,double (*p)(double))
{
    int i;
    for(i = 0; i < M;i++)
    {
        target[i] = (*p)(source[i]);
    }
}
