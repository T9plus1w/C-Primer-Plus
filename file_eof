/*******************************************
描述：file_eof.c -- 打开一个文件并显示其内容
功能：实现文件打开并显示其内容功能
版本：v1.00
作者：汤俊伟
时间：2017.05.20
学习点：文件的操作
********************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ch;
    FILE *fp;
    char fname[50];  //用于存放文件名
    
    printf("Enter the name of the file:");
    scanf("%s",&fname);
    fp = fopen (fname,'r'); //打开文件以供读取
    if(fp == NULL)          //尝试打开文件失败
    {
    printf("Failed to open file.Bye\n");
    exit(1);                //终止程序
    }
    //getc(fp)从打开的文件中获取一个字符
    while ((ch = getchar(fp)) != EOF)
        putchar(ch);
    fclose(fp);             //关闭文件
    return 0;
}
