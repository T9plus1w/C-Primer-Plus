/*
  编写并测试函数langer_of( ),其功能是将两个double类型变量的数值替换成它们
中的较大值。例如，langer_of(x,y)会把x和y中的较大数值重新赋给变量x和y。
*/
#include <stdio.h>

void langer_of(double *x,double *y);

int main(void)
{
    double x,y;

    //输入两个数
    printf("please input two number\n");
    printf("x :");
    scanf("%lf",&x);
    printf("y :");
    scanf("%lf",&y);

    //把x和y中的较大数值重新赋给变量x和y
    langer_of(&x,&y);

    //输出两个变量的值
    printf("output max number:x = %0.2lf,y = %0.2lf\n",x,y);

    return 0;
}

/* 把x和y中的较大数值重新赋给变量x和y */
void langer_of(double *x,double *y)
{
    if(*x > *y)
        *y = *x;
    else
        *x = *y;
}
