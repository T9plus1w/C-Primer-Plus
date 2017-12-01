/*
  编写一个打开两个文件的程序。可以使用命令行参数或者请求用户输入来获得文件名。
a.让程序打印第一个文件的第一行、第二个文件的第一行、第一个文件的第二行、第二个
文件的第二行，依此类推，知道打印完行数较多的文件的最后一行。
b.修改程序，把行号相同的行打印到同一行上。
*/
#include <stdio.h>
#include <stdlib.h>

#define LEN 40
#define M 100
int main(void)
{
    FILE *fp1,*fp2;
    char file_app[LEN],file_src[LEN];
    char str1[M],str2[M];
    int E1,E2;

    puts("Enter name of read file: ");
    gets(file_app);
    puts("Enter name of write file: ");
    gets(file_src);
    if((fp1 = fopen(file_app,"r")) == NULL)    //打开读文件
    {
        fprintf(stderr,"I couldn't open the file \"%s\"\n",file_app);
        exit(1);
    }
    if((fp2 = fopen(file_src,"r")) == NULL)    //打开读文件
    {
        fprintf(stderr,"I couldn't open the file \"%s\"\n",file_src);
        exit(1);
    }

    while(1)
    {
        if((E1 = fscanf(fp1,"%s",str1)) == 1)    //使用fscanf读取字符串
            puts(str1);
        if((E2 = fscanf(fp2,"%s",str2)) == 1)
            puts(str2);
        if(E1 != 1 && E2 != 1)
            break;
    }

    fclose(fp1);
    fclose(fp2);

    return 0;
}
