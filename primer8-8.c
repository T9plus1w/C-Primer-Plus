/*
title:
  编写一个程序，显示一个菜单，为您提供加法、减法、乘法或除法的选项。获得您的选择后，该程
序请求两个数，然后执行您选择的操作。该程序应该只接受它所提供的菜单选项。它应该使用float
类型的数，并且如果用户未能输入数字应允许其重新输入。在除法的情况中，如果用户输入O作为第二个数，
该程序应该提示用户输入一个新的值。一个典型的程序运行应该如下所示：
Enter the operation of your choice:
 a. add       s. subtract
 m. multiply   d. divide
 q. quic
 Enter first number: 22.4
 Enter second number: one one is not an number.
 Please enter a number, such as 2.5. -1.78E8, or 3. 1 22.4 + 1 = 23.4
 Enter the operation of your choice:
 a. add        s. subtract
 m. multiply   d. divide
 q. quit
 Enter first number: 18.4
*/
#include <stdio.h>

int main(void)
{
    char a;
    float number1,number2,result;

    while(1)
    {
        //打印菜单并输入两个数
        printf("                menu               \n");
        printf("a.add                    s.subtract\n");
        printf("m.multiply               d.divide  \n");
        printf("q.quit                             \n");
        printf("please input number1 = ");
        scanf("%f",&number1);
        printf("please input number2 = ");
        scanf("%f",&number2);

        //清空缓存
        while(getchar() != '\n')
            continue;

        //选择需要的运算并计算结果输出
        printf("please input a,s,m,d,q:");
        a = getchar();
        switch(a)
        {
          case 'a':
                result = number1+number2;    //加法运算
                printf("number1 + number2 = %.2f\n",result);
                break;
          case 's':
                result = number1-number2;    //减法运算
                printf("number1 - number2 = %.2f \n",result);
                break;
          case 'm':
                result = number1*number2;    //乘法运算
                printf("number1 * number2 = %.2f \n",result);
                break;
          case 'd':
                if(number2 == 0)    //被除数为0请重新输入
                {
                    printf("The dividend cannot be 0\n");
                    printf("Please re-enter it\n");
                    break;
                }
                else    //除法运算
                {
                  result = number1/number2;
                  printf("number1 / number2 = %.2f \n",result);
                  break;
                }

          case 'q':
                printf("Bye!\n");
                return 0;
          default:
                printf("You input error!\n");
                return 104;
        }

        getchar();
        getchar();

    }

    return 0;
}
