/* title:编写一个程序读取输入，直到＃，并报告序列ei出现的次数。
    此程序必须要记住前一个字符和当前的字符。用诸如
    "Receive your eieio award."的输入测试它。           */
#include <stdio.h>

int main(void)
{
    char ch,prev;
    int n = 0;

    printf("please input characters:");
    while((ch = getchar()) != '#')
    {
        if((ch == 'i') && (prev == 'e'))    //当ei出现统计加1
        {
            n++;
            prev = ch;
        }
        prev = ch;    //记住前字符
    }
    printf("The number of characters “ei” appears is：%d\n",n);

    return 0;
}
