//将数字转换为二进制形式

#include <stdio.h>

#define MAX 40
char *itobs(int,char *);
void show_bstr(const char *);

int main(void)
{
    int n;
    char title[8*sizeof(int)+1];

    printf("Please input a intger:");
    scanf("%d",&n);

    itobs(n,title);    //将数字转换为二进制形式，存储进字符串中
    printf("%d is",n);
    show_bstr(title);    //打印字符串

    return 0;
}

//将数字转换为二进制形式，存储进字符串中
char *itobs(int n,char *title)
{
    int i;
    static int size = 8 * sizeof(int);

    for(i = size-1; i >= 0; i--,n >>= 1)
    {
        title[i] = (01&n) + '0';
    }
    title[size] = '\0';

    return title;
}

//打印字符串
void show_bstr(const char *str)
{
    int i = 0;
    while(str[i])
    {
        putchar(str[i]);
        if(++i % 4 == 0 && str[i])    //每4位打印空格
            putchar(' ');
    }
}
