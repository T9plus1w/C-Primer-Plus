/*
title:
  编写一个程序，把输入作为字符流读取，直至遇到EOF。令其报告每个单词的平均字母数。不要
将空白符记为单词中的字母。实际上，标点符号也不应该计算，但现在不必考虑这一点（如果您想
做得好一些，可以考虑使用 ctype.h 系列中的 ispunct() 函数）。
*/
#include <stdio.h>

int main(void)
{
    char ch;
    int nw = 0;
    int flag = 0;
    int wordCount = 0;

    while((ch = getchar()) != EOF)
    {
        if(ch != ' ' && ch != '\n')    //不为空字符加1
            nw++;

        if(((ch >= 'A' && ch <= 'Z')||(ch >= 'a' && ch <= 'z'))    //标记单词
        && !flag)
        {
            flag = 1;
            wordCount++;
        }
        if(ch == ' '||ch == '\n'||ch == '\t')    //跳出单词标记清零
        {
            flag = 0;
        }
    }

    printf("The average number of word:%d\n",nw/wordCount);

    return 0;
}
