／＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c 
练习1-9 编写一个将输入复制到输出到程序，并将其中连续到多个空格用一个空格代替。
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊／

#include <stdio.h>

int main()
{
  int c,lastc;
  lastc = 'a';
  while ((c=getchar()) != EOF) {
      if (c != ' ') {
        putchar(c);
      }
      if(c ==' ' && lastc != ' ')
        putchar(c);
      lastc = c;
  }
  return 0;
}
