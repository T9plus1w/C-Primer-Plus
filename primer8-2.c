/*
title:
  编写一个程序，把输入作为字符流读取，直到遇到EOF。令该程序打印每个输入字符及其ASCII
编码的十进制值。注意在ASCII序列中空格字符前面的字符是非打印字符，要特殊处理这些字符。
如果非打印字符是换行符或制表符，则分别打印\n或\t。否则，使用控制字符符号。例如，ASCII
的1是Ctrl+A，可以显示^A。注意A的ASCII值是Ctrl+A的值加64。对其他非打印字符也保持相似
的关系。除去每次遇到一个换行符时就开始一个新行之外，每行打印10对值。
*/

#include <stdio.h>

int main(void)
{
    char ch;
    int nl = 0;    //统计一行内的字符


    while((ch = getchar()) != EOF)
    {
        ++nl;

        /* 每行打印10对值 */
        if(nl % 11 == 0)
        {
            putchar('\n');
            nl = 0;
        }

        if(ch == '\n')    //遇换行符开始一个新行
        {
              printf("\n");
              nl = 0;
        }
        else if(ch >= 0 && ch < 32)    //输出控制字符
        {
            if(ch == '\n')
            {
                putchar('\\');
                putchar('t');
            }
            else if(ch == '\t')
            {
                putchar('\\');
                putchar('t');
            }
            else
                printf("%c",ch+64);
        }
        else    //输出字符及十进制值
            printf("%c%d ",ch,ch);
    }
}
