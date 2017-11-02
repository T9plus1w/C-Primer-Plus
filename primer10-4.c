/*
title:
  编写一个函数，返回一个double数组中存储的最大数值的索引，并在一个简单程序中测试这个
函数。
*/
#include <stdio.h>

int maxIndex(double arr[],int n);

int main(void)
{
    /* 测试 */
    double arr[] = {1.3,4.2,2.4,79.2,6.8,32.6,54.0,23.4,12.5,64.9};

    printf("arr max = %d\n",maxIndex(arr,10));
    return 0;
}

/* 返回一个double数组中存储的最大数值的索引 */
int maxIndex(double arr[],int n)
{
    int flag,i;
    double max;

    //找出最大值，标记索引
    for(i=0,max=arr[0];i<n;i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
            flag = i;
        }
    }

    return flag+1;
}
