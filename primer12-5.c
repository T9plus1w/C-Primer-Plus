/*
    编写产生100个1到10范围内的随机数的程序，并且以降序排序（可以将11章中的排序算法稍加
改动来对整数进行排序。这里，对数字本身进行排序即可）。
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void descending_sort(int arr[SIZE]);

int main(void)
{
    int number[SIZE];
    int i;

    for(i = 0;i < SIZE;i++)
    {
        number[i] = rand()%10+1;    //获得1-10的随机数
    }

    printf("排序前数组：\n");
    for(i = 0;i < SIZE;i++)
        printf("%d ",number[i]);    //输出数组
    printf("\n");

    descending_sort(number);

    printf("排序后数组：\n");
    for(i = 0;i < SIZE;i++)
        printf("%d ",number[i]);    //输出数组
    printf("\n");

    return 0;
}

//    倒叙排序
void descending_sort(int arr[SIZE])
{
    int i,j,temp;

    for(i=0;i<SIZE;i++)
        for(j=0;j<SIZE;j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
}
