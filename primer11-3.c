/*
    设计并测试一个函数，其功能是读取输入行里的第一个单词到数组，并丢掉该行中其他的字符。
一个单词的定义是一串字符，其中不含空格、制表符和换行符。
*/
#include <stdio.h>

void word(char *str);

int main(void)
{
    /* 测试 */
    char arr[50];
    printf("Please input a string:\n");

    gets(arr);
    word(arr);
    puts(arr);
}

/* 读取输入行里的第一个单词到数组，并丢掉该行中其他的字符 */
void word(char *str)
{
    int i,j;
    for(i = 0;str[i] != '\0';i++)
    {
        if(str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
    }
    
    for(j = i+1;str[j] != '\0';j++)
    {
        str[j] = '\0';
    }
}
