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

#define MAXTITL 40
#define MAXAUTL 40
#define MAXAIR 12    

struct airplane
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

void showmenu();
int main(void)
{
  struct airplane airplane[MAXAIR];
  showmenu();
  
  return 0;
}

void showmenu()
{
    printf("To choose a function\n", );
}
