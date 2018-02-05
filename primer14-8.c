/*
  巨人航空公司的机群由座位容量为12的飞机组成。它每天飞行一个航班。按照下面的功能，写一个
座位预定程序：
  a.程序使用一个含12个结构的数组。每个结构要包括一个用于标识座位的编号、一个表示座位是否
分配出去的标记、座位预定人的姓和座位预定人的名。
  b.程序显示下面的菜单：

  To choose a function,enter its letter label:
  a.Show number of empty seats
  b.Show list of empty seats
  c.Show alphabetical list of seats
  d.Assign a customer to a seat assignment
  e.Delete a seat assignment
  f.Quit

  c.程序应能执行菜单所给出的功能。选择d和e需要额外的输入，每一个选项都应当允许用户终止
  输入。
  d.执行完一个特定的功能之后，程序再次显示菜单，除非选择了f。
  e.每次运行程序都把数据保存到一个文件中。当程序再次运行时，首先从文件中载入数据（如果有的话）。
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXAIR 12

struct airplane
{
    int number;
    bool occupied;    //座位是否分配出去 0未分配，1已分配
    char firstName[MAXTITL];
    char lastName[MAXAUTL];
};

void showmenu();
void init(struct airplane airplane[MAXAIR]);
void showEmptySeats(struct airplane airplane[MAXAIR]);
void showListEmptySeats(struct airplane airplane[MAXAIR]);
void showAlphabeticalListSeats(struct airplane airplane[MAXAIR]);
int assignment(struct airplane airplane[MAXAIR],struct airplane temp);
int deleteSeats(struct airplane airplane[MAXAIR],struct airplane temp);

int main(void)
{
  struct airplane airplane[MAXAIR];
  struct airplane temp;
  char keyword;
  char c;

  //初始化座位编号以及是否分配
  init(airplane);
  //显示菜单,并提示用户输入一个字符
  showmenu();
  printf("Please enter a~e(f to quit):");

  //获取第一个用户选项
  keyword = getchar();
  while((c = getchar()) != '\n' && c != EOF)
      continue;

  //菜单程序，输出用户选择的功能并循环输入
  while(keyword >= 'a' && keyword <= 'f' )
  {
      switch (keyword)
      {
          case 'a':
              showEmptySeats(airplane);
              break;
          case 'b':
              showListEmptySeats(airplane);
              break;
          case 'c':
              showAlphabeticalListSeats(airplane);
              break;
          case 'd':
              //获取temp
              printf("please enter first Name:");
              scanf("%s",temp.firstName);
              while(getchar() != '\n')
                  continue;
              printf("please enter last Name:");
              scanf("%s",temp.lastName);
              while(getchar() != '\n')
                  continue;
              temp.occupied = 1;

              assignment(airplane,temp);
              break;
          case 'e':
              //获取temp
              printf("please enter first Name:");
              scanf("%s",temp.firstName);
              while(getchar() != '\n')
                  continue;
              printf("please enter last Name:");
              scanf("%s",temp.lastName);
              while(getchar() != '\n')
                  continue;

              deleteSeats(airplane,temp);
              break;
          case 'f':
              return 1;
              break;
          default:
              printf("please enter a~e(f to quit):\n");
       }

        showmenu();
        printf("Please enter a~e(f to quit):");
        keyword = getchar();

        //清空getchar缓存
        while((c = getchar()) != '\n' && c != EOF)
            continue;
    }

    return 0;
}

//显示菜单函数
void showmenu()
{
    printf("To choose a function\n");
    printf("a.Show number of empty seats.\n");
    printf("b.Show list of empty seats\n");
    printf("c.Show alphabetical list of seats\n");
    printf("d.Assign a customer to a seat assignment\n");
    printf("e.Delete a seat assignment\n");
    printf("f.Quit\n");
}

//初始化座位编号以及是否分配
void init(struct airplane airplane[MAXAIR])
{
    int i;
    for(i = 0; i < MAXAIR;i++)
    {
        airplane[i].number = i+1;
        airplane[i].occupied = 0;
        airplane[i].firstName[0] = '\0';
        airplane[i].lastName[0] = '\0';
    }
}

//显示空座位函数
void showEmptySeats(struct airplane airplane[MAXAIR])
{
    int i;
    int count = 0;
    for(i = 0; i < MAXAIR; i++)
    {
        if(airplane[i].occupied == 0)
        {
            count++;
        }
    }
    printf("空座位数共计: %d\n",count);
}

//显示空座位数列表
void showListEmptySeats(struct airplane airplane[MAXAIR])
{
    int i;

    printf("空座位编号:");
    for(i = 0; i < MAXAIR; i++)
    {
        if(airplane[i].occupied == 0)
        {
          printf("%d ",airplane[i].number);
        }
    }
    printf("\n");
}

//显示座位的字母顺序
void showAlphabeticalListSeats(struct airplane airplane[MAXAIR])
{
    int i;
    for(i = 0; i < MAXAIR;i++)
    {
        if(airplane[i].occupied == 1)
        {
            printf("%d %s %s\n",airplane[i].number,airplane[i].firstName
                             ,airplane[i].lastName);
        }
    }
}

//分配一个客户到一个座位
int assignment(struct airplane airplane[MAXAIR],struct airplane temp)
{
    int i;
    for(i = 0; i < MAXAIR;i++)
    {
        if(airplane[i].occupied == 0)
        {
            temp.number = airplane[i].number;
            airplane[i] = temp;
            return 1;
        }
    }
    return 0;
}

//删除一个座位分配
int deleteSeats(struct airplane airplane[MAXAIR],struct airplane temp)
{
    int i;
    for(i = 0; i < MAXAIR;i++)
    {
        if(!(strcmp(airplane[i].firstName,temp.firstName)))
        {
            if(!(strcmp(airplane[i].lastName,temp.lastName)))
            {
                airplane[i].firstName[0] = '\0';
                airplane[i].lastName[0] = '\0';
                airplane[i].occupied = 0;
                return 1;
            }
        }
    }

    return 0;
}
