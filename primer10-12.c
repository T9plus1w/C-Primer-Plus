/*
title:
  编写一个程序，提示用户输入3个数集，每个数集包括5个double值。程序应当实现
下列所有功能：

  a.把输入信息存储到一个3*5的数组中
  b.计算出每个数集（包括5个数值）的平均值
  c.计算所有数值的平均值
  d.找出这15个数中的最大值
  e.打印出结果

  每个任务需要用一个单独的函数来实现（使用传统c处理数组的方法）。对于任务b，
需要编写计算并返回一维数组平均值的函数，循环3次调用该函数来实现任务b。对于
其他任务，函数应当把整个数组做为参数，并且完成任务c和d的函数应该向它的调用
函数返回答案。
*/
#include <stdio.h>
#define N 3
#define M 5

double Average(double (*arr)[M]);
double allAverage(double arr[][M],int n);
double maxarr(double arr[][M],int n);

int main(void)
{
    //初始化二维数组
    double arr[N][M] = {
      {1.1,2.2,3.3,4.4,5.5},
      {6.6,7.7,7.6,8.8,8.7},
      {4.7,5.6,3.5,9.8,6.4}
    };
    double (*ptr)[M];    //指向二位数组的指针
//    int i,j;
    double ave1,ave2,ave3;    //每个数集的平均数
    double allave;    //全部数的平均数
    double max;    //最大值

    /* a、提示用户输入3个数集，每个数集包括5个double值。 */
/*    printf("Enter the number 3 sets, each set includes 5 double values.\n");
    for(i = 0;i < N;i++)
    {
        printf("please input 5 number:\n");
        for(j = 0;j < M;j++)
        {
          scanf("%lf",&arr[i][j]);
        }
    }
*/
    ptr = arr;

    ave1 = Average(ptr);
    ptr = ptr + 1;
    ave2 = Average(ptr);
    ptr = ptr + 1;
    ave3 = Average(ptr);

    allave = allAverage(arr,3);
    max = maxarr(arr,3);

    printf("ave1 = %0.2lf ave2 = %0.2lf ave3 = %0.2f\n",ave1,ave2,ave3);
    printf("allAverage = %0.2lf max = %0.2lf\n",allave,max);
    return 0;
}

/* b.计算出每个数集的值（包括5个值） */
double Average(double (*arr)[M])
{
    int i;
    double result = 0.00;

    for(i = 0;i < M;i++)
    {
        result += (*arr)[i];
    }

    return result/M;
}

/* c.计算所有数值的平均值 */
double allAverage(double arr[][M],int n)
{
    int i,j;
    double result = 0.00;

    for(i = 0;i < n;i++)
        for(j = 0;j < M;j++)
        {
            result += arr[i][j];
        }
    return result/(N*M);
}

/* d.找出这15个数中的最大值 */
double maxarr(double arr[][M],int n)
{
  int i,j;
  double max = 0.00;

  for(i = 0;i < n;i++)
      for(j = 0;j < M;j++)
      {
          if(max < arr[i][j])
              max = arr[i][j];
      }
  return max;
}
