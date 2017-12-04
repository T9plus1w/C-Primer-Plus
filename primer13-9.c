/*
    修改程序清单13.3中的程序，从1开始，根据加入列表的顺序为每个单词编号。当再次运行
程序时，确保新的单词编号接着前面的编号开始。
*/
/* addaword.c -- 使用fprintf()、fscanf()、和rewind()函数 */
#include <stdio.h>
#include <stdlib.h>

#define MAX 40

int main(void)
{
    FILE *fp;
    char words[MAX];
    int i = 1;

    if((fp = fopen("words","a+")) == NULL)    //打开文件
    {
        fprintf(stdout, "Can't open \"wrods\" file.\n");
        exit(1);
    }

    puts("Enter words to add to the file;press the Enter");
    puts("key at the beginning of a line to terminate.");
    while(gets(words) != NULL && words[0] != '\0')    //在文件中写入字符
    {
        fprintf(fp,"%d:%s ",i++,words);
    }
    puts("File contents: ");
    rewind(fp);    //回到文件的开始处
    while(fscanf(fp,"%s",words) == 1)    //从文件读取字符流并打印
        puts(words);
    if(fclose(fp) != 0)
        fprintf(stderr, "Error closing file\n");

    return 0;
}
