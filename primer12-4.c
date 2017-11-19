/*
    编写一个函数，它返回函数自身被调用的次数，并在一个循环中测试之。
*/
#include <stdio.h>

static int num = 0;

int f(void);

int main(void)
{
    int i,n;
    printf("Please input number:");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        f();
    }
    printf("%d\n",num);
    return 0;
}

/* 返回函数自身被调用的次数 */
int f(void)
{
    extern int num;
    num++;
    return num;
}
