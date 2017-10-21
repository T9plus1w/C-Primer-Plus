/* title:编写一个程序，此程序要求输入一个整数，然后打印出从（包括）
   输入的值到（包括）比输入的值大10的所有整数值（也就是说，如果输入
   为5，那么输出就以5到15）。要求在各个输出值之间用空格，制表符或
   换行符分开                                             */
#include <stdio.h>

int main(void)
{
    int max,number;
    
    printf("please input the number:");
    scanf("%d",&number);
    max = number + 10;    //计算出上边界的数
    printf("Print this to count 10(include the number)\n");

    //循环打印
    while(number <= max)
    {
        printf("%d ",number++);
    }
    printf("\n");

    return 0;
}
