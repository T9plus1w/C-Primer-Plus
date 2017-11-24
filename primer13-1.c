/*
    修改程序清单13.1中的程序，使之不采用命令行参数，而是请求用户输入文件名并读入用户
的响应。
*/
/* count.c -- 使用标准I/O */
#include <stdio.h>

#include <stdlib.h>    //ANSI C的exit()原型
int main(int argc,char *argv[])
{
    int ch;    //读取时存储每个字符的位置
    FILE *fp;    //文件指针
    long count = 0;
    char name[30];

    printf("please input file name:");
    if(scanf("%s",name) != 1)    //请求用户输入文件名并读入用户的响应
    {
        printf("Error\n");
        exit(1);
    }

    if((fp = fopen(name,"r")) == NULL)
    {
        printf("Error\n");
        exit(2);
    }

    while((ch = getc(fp)) != EOF)
    {
        putc(ch,stdout);
        count++;
    }
    fclose(fp);
    printf("File %s has %ld characters\n",name,count);

    return 0;
}
