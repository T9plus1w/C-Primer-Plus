/*
    编写一个函数。其参数为一个字符串，函数删除字符串中的空格。在一个可以循环读取的程序中进行
测试，直到用户输入空行。对于任何输入字符串，函数都应该适用并可以显示结果。
*/
#include <stdio.h>

void respaces(char* str);
int main(void)
{
    char arr[50];
    printf("Please enter a line of characters：\n");
    gets(arr);
    respaces(arr);
    puts(arr);
}

/* 函数删除字符串中的空格 */
void respaces(char* str)
{
    int i,j,p;
    for(i = 0;str[i] != '\0';i++)
    {
        if(str[i] == ' ')
        {
            p = i;
            for(j = 1;str[p] != '\0';j++)
            {
                //字符串数组前进一位
                str[p] = str[i+j];
                p++;
            }
            i++;
        }
    }
}
