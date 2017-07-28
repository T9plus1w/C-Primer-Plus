／＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c 
练习1-12 编写一个程序，以每行一个单词的形式打印其输入。
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊／

#include <stdio.h>

#define IN 1   //在单词内
#define OUT 0  //在单词外

int main()
{
  int c,nl,nw,nc,state;

  nl = nw = nc = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' '||c == '\t'||c == '\n'){
      state = OUT;
      printf("\n");
    }
    else if (state == OUT) {
      state = IN;
      }
    if(state == IN)
      putchar(c);
  }
  return 0;
}
