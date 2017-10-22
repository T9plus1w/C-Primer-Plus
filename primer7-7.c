/*
title:编写程序，要求输入一周中的工作小时数，然后打印工资总额、税金以及净工资。作如下假设：
a．基本工资等级=10.00美元//J,时
b．加班（超过40小时）=1.5倍的时间
c．税率    前300美元为15%     下一个150美元为20%     余下的为25%
用#define定义常量，不必关心本例是否符合当前的税法。
*/
#include <stdio.h>

#define WAGES 10
#define OVERTIME 40
int main(void)
{
    int hour;
    int tatolWages,tax,netWages;

    printf("please input working hour:");
    scanf("%d",&hour);
    /* 总工资 */
    if(hour > OVERTIME)
        hour = OVERTIME + (hour - OVERTIME)*1.5;
    tatolWages = hour * WAGES;

    /* 税金 */
    if(tatolWages <= 300)
    {
        tax = tatolWages * 0.15;
    }
    else if(tatolWages > 300 && tatolWages <= 450)
    {
        tax = 300 * 0.15 + (tatolWages-300) * 0.20;
    }
    else
        tax = 300*0.15+150*0.20+(tatolWages-450)*0.25;

    /* 净工资 */
    netWages = tatolWages - tax;

    /* 打印总工资，税金，净工资 */
    printf("tatolWages = %dhours,tax = %d$,netWages = %d$\n",tatolWages,tax,netWages);

    return 0;
}
