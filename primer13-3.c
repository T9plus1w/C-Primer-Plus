/*
    编写一个文件复制程序，提示用户输入源文件名和输出文件名。在向输出文件写入时，程序应当
使用ctype.h中定义的toupper()函数将所有的文本转换成大写。使用标准I/O和文本模式。
*/
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{
    char name1[30],name2[30];
    char ch;
    FILE *source,*destination;    //文件指针

    printf("Please input name1:");    //获取文件名
    scanf("%s",name1);
    printf("Please input name2:");
    scanf("%s",name2);

    if((source = fopen(name1,"rb")) == NULL)
    {
        printf("Can't open %s\n",name1);
        exit(1);
    }
    if((destination = fopen(name2,"wb")) == NULL)
    {
        printf("Can't open %s\n",name2);
        exit(1);
    }
    while((ch = getc(source)) != EOF)    //复制文件
    {
        putc(ch,destination);
    }

    fclose(source);
    fclose(destination);
    printf("Copy finshed!\n");

    return 0;
}
