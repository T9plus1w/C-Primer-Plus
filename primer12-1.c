/*
    不使用全局变量，重写程序清单12.4中的程序。
*/
#include <stdio.h>

void critic(int *units);

int main(void)
{
    int units;
    int *p;
    p = &units;    //使用指针代替全局变量

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d",&units);
    while(units != 56)
        critic(p);    //传入指针

    printf("You must have looked it up!\n");
    return 0;
}

void critic(int *units)
{
    printf("No luck,chummy.Try again.\n");
    scanf("%d",units);

}
