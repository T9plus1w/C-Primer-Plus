/*
title:
  编写一个函数，函数的3个参数是一个字符和两个整数。字符参数是需要输出的字符。第一个整数
说明了在每行中该字符输出的个数，而第二个整数指的是需要输出的行数。编写一个调用该函数的程
序。
*/
#include <stdio.h>

void chline(char ch,int column,int row);

int main(void)
{
  char ch;
  int i,j;

  printf("input a char:");
  scanf("%c",&ch);

  printf("input two int:");
  scanf("%d %d",&i,&j);

  chline(ch,i,j);

  return 0;
}

/* 打印一个y行x列的ch字符方阵 */
void chline(char ch,int column,int row)
{
    int i,j;
    for(i = 0; i < row;i++)
    {
        for(j = 0; j < column;j++)
            putchar(ch);
        printf("\n");
    }
}
