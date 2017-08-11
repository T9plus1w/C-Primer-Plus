/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c

练习3-2 编写一个函数escape(s,t)，将字符串s复制到字符串t中，并在复制过程中将换
行符、制表符等不可见字符分别转换为\n、\t等相应的可见的转义字符序列。要求使用switch
语句。再编写一个具有相反功能的函数，在复制过程中将转义字符序列转换为实际字符。

例如：
字符串 s "abcdefg##**aba" (#号代表换行符，＊号代表制表符)
复制到
字符串 t "abcdefg\n\n\t\taba"
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/

#include <stdio.h>

void escape(char s[],char t[]);

int main()
{
    char s[100];
    char t[100];
    int i = 0;
    char c;
    while((c = getchar()) != EOF)
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    escape(s,t);
    printf("%s\n",t);
    return 0;
}

void escape(char s[],char t[])
{
    int i,j;
    i = 0;
    j = 0;

    while(s[i] != '\0')
    {
        if((s[i] >= 'a' && s[i] <= 'z') ||(s[i] >= 'A' && s[i] <= 'Z')
        ||(s[i] >= '0' && s[i] <= '9'))
        {
            t[j++] = s[i];
        }
        else
        {
        switch(s[i])
        {
          case '\n':
            t[j++] = '\\';
            t[j++] = 'n';
            break;
          case '\t':
            t[j++] = '\\';
            t[j++] = 't';
            break;
          default:
            break;
        }
        }
        i++;
    }
}
