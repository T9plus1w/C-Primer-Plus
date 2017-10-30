/*
  编写一个程序，使其从标准输入读取字符，直到遇到文件结尾。对于每个字符，程序需要
检查并报告该字符是否是一个字母。如果是的话，程序还应报告该字母在字母表中的数值位置。
例如，c和C的字母位置都是3。可以先实现这样一个函数:接受一个字符参数，如果该字符为
字母则返回该字母的数值位置，否则返回－1.
*/
#include <stdio.h>

int isAlph(char ch);

int main(void)
{
    char ch;
    int al;
    printf("please input a char:");
    ch = getchar();

    al = isAlph(ch);
    if(al != -1)
        printf("char = %c Letter position is:%d\n",ch,al);
    else
        printf("error!\n");

}

/* ch为字母则返回该字母的数值位置，否则返回－1*/
int isAlph(char ch)
{
    int n;

    if(ch >= 'a' && ch <= 'z')    //处理小写字母
    {
        n = ch - 'a' + 1;    //计算在字表表中的位置
        return n;
    }
    else if(ch >= 'A' && ch <= 'Z')    //处理大写字母
    {
        n = ch - 'A' + 1;
        return n;
    }
    else
        return -1;    //否则返回－1
}
