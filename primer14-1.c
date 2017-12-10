/*
  重做复习题3，但用月份名的拼写代替月份号（别忘了可以使用strcmp()）.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int days(char* p);

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
    char input[10];
    int daytotal;

    //输入月份
    printf("Enter the name of a month:");
    while(gets(input) != NULL && input[0] != '\0')  //获取月份名
    {
      daytotal = days(input);  //计算到这个月份的天数
          if(daytotal > 0)
              printf("There are %d days through %s.\n",daytotal,input);
          else
              printf("%s is not valid input.\n",input);
      printf("Next month (empty line to quit):");
    }
    puts("bye");

    return 0;
}

//返回一年中到该月的总共天数
int days(char* p)
{
    int i = 0,total = 0;
    while(p[i] != '\0')
    {
        p[i] = tolower(p[i]);
        i++;
    }

    for(i = 0;i < 12;i++)
    {
        total += months[i].days;
        if(strcmp(p,months[i].name) == 0)    //查找这个月份
            return total;
    }

    return -1;
}
