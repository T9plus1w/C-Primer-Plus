/*
    编写一个产生1000个1到10范围内的随机数的程序。不必保存或打印数字，仅打印每个数被
产生了多少次。让程序对10个不同的种子值进行计算。数字出现的次数相同吗？可以使用本章中的
函数或ANSI C中的函数rand()和srand()，它们与我们的函数具有相同的形式。这是一个测试
特定随机数发生器的随机性的方法。
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000
int main(void)
{
    int arr[10] = {0,0,0,0,0,0,0,0,0,0};
    int i,ch;
    unsigned int seed;

    printf("Enter a positive integer seed value:");
    scanf("%u",&seed);
    srand(seed);    //改变随机种子

    for(i = 0;i < SIZE;i++)
    {
        ch = rand()%10+1;    //获得1-10的随机数

        switch(ch)
        {
            case 1:
                arr[0]++;
                break;
            case 2:
                arr[1]++;
                break;
            case 3:
                arr[2]++;
                break;
            case 4:
                arr[3]++;
                break;
            case 5:
                arr[4]++;
                break;
            case 6:
                arr[5]++;
                break;
            case 7:
                arr[6]++;
                break;
            case 8:
                arr[7]++;
                break;
            case 9:
                arr[8]++;
                break;
            case 10:
                arr[9]++;
                break;
            default:
                return 1;
        }
    }

    //打印1-10出现次数
    for(i = 0; i < 10; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");

    return 0;
}
