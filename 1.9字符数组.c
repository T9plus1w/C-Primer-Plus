//该程序读入一组文本行，并把最长的文本行打印出来

#include <stdio.h>
#define MAXLIN 1000  //允许的输入行的最大长度

int getlin(char line[],int maxline);
void copy(char to[],char from[]);

int main(){
  int len;
  int max;
  char line[MAXLIN];
  char longest[MAXLIN];
  
  while((len = getlin(line,MAXLIN)) > 0)
  {
      if(len > max)
      {
        max = len;
        copy(longest, line);
      }  
  }
  if (max > 0)
      printf("%s\n",longest);
  return 0;
}

//getlin函数：将一行读入到s中并返回其长度
int getlin(char line[],int maxline)
{
    int c,i;

    for(i = 0;i < maxline - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }
    if (c == '\n') {
      line[i] = c;
      ++i;
    }
    line[i] = '\0';
    return i;
}

//copy函数：将from复制到to；这里假定to足够大
void copy(char to[],char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
      ++i;
    }
}


