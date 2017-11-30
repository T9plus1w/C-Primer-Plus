/*
  使用命令行参数的程序要求用户记住正确的方法。重写程序清单13.2中的程序，不使用命令行
参数，而是提示用户键入所需的信息。
*/
/* 简单压缩算法 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(void)
{
    FILE *in,*out;
    int ch;
    char name[LEN];
    int count = 0;

    char file_app[LEN],file_src[LEN];

    puts("Enter name of read file: ");
    gets(file_app);
    puts("Enter name of write file: ");
    gets(file_src);
    if((in = fopen(file_app,"r")) == NULL)    //打开读文件
    {
        fprintf(stderr,"I couldn't open the file \"%s\"\n",file_app);
        exit(2);
    }

    //实现输出
    strcpy(name,file_app);    //把文件名复制到数组中
    strcat(name,".red");    //在文件名后添加.red
    if((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(3);
    }

    //复制数据
    while((ch = getc(in)) != EOF)
        if(count++ % 3 == 0)
            putc(ch,out);

    //收尾工作
    if(fclose(in) != 0 || fclose(out) != 0)
        fprintf(stderr, "Error in closing files\n");

    return 0;
}
