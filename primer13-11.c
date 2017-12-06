/*
    编写一个程序，接受两个命令行参数。第一个参数为一个字符串；第二个为文件名。程序
打印文件中包含该字符串的所有行。因为这一任务是面向行而不是面向字符的，所以要使用
fgets()而不是getc()。使用标准c库函数strstr()(在第11章的练习7中简要描述过)在
每一行中搜索这一字符串。
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 81
int main(int argc, char const *argv[])
{
    FILE *fp;
    char line[MAX];

    if(argc != 3)    //判断命令行参数为3个
    {
        fprintf(stderr, "error\n");
        exit(1);
    }

    if((fp = fopen(argv[2],"r")) == NULL)    //打开文件
    {
        fprintf(stderr, "Can't open %s\n",argv[2]);
        exit(1);
    }

    //获取字符串行
    while(fgets(line,MAX,fp) != NULL && line[0] != '\n')
    {
        if(strstr(line,argv[1]) != NULL)    //字符串中存在参数字符串则打印
            fputs(line,stdout);
    }

    return 0;
}
