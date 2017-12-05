/*
    编写一个程序，打开一个文本文件，文件名通过交互方式获得。建立一个循环，请求用户输入
一个文件位置。然后程序打印文件中从该位置开始到下一个换行符之间的部分。用户通过输入非数字
字符来终止输入循环。
*/
#include <stdio.h>
#include <stdlib.h>

#define LEN 40
#define MAX 81
int main(void)
{
    FILE *fp;
    char file_app[LEN],ch;
    int row;

    puts("Enter name of read file: ");
    gets(file_app);
    if((fp = fopen(file_app,"r")) == NULL)    //打开一个文件
    {
        fprintf(stderr, "Can't open %s\n",file_app);
        exit(1);
    }

    printf("input the row(input the number quik):");

    while(scanf("%d",&row) == 1)    //获取一个数字
    {
        fseek(fp,row,SEEK_SET);    //定位文件的位置
        while((ch = getc(fp)) != '\n')
        {
            putchar(ch);
        }
        printf("\n");
        printf("input the row(input the number quik):");
    }
}
