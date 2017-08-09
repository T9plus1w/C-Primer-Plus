/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c

练习2-4 重新编写函数squeeze(s1,s2),将字符串s1中任何与字符串s2中字符匹配的字符
都删除。

例如：
字符串 s1: "abcde"
字符串 s2: "abdec"
转换为  "dec"
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/

#include <stdio.h>

void squeeze(char s1[],char s2[]);

int main()
{
    char s1[100];
    char s2[100];
    int i = 0;
    char c;
    while((c = getchar()) != '\n' && i < 100)
    {
        s1[i] = c;
        i++;
    }
    i = 0;
    while((c = getchar()) != '\n' && i < 100)
    {
        s2[i] = c;
        i++;
    }
    squeeze(s1,s2);
    printf("%s\n",s1);

    return 0;
}

void squeeze(char s1[],char s2[])
{
    int i,j;

    for(i = j = 0;s1[i] != '\0';i++)
    {
      if(s1[i] != s2[i])
      {
        s1[j++] = s1[i];
      }
    }
    s1[j] = '\0';
}
