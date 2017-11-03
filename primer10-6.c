/*
title:
  编写一个程序，初始化一个二维double数组，并利用练习2中的任一函数来把这个数复制
到另一个二维数组（因为二维数组是数组的数组，所以可以使用处理一维数组的函数来复制
数组的每个子数组）。
*/
#include <stdio.h>

#define COLS 3
void copy_arra(int a[][COLS],int b[][COLS],int n);

int main(void)
{
    /* 测试 */
    int arr[2][3] = {{4,5,6},{9,8,7}};
    int b[2][3];
    int i,j;

    //调用copy_arra函数
    copy_arra(arr,b,2);

    //打印b二维数组
    for(i=0;i<2;i++)
        for(j=0;j<COLS;j++)
            printf("%d ",b[i][j]);

    printf("\n");

    return 0;
}

//为二维数组进行拷贝数据
void copy_arra(int a[][3],int b[][3],int n)
{
    int i,j;
    //为二维数组拷贝数据
    for(i=0;i<n;i++)
    {
        for(j=0;j<COLS;j++)
            b[i][j] = a[i][j];
    }
}
