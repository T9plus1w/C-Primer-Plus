/*
    一个文本文件中存放着一个棒球队的信息。每一行的数据都是这样排列的：
    4 Jessie Joybat 5 2 1 1
    第一项是球员号码，为了方便，范围是0到18.第二项是球员的名，第三项是姓。姓和名
都是单个的单词。下一项是官方统计的球员上场次数，紧跟着是击中数、走垒数和跑点数（RBI）.
文件可能包括超过一场比赛的数据，因此同一个球员可能会有多于一行的数据，而且在不同的行
之间有可能有别的球员的数据。写一个程序，把这些数据存储到一个结构数组中。结构中必须
含有姓、名、上场次数、击中数、走垒数和跑点数，以及击球平均成功率（稍后计算）。可以使用
球员号码作为数组索引。程序应该读到文件末尾，并且应该保存每个球员的累计总和。
  这个棒球运动中的统计方法是相关的。例如，一次走垒和触垒中的失误并不会记作上场次数，但
是这可能产生一个RBI。可是，该程序所要做的只是处理数据文件，而不必关心数据的实际含义。
  要实现这些功能，最简单的方法是把结构的内容初始化为零值，将文件数据读入临时变量中，然后
把它们加到相应结构的内容中。程序读完文件后，应该计算每个球员的击球平均成功率，并把它保存
到相应的结构成员里。计算击球平均成功率是用球员的累计击中数除以上场累计次数；这是个浮点数
计算。然后程序要显示每个球员的累计数据，并且对整个时期显示一行综合统计数据。
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 18
struct name
{
  int number;
  char firstName[20];
  char lastName[20];
};

struct player
{
  struct name name;
  int numberTime;
  int hitNumber;
  int baseNumber;
  int runningPoint;
  double successRate;
};

void initPlayer(struct player *player);
void inputPlayer(struct player *player,FILE *fa);
void accNumber(struct player *player);
void show(struct player *player);

int main(void)
{
    FILE *fa;
    struct player player[SIZE];
    char file_src[20];

    //初始化球员
    initPlayer(player);
    //获取player_data文件名并打开文件
    puts("Enter name of destination file: ");
    gets(file_src);
    if((fa = fopen(file_src,"r")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n",file_src);
        exit(2);
    }
    //获取球员数据
    inputPlayer(player,fa);
    fclose(fa);
    accNumber(player);
    show(player);

    return 0;
}

/* 初始化结构体 */
void initPlayer(struct player *player)
{
    int i;
    for(i = 0; i < SIZE;i++)
    {
      player[i].name.firstName[0] = '\0';
      player[i].name.lastName[0] = '\0';
      player[i].baseNumber = 0;
      player[i].hitNumber = 0;
      player[i].numberTime = 0;
      player[i].runningPoint = 0;
      player[i].successRate = 0.0;
    }
}

/* 获取球员数据 */
void inputPlayer(struct player *player,FILE *fa)
{
  struct player temp;

  //读取文件数据直至结尾
  while(!feof(fa))
  {
    //获取一行数据，制作临时结构体
    fscanf(fa,"%d %s %s",&temp.name.number,temp.name.firstName,temp.name.lastName);
    fscanf(fa,"%d %d %d %d",&temp.numberTime,&temp.hitNumber,&temp.baseNumber
           ,&temp.runningPoint);

    //如果姓名不为空则累加球员数据
    if(player[temp.name.number].name.firstName[0] != '\0')
    {
        player[temp.name.number].numberTime += temp.numberTime;
        player[temp.name.number].hitNumber += temp.hitNumber;
        player[temp.name.number].baseNumber += temp.baseNumber;
        player[temp.name.number].runningPoint += temp.runningPoint;
    }

    //否则添加新数据
    else
        player[temp.name.number] = temp;
  }
}

/* 计算累计击球数 */
void accNumber(struct player *player)
{
  int i;
  for(i = 0; i < SIZE;i++)
  {
    if(player[i].hitNumber != 0)
        player[i].successRate = player[i].numberTime / player[i].hitNumber;
  }
}

/* 显示数据 */
void show(struct player *player)
{
  int i;
  for(i = 0; i < SIZE;i++)
  {
    printf("%d %s %s %d %d %d %d %.2lf\n",player[i].name.number
                                     ,player[i].name.firstName
                                     ,player[i].name.lastName
                                     ,player[i].numberTime
                                     ,player[i].hitNumber
                                     ,player[i].baseNumber
                                     ,player[i].runningPoint
                                     ,player[i].successRate);
  }
}
