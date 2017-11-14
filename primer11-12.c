/*
    编写一个程序，按照相反的单词顺序显示命令行参数。即，如果命令行参数是see you later，
程序的显示应该为later you see.
*/
#include <stdio.h>

void reword(char *str[],int n);

int main(int argc,char *argv[])
{
    int i;

    reword(argv,argc);

    //输出命令行参数
    for(i = 1;i < argc;i++)
    {
        printf("%s ",argv[i]);
    }
    printf("\n");

    return 0;
}

//按照相反的单词顺序重新排列
void reword(char *str[],int n)
{
    char *temp;
    int i,j;
    for(i = 1,j = n-1;i < (n/2);i++,j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
