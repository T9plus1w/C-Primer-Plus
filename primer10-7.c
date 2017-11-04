/*
title:
  利用练习2中的复制函数，把一个包含7个元素的数组内第3到第5元素复制到一个包含3个元素
的数组中。函数本身不需要修改，只需要选择合适的实际参数（实际参数不需要是数组名和数组
大小，而只须是数组元素的地址和需要复制的元素数目）。
*/
#include <stdio.h>

void copy_arra(int a[],int b[],int n);

int main(void)
{
    int arr[7] = {3,6,2,9,5,7,4},b[3];
    int *pt,i;

    //将第3到第5元素复制到b
    pt = &arr[2];
    copy_arra(pt,b,3);

    for(i=0;i<3;i++)
    {
        printf("%d ",b[i]);
    }
    printf("\n");
    return 0;
}

//制作第一份拷贝
void copy_arra(int a[],int b[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        b[i] = a[i];
    }
}
