/* title:让程序要求用户输入一个大写字母，使用嵌套循环产生像下面金字塔图案。
    A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
这种图案要扩展到用户输入的字符。例如，前面的图案是在输入E时需要产生的。
提示：使用一个外部循环来处理行，在每一行中使用三个内部循环，一个处理
空格，一个以升序打印字母，一个以降序打印字母。如果您的系统不使用ASCII
或类似的以严格数字顺序表示字母的编码，请参见在编程练习3中给出的建议。
                                                          */
#include <stdio.h>

int main(void)
{
    char ch,ac;
    int i,j,k,y,cl;

    printf("Please enter a capital letter:");
    scanf("%c",&ch);
    cl = ch - 'A' +1;    //需要打印的行
    for(i = 1;i <= cl;i++)    //外部循环处理行
    {
        ac = 'A';
        for(j = cl;j >= i;j--)    //处理空格
            printf(" ");
        for(k = 0;k < i;k++)    //升序打印字母
             printf("%c",ac++);
        ac--;
        for(y = 1;y < i;y++)    //降序打印字母
            printf("%c",--ac);
        printf("\n");
    }
}
