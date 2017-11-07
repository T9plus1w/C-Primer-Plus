/*
    修改并测试练习1中的函数，使得可以在n个字符后，或第一个空格、制表符、换行
符后停止读取输入，由上述情况中最先被满足的那个终止读取（不能用scanf()函数）
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

/* 从输入读取n个字符或第一个空格、制表符、换行
符后停止读取输入 */
void input(char *str,int n)
{
    int i;
    char ch;

    for(i = 0;i < n && (ch = getchar())!= ' '&& ch!='\t'&&ch!='\n';i++)
    {
        str[i] = ch;
    }
    str[i] = '\0';
}
