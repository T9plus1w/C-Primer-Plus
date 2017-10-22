/*
title:
1988年United States Federal Tax Schedule是近期最基本的。它分为4类，每类有两个等级。
下面是其摘要；美元数为应征税的收入。
┏━━━━━━┳━━━━━━━━━━━━━━━━━━┓
┃    种  类        ┃    税  金
┃ ┣━━━━━━╋━━━━━━━━━━━━━━━━━━┫
┃    单身          ┃前17·850美元按15%，超出部分按28%┃
┣━━━━━━╋━━━━━━━━━━━━━━━━━━┫
┃    户主          ┃前23，900美元按15%，超出部分按28%┃
┣━━━━━━╋━━━━━━━━━━━━━━━━━━┫
┃已婚，共有         ┃前29，750美元按15%，超出部分按28%┃
┣━━━━━━╋━━━━━━━━━━━━━━━━━━┫
┃已婚，离异         ┃前14，875美元按l5%，超出部分按28%┃
┗━━━━━━┻━━━━━━━━━━━━━━━━━━┛
例如，有20 000美元应征税收入的单身雇佣劳动者应缴税金
0.15×17 850美元+0.28×（20 000美元-17 850美元）。
编写一个程序，让用户指定税金种类和应征税收入，然后计算税金。使用循环以便用户可以多次输入。
*/

#include <stdio.h>
/* 一个简单的菜单程序（计算税金） */
int main(void)
{
    int wages,tax,a;

    while(1)
    {
        //菜单程序界面
        printf("                tax        \n");
        printf("1、Single            2、Householder   \n");
        printf("3、Married shared    4、Married divorled\n");
        printf("5、quit\n");
        printf("please input wages:");
        scanf("%d",&wages);
        printf("please input 1~4(5 quit):");
        scanf("%d",&a);

        //处理4种税金计算
        switch(a)
        {
          case 1:
                tax = 0.15*17850+0.28*(wages-17850);
                break;
          case 2:
                tax = 0.15*23900+0.28*(wages-23900);
                break;
          case 3:
                tax = 0.15*29750+0.28*(wages-29750);
                break;
          case 4:
                tax = 0.15*14875+0.28*(wages-14875);
                break;
          case 5:
                printf("Bye!\n");
                return 0;
          default:
                printf("You input error!\n");
                break;
        }
        printf("Taxes should be levied as:%d\n",tax);


        getchar();
        getchar();
    }
    return 0;
}
