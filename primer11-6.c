/*
    strncpy(s1,s2,n)函数从s2复制n个字符给s1，并在必要时截断s2或为其填充额外的空字符。
如果s2的长度等于或大于n，目标字符串就没有标志结束的空字符。函数返回s1.自己编写这个函数，
并在一个使用循环语句为这个函数提供输入的完整程序中进行测试。
*/
#include <stdio.h>

char* mystrncpy(char* s1,char* s2,int n);

int main(void)
{
    /* 测试 */
    char s1[50],s2[50];

    gets(s1);
    gets(s2);

    mystrncpy(s1, s2,5);

    puts(s1);
}

/* 函数从s2复制n个字符给s1，并在必要时截断s2或为其填充额外的空字符。
如果s2的长度等于或大于n，目标字符串就没有标志结束的空字符。函数返回s1. */
char* mystrncpy(char* s1,char* s2,int n)
{
    char *p = s1;
    while(*s1++ != '\0')
        continue;

    *--s1 = *s2;
    n--;

    while(n>0 && *s2 != '\0')
    {
        *++s1 = *++s2;
        n--;
    }

    return p;
}
