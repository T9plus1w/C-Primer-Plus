/*
title:
  编写一个程序，初始化一个double数组，然后把数组内容复制到另外两个数组（3个数组都需要在
主程序中声明）。制作第一份拷贝的函数使用数组符号。制作第二份拷贝的函数使用指针符号，并使
用指针的增量操作。把目标数组名和要复制的元素数目做为参数传递给函数。也就是说，如果给定了
下列声明，函数调用应该如下面所示：
    double source[5] = {1.1,2.2,3.3,4.4,5.5};
    double target1[5];
    double target2[5];
    copy_arr(source,target1,5);
    copy_ptr(source,target2,5);
*/
#include <stdio.h>

void copy_arra(double a[],double b[],int n);
void copy_ptr(double *,double *,int n);

int main()
{
    double source[5] = {1.1,2.2,3.3,4.4,5.5};
    double target1[5];
    double target2[5];
    int i;

    //将source拷贝至target1
    printf("target1\n");
    copy_arra(source,target1,5);

    for(i = 0;i < 5;i++)
    {
        printf("target1 %d= %.2f\n",i+1,target1[i]);
    }

    //将source拷贝至target2
    printf("target2\n");
    copy_ptr(source,target2,5);

    for(i = 0;i < 5;i++)
    {
        printf("target2 %d= %.2f\n",i+1,target2[i]);
    }

    return 0;
}

//制作第一份拷贝，使用数组符号
void copy_arra(double a[],double b[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        b[i] = a[i];
    }
}

//制作第二份拷贝，使用指针符号
void copy_ptr(double *a,double *b,int n)
{
    int i;

    for(i = 0;i < n;i++)
    {
        *(b+i)=*(a+i);
    }
}
