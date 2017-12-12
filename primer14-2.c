/*
  编写一个程序。请求用户键入日、月和年。月份可以是月份号、月份名或月份缩写。然后
程序返回一年中到给定日子（包括这一天）的总天数。
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int days(int year,int month,int day);
int leapyear(int year);

//定义月份结构体模版
struct month
{
  char name[10];
  char abbrev[4];
  int days;
  int monumb;
};

//结构体数组初始化
struct month months[12] = {
  {"january","jan",31,1},
  {"february","feb",28,2},
  {"march","mar",31,3},
  {"april","apr",30,4},
  {"may","may",31,5},
  {"june","jun",30,6},
  {"july","jul",31,7},
  {"august","aug",31,8},
  {"september","sep",30,9},
  {"october","oct",31,10},
  {"november","nov",30,11},
  {"december","dec",31,12}
};

int main(void)
{
    int day,month,year;
    int total = 0;

    printf("Please input year month and day\n");
    printf("year = ");
    scanf("%d",&year);
    printf("month = ");
    scanf("%d",&month);
    printf("day = ");
    scanf("%d",&day);

    total = days(year,month,day);


    printf("total days = %d\n",total);

    return 0;
}

//统计到到今年的t天数
int days(int year,int month,int day)
{
    int total = 0;
    int i = 0;

    if(leapyear(year))
    {
        months[2].days = 29;
    }
    else
        months[2].days = 28;

    if(month >= 1 && month <= 12)
    {
        while(month != months[i].monumb)
        {
           total += months[i].days;
           i++;
        }
        total = total + day;
        return total;
    }
    else
        return -1;
}

//判断是否为闰年
int leapyear(int year)
{
    if(year%400 == 0)
        return 1;
    else if(year%100 != 0 && year%4 == 0)
        return 1;
    else
        return 0;
}
