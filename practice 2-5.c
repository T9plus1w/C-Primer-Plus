/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c

练习2-5 编写函数any(s1,s2),将字符串s2中的任一字符在s1中第一次出现的位置作为
结果返回。如果s1中不包含s2中的字符，则返回－1.（标准库函数strpbrk具有同样的功
能，但它返回的是指向该位置的指针。）

例如：
字符串 s1: "abcde"
字符串 s2: "daade"
输出值：4
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/

#include <stdio.h>

int any(char s1[],char s2[]);

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
    printf("%d\n",any(s1,s2));

    return 0;
}

int any(char s1[],char s2[])
{
    int i;

    for(i = 0;s1[i] != '\0';i++)
    {
      if(s1[i] == s2[i])
      {
        i++;
        return i;
      }
    }
    return -1;
}
