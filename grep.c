/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c

描述：
（范例）
  程序将输入中包含特定“模式”或字符串的各行打印出来（这是UNIX程序grep的特例）。
  例如，在下列一组问本行中查找包含字符串“ould”的行。
功能：
  输入字符串
  “Ah love! could you and I with Fate conspire
  To grasp this sorry Scheme of Things entire,
  Would not we shatter it to bits -- and then
  Re-mould it nearer to the Heart's Desire!”
  输出字符串
  “Ah love! could you and I with Fate conspire
  Would not we shatter it to bits -- and then
  Re-mould it nearer to the Heart's Desire!”
作者：
时间：08／22／17
版本：
程序组织结构：
  该程序可分为3部分：

  while(还有未处理的行)
    if(该行包含指定的模式)
      打印该行
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/
#include <stdio.h>

#define MAX 1000    //最大输入行长度

int getlin(char s[],int lim);
int strindex(char source[],char searchfor[]);

char pattern[] = "ould";    //待查找的模式
int main(void)
{
  char s[MAX];     //存储字符串

  while(getlin(s,45) > 0)  //获得字符串，判断字符串不为空
  {
    if(strindex(s,pattern) >= 0)    //判断字符串中是否有模式中的符号，如有进行打印
      printf("%s\n",s);
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
int strindex(char source[],char searchfor[])
{
  int i,j,k;
  for(i = 0; source[i] != '\0';i++)  //遍历字符数组
  {
    //判断字符串中是否有模式中的符号
    for(j = i,k = 0;searchfor[k] != '\0' && source[j] == searchfor[k];j++,k++)
      ;
    //有的话返回正数
    if(k > 0 && searchfor[k] == '\0')
      return i;
  }
  //否则返回－1
  return -1;
}
