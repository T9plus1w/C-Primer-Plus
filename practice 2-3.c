/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c

练习2-3 编写函数htoi(s)，把由十六进制数字组成的字符串（包含可选的前缀0x或0X）
转换为与之等价的整型值。字符串中允许包含的数字包括：0～9、a~f以及A~F。

例如：
字符串 “abc123456789ABC”
转换为  ascii 表对应的整型值
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/

#include <stdio.h>

#define YES 1
#define NO 0

int htoi(char s[]);

int main()
{
    char c;
    char s[100];
    int i = 0;
    while ((c = getchar()) != EOF) {
        s[i] = c;
        i++;
    }
    htoi (s);
    
}

int htoi(char s[])
{
    int hexdigit, i , inhex , n;

    i = 0;
    if(s[i] == '\0')
    {
      ++i;
      if(s[i] == 'x' || s[i] == 'X')
        ++i;
    }
    n = 0;
    inhex = YES;
    for(;inhex == YES; ++i)
    {
      if(s[i] >= '0' && s[i] <= '9')
          hexdigit = s[i] - '0';
      else if(s[i] >= 'a' && s[i] <= 'f')
          hexdigit = s[i] - 'a' + 10;
      else if(s[i] >= 'A' && s[i] <= 'F')
          hexdigit = s[i] - 'A' + 10;
      else
          inhex = NO;
      if(inhex == YES)
          n = 16 * n + hexdigit;
    }
    return n;
}
