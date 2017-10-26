/*
title:
  设计函数chline(ch,i,j),实现指定字符在i列到j列的输出，并用一个简单的驱动程序
测试该函数。
*/
#include <stdio.h>

void chline(char ch,int i,int j);

int main(void)
{
    char ch;
    int i,j;

    printf("input a char:");
    scanf("%c",&ch);

    printf("input two int:");
    scanf("%d %d",&i,&j);

    chline(ch,i,j);
}

/* 输出i列到j列为ch的符号 */
void chline(char ch,int i,int j)
{
    int k;
    for(k = 1;k < i; k++)
        printf(" ");
    for(;k < j;k++)
        printf("%c",ch);
    printf("\n");
}
