/*
title:
  编写一个程序，初始化一个3*5的二维数组，并利用一个基于变长数组的函数把该数组
复制到另一个二维数组。还要编写一个基于变长数组的函数来显示两个数组的内容。这两
个函数应该能够处理任意的N*M数组（如果没有可以支持变长数组的编译器，就使用传统
C中处理N＊5数组的函数方法）。
*/
#include <stdio.h>

void copy_arrVla(int n,int m,int arr[n][m],int b[n][m]);
void print_arrVla(int n,int m,int b[n][m]);

int main(void)
{
    /* 测试 */
    int arr[3][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    int n = 3;
    int m = 5;
    int b[n][m];

    copy_arrVla(n, m, arr,b);

    print_arrVla(n, m, b);

    printf("\n");
    return 0;
}

/* 使用变长数组进行拷贝 */
void copy_arrVla(int n,int m,int arr[n][m],int b[n][m])
{
    int i,j;
    for(i = 0;i < n;i++)
        for(j = 0;j < m;j++)
            b[i][j] = arr[i][j];
}

/* 打印变长数组 */
void print_arrVla(int n,int m,int b[n][m])
{
    int i,j;
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < m;j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
}
