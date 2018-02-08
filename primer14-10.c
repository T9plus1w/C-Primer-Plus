/*
  编写一个程序，用指向函数的指针数组执行菜单。例如，在菜单中选择a会激活由数组第一个元素指向
的函数。
*/
#include <stdio.h>

void showmenu(void);
int sub(int a,int b);
int add(int a,int b);
int div(int a,int b);
int mult(int a,int b);

int main(void)
{
    char c;
    char n;
    //声明指向函数的指针数组
    int(*pfun[4])(int,int) = {sub,add,div,mult};

    showmenu();
    printf("please enter a~d(q to quit)\n");

    while(1)
    {
        c = getchar();
        while((n = getchar()) != '\n' && n != EOF)
            continue;
        switch(c)
        {
            case 'a':
                pfun[0](3,3);
                break;
            case 'b':
                pfun[1](3,3);
                break;
            case 'c':
                pfun[2](3,3);
                break;
            case 'd':
                pfun[3](3,3);
                break;
            case 'q':
                return 1;
            default:
                showmenu();
                printf("please enter a~d(q to quit)\n");
        }
        showmenu();
        printf("please enter a~d(q to quit)\n");
    }

    return 0;
}

//显示菜单函数
void showmenu()
{
    printf("To choose a function\n");
    printf("a.sub\n");
    printf("b.add\n");
    printf("c.div\n");
    printf("d.mult\n");
    printf("q.Quit\n");
}

int sub(int a,int b)
{
    printf("sub = %d\n",a-b);
    return 0;
}

int add(int a,int b)
{
    printf("add = %d\n",a+b);
    return 0;
}

int div(int a,int b)
{
    if(b != 0)
        printf("div = %d\n",a/b);
    return 0;
}

int mult(int a,int b)
{
    printf("mult = %d\n",a*b);
    return 0;
}
