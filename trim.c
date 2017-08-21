/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c

范例  函数trim用于删除字符串尾部的空格符、制表符与换行符。当发现最右边的字符为非
空格符、非制表符、非换行符时，就使用break语句从循环中退出。

如：
  输入字符串“abccba ”
  输出字符串“abccba*”    //用＊号进行标记

＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/

#include <stdio.h>
#include <string.h>

int trim(char s[]);

int main(void){
    char s[100];
    char c;
    int i = 0;
    while((c = getchar()) != '\n')  //获取字符串
    {
        s[i] = c;
        i++;
    }
    trim(s);    //
    printf("%s\n",s);
}

/* 删除字符串尾部的空格符、制表符与换行符*/
int trim(char s[])
{
  int n;

  for(n = strlen(s)-1;n>=0;n--)
  {
    if(s[n] != ' '&&s[n] != '\t'&&s[n] != '\n')  //遇到空格符、制表符、换行符跳出循环
        break;
  }
  s[n+1] = '*';   //用＊号进行实验标记 
  s[n+2] = '\0';
  return n;
}
