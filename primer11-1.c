/*
title:
    设计并测试一个函数，可以从输入读取n个字符（包括空格、制表符和换行符），把结果存储在一
个数组中，这个数组的地址通过参数来传递。
*/
#include <stdio.h>

void input(char *str,int n);

int main(void)
{
    /* 测试 */
    char arr[50];
    int n;

    printf("Please enter n char:");
    scanf("%d",&n);
    while(getchar() != '\n')    //清空缓存
        ;
    input(arr,n);

    printf("%s\n",arr);
}

/* 从输入读取n个字符 */
void input(char *str,int n)
{
    int i;

    for(i = 0;i < n;i++)
    {
        str[i] = getchar();
    }
    str[n] = '\0';
}
