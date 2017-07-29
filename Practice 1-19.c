
#include <stdio.h>
#define MAXLIN 1000  //允许的输入行的最大长度

int getlin(char line[],int maxline);

void reverse(char s[]);

int main(){
  char line[MAXLIN];

  while((getlin(line,MAXLIN)) > 0)
  {
      reverse(line);
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
//reverse 将字符数组顺序颠倒
void reverse(char s[])
{
    int i = 0;
    int j = 0;
    char temp;

    while(s[i] != '\0')
    {
      ++i;
    }
    --i;
    if(s[i] == '\n')
    {
      --i;
    }

    while (j < i)
    {
      temp = s[j];
      s[j] = s[i];
      s[i] = temp;
      ++j;
      --i;
    }
}
