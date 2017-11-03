//这个文件包含两个c程序，做为存储类的讲解例程。

//parta.c ---各种存储类
#include <stdio.h>

void report_count();    //函数原型声明
void accumulate(int k);    //函数原型声明，函数原型作用域
int count = 0;    //静态类型，文件作用域，外部链接   这里为定义

int main(void)
{
    int value;    //自动，代码块，空链接    这里为定义
    register int i;    //自动，代码块，空链接，寄存器，不能访问地址

    printf("Enter a positive integer(0 to quit): ");
    while(scanf("%d",&value) == 1 && value > 0)
    {
        ++count;
        for(i = value; i >= 0;i--)
            accumulate(i);
        printf("Enter a positive integer (0 to quit): ");
    }

    report_count();

    return 0;
}

void report_count()
{
    printf("Loop executed %d times\n",count);
}


//partb.c --程序的其余部分
#include <stdio.h>

extern int count;    //静态类型，文件作用域，外部链接   这里为声明

static int total = 0;    //静态类型，文件作用域，内部链接  这里进行声明初始化

void accumulate(int k);

void accumulate(int k)
{
    static int subtotal = 0;    //静态类型，代码块作用域，空链接  这里进行声明初始化

    if(k <= 0)
    {
        printf("Loop cycle: %d\n",count);
        printf("Subtotal: %d;total: %d\n",subtotal,total);
        subtotal = 0;
    }
    else
    {
        subtotal += k;
        total += k;
    }
}
