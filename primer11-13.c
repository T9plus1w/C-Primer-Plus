/*
    编写一个计算乘幂的基于命令行的程序。第一个命令行参数为double类型数，做为幂的底数；
第二个参数为整数，作为幂的指数。
*/
#include <stdio.h>
#include <stdlib.h>

double power(double x,int y);

int main(int argc,char *argv[])
{
    int y;
    double x,total;

    //获取命令行参数数值
    x = atof(argv[1]);
    y = atoi(argv[2]);

    total = power(x,y);

    printf("%lf\n",total);
    return 0;
}

//计算double类型，x的y次幂
double power(double x,int y)
{
    int i;
    double total = 1;    //y为0次幂不返回1

    for(i = 0; i < y;i++)
    {
        total = total * x;    //计算x的y次幂结果
    }

    return total;
}
