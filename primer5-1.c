/* title:编写一个程序。将用分钟表示的时间转换成以小时和分钟表示的时
   间，使用#define或者const来创建一个表示60的符号常量。使用while
   循环来允许用户重复键入值，并且当键入一个小于等于0的时间时终止循环。*/
#include <stdio.h>
#define MINUTE 60

int main(void)
{
    int minute;
    int hour,min;

    printf("please input minute:");
    while(scanf("%d",&minute) == 1)  //输入分钟数
    {
        if(minute <= 0)    //分钟数小于等于0将退出
            break;
        else
        {
            hour = minute / MINUTE;
            min = minute % MINUTE;
            printf("%d hour %d minute\n",hour,min);
        }
        printf("please input minute:");
    }
    printf("bye!!\n");
    return 0;
}
