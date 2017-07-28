//统计行，统计单词数，统计字符数
#include <stdio.h>

#define IN 1
#define OUT 0

int main()
{
  int c,nl,nw,nc,state;

  nl = nw = nc = 0;
  state = OUT;
  while ((c = getchar()) != EOF) {
    nc++;
    if (c == '\n')
      ++nl;
    if (c == ' '||c == '\t'||c == '\n')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
      }
  }
  printf("单词数＝%d 字符数＝%d 行数＝%d\n",nw,nc,nl);
  return 0;
}
