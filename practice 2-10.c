/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c

练习2-10 重新编写将大写字母转换为小写字母的函数lower，并用条件表达式替代其中的
if-else结构。

个人部分：编写lower为：将字符串中大写字母转换为小写字母的函数。

例如：
字符串 s1: "aBcDefg"
输出值：   "abcdefg"
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/

#include <stdio.h>

void lower(char s[]);

int main()
{
    char s[100];
    int i = 0;
    char c;
    while((c = getchar()) != '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    lower(s);
    printf("%s\n",s);
    return 0;
}

void lower(char s[])
{
  int i = 0;
  while(s[i] != '\0')
  {
    (s[i] >= 'A' && s[i] <= 'Z') ? s[i] = s[i] + 'a' - 'A' :s[i] ;
    i++;
  }
}
