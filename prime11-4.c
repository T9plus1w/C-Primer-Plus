/*
    设计并测试一个函数，其功能是搜索由函数的第一个参数指定的字符串，在其中查找由函数的
第二个参数指定的字符的第一次出现的位置。如果找到，返回指向这个字符的指针；如果没有找到，
返回空字符（这种方式和strchr()函数的功能一样）。在一个使用循环语句为这个函数提供输入
的完整程序中进行测试。
*/
#include <stdio.h>

char* strchrArr(char *str,char ch);

int main(void)
{
    /* 测试 */
    char arr[50];
    char ch;
    char *pt;
    printf("please input a line char:\n");
    gets(arr);
    printf("please input a char:");
    ch = getchar();

    pt = strchrArr(arr,ch);
    if(pt == NULL)
        printf("Not found!\n");
    else
        printf("find = %c\n",*pt);

    return 0;
}

/* 搜索由函数的第一个参数指定的字符串，在其中查找由函数的
第二个参数指定的字符的第一次出现的位置 */
char* strchrArr(char *str,char ch)
{
    while(*str != ch && *str != '\0')
        str++;

    if(*str == '\0')
        return NULL;
    else
        return str;
}
