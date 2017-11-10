/*
    编写一个函数，其功能是使输入字符串反序。在一个使用循环语句为这个函数提供输入的完整
程序中进行测试。
*/
#include <stdio.h>

void reorder(char* str);

int main(void)
{
    char arr[50];
    printf("Please enter a line of characters：\n");
    gets(arr);
    reorder(arr);
    printf("reorder:\n");
    puts(arr);
}

/* 其功能是使输入字符串反序 */
void reorder(char* str)
{
    int n = 0;
    int i;
    char temp;
    char *p = str;
    while(*(p++) != '\0')
        n++;
    n--;
    for(i = 0; i < n;i++,n--)
    {
        temp = str[i];
        str[i] = str[n];
        str[n] = temp;
    }
}
