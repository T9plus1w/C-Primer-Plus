/*
tiele:
  两数值的谐均值可以这样计算：首先对两数值的倒数取平均值，最后再取倒数。编写一个带有
两个double参数的函数，计算这两个参数的谐均值。
*/
#include <stdio.h>

double mean(double x,double y);
int main(void)
{
    double a,b;
    
    printf("input two double:");
    scanf("%lf %lf",&a,&b);
    printf("%0.3lf\n",mean(a,b));
    
    return 0; 
}

/* 求两数值的谐均值 */
double mean(double x,double y)
{
    return 1/((1/x+1/y)/2);
}
