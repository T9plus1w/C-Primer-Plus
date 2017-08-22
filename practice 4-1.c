/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c

描述：
  练习4-1  编写函数strrindex(s,t),它返回字符串t在s中最右边出现的位置。如果
  s中不包含t，则返回－1
功能：
  输入字符串
  “Ah love! could you and I with Fate conspire”
  输出
  9
作者：
时间：08／22／17
版本：
程序组织结构：
  该程序可分为3部分：

  while(还有未处理的行)
    if(该行包含指定的模式)
      打印位置
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/
#include <stdio.h>
#include <string.h>

#define MAX 1000    //最大输入行长度

int getlin(char s[],int lim);
int strrindex(char source[],char searchfor[]);

char pattern[] = "ould";    //待查找的模式
int main(void)
{
  int k;
  char s[MAX];     //存储字符串

  while(getlin(s,45) > 0)  //获得字符串，判断字符串不为空
  {
    if((k=strrindex(s,pattern)) >= 0)    //判断字符串中是否有模式中的符号，如有进行打印
    {
      k = k-strlen(pattern) - 1;
      printf("%d\n",k);
    }
    else
    {
      printf("%d\n",-1);
    }

  }
  return 0;
}

//获取字符串函数
int getlin(char s[],int lim)
{
  int i = 0;
  char c;
  while(--lim > 0 && (c = getchar()) != EOF &&  c != '\n')//将获取的字符放入字符数组
  {
    s[i] = c;
    i++;
  }
  if(c == '\n')    //换行符结尾，给字符数组输入换行符
    s[i++] = '\n';
  s[i] = '\0';    //以'\0'结尾
  return i;  //返回字符数组个数
}

//判断字符串中是否有模式中的符号
int strrindex(char source[],char searchfor[])
{
  int i,j,k;
  for(i = 0; source[i] != '\0';i++)  //遍历字符数组
  {
    //判断字符串中是否有模式中的符号
    for(j = i,k = 0;searchfor[k] != '\0' && source[j] == searchfor[k];j++,k++)
        ;
    //有的话返回正数
    if(k > 0 && searchfor[k] == '\0')
      return j;
  }
  //否则返回－1
  return -1;
}
