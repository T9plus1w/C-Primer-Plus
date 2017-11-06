/*
title:
  编写一个程序，声明一个3*5的数组并初始化，具体数值可以随意。程序打印出数值，然后数值
翻一番，接着再次打印出新值。编写一个函数来显示数组的内容，再编写另一个函数执行翻倍功能。
数组名和数组行数做为参数由程序传递给函数。
*/
#include <stdio.h>

#define COWL 5

void printarr(int arr[][COWL],int n);
void doublearr(int arr[][COWL],int n);

int main(void)
{
    int arr[3][COWL] = {
      {1,2,3,4,5},
      {6,7,8,9,10},
      {11,12,13,14,15}
    };

    printarr(arr,3);
    printf("\n");

    doublearr(arr,3);

    printarr(arr,3);
    printf("\n");
    return 0;
}

/* 打印二维数组内的值 */
void printarr(int arr[][COWL],int n)
{
    int i,j;
    for(i = 0;i < n;i++)
        for(j = 0;j < COWL;j++)
            printf("%d ",arr[i][j]);
}

/* 二维数组内的值翻倍 */
void doublearr(int arr[][COWL],int n)
{
  int i,j;
  for(i = 0;i < n;i++)
      for(j = 0;j < COWL;j++)
          arr[i][j]=arr[i][j]*2;
}
