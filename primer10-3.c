/*
title:
  编写一个函数，返回一个int数组中存储的最大数值，并在一个简单的程序中测试这个函数。
*/
#include <stdio.h>

int max(int arr[],int n);

int main(void)
{
    /* 测试 */
    int arr[] = {1,4,2,79,6,32,54,23,12,64};

    printf("arr max = %d\n",max(arr,10));
}

//返回一个int数组中存储的最大数值
int max(int arr[],int n)
{
    int max,i;

    /* 找出最大值 */
    for(i=0,max=arr[0];i<n;i++)
        if(max < arr[i])
            max = arr[i];

    return max;
}
