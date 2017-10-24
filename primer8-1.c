/*
title:设计一个程序，统计从输入到文件结尾为止的字符数
*/

#include <stdio.h>

int main(void)
{
    char ch;
    int i = 0;

    while ((ch = getchar()) != EOF)
    {
        i++;    //统计字符个数
    }
    printf("total = %d\n",i);    //输出字符个数

    return 0;
}
