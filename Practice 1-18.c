／＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c 
练习1-18 编写一个程序，删除每个输入行末尾的空格及制表符，并删除完全是空格的行。
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊／


#include <stdio.h>
#define MAXLIN 1000  //允许的输入行的最大长度

int getlin(char line[],int maxline);
int rmove(char s[]);

int main(){
  int len;
  char line[MAXLIN];
  

  while((len = getlin(line,MAXLIN)) > 0)
  {
      if(rmove(line) > 0)
        printf("%s\n",line);
  }

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

//删除末尾空格以及制表符，并返回其长度
int rmove(char s[])
{
    int i = 0;
    while(s[i] != '\n')
    {
      ++i;
    }
    --i;
    while(i >= 0 && (s[i] ==' '|| s[i] == '\t')){
      --i;
    }
    if(i > 0)
    {
      ++i;
      s[i] ='\n';
      ++i;
      s[i] ='\0';
    }
    return i;
}
