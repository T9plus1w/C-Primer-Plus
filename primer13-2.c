/*
    编写一个文件复制程序。程序需要从命令行获得源文件名和目的文件名。尽可能使用标准I/O
和二进制模式。
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
    int ch;
    FILE *source,*destination;    //文件指针

    if((source = fopen(argv[1],"rb")) == NULL)    //打开读取文件
    {
        printf("Can't open %s\n",argv[1]);
        exit(1);
    }
    if((destination = fopen(argv[2],"wb")) == NULL)    //打开写入文件
    {
        printf("Can't open %s\n",argv[2]);
        exit(1);
    }

    while((ch = getc(source)) != EOF)    //复制文件
        putc(ch,destination);
        
    fclose(source);    //关闭文件
    fclose(destination);
    printf("copy finished\n");

    return 0;
}
