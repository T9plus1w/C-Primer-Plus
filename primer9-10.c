/*
  编写并测试一个函数Fibonacei(),在该函数中使用循环代替递归完成斐波纳契数列
的计算。
*/
#include <stdio.h>

long Fibonacci(int n);

int main(void)
{
    int n,fibonc;
    printf("please input Fibonacci number:");
    scanf("%d",&n);

    fibonc = Fibonacci(n);

    printf("fibonacci is:%d\n",fibonc);    //打印第n位的斐波那契数值

    return 0;
}

/* 斐波那契数列计算，返回第n位数(使用循环)*/
long Fibonacci(int n)
{
    long i,x,y,z,temp;

    x = 1;
    y = 1;
    z = 0;    //保持前两位数之和

    if(n <= 2)
        return 1;
    else
    {
        for(i = 0;i < n-2;i++)
        {
            z = x + y;    //x,y调换值，更新z
            temp = y;
            x = y;
            y = z;
        }
        return z;
    }
}
