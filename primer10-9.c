/*
title:
  编写一个函数，把两个数组内的相应元素相加，结果存储到第3个数组内。也就是说，如果数组1
具有值2、4、5、8，数组2具有值1、0、4、6，则函数对数组3赋值为3、4、9、14。函数的参数包
括3个数组名和数组大小。并在一个简单的程序中测试这个函数。
*/
#include <stdio.h>

#define COLS 4
void sum(int arr1[COLS],int arr2[COLS],int arr3[COLS]);

int main(void)
{
    /* 测试 */
    int a[COLS] = {2,4,5,8};
    int b[COLS] = {1,0,4,6};
    int arr[COLS];
    int i;

    sum(a,b,arr);
    
    for(i = 0;i < COLS;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}

/* 把两个数组内的相应元素相加，结果存储到第3个数组内 */
void sum(int arr1[COLS],int arr2[COLS],int arr3[COLS])
{
    int i;
    for(i = 0;i < COLS;i++)
        arr3[i] = arr1[i]+arr2[i];
}
