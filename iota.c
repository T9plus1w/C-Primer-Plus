/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c

范例：
itoa函数是atoi函数的逆函数，它把数字转换为字符串。

如：
  把整数123 转换成 字符串“123”
  
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/

#include <stdio.h>

void itoa(int n,char s[]);

int main(void){
    char s[100];
    int n;
    scanf("%d\n",&n);
    itoa(n,s);    //将整数转换为字符串
    printf("%s\n",s);
}

void itoa(int n,char s[])
{
  int i = 0;
  int number;

  if((number = n) < 0)  //记录符号，使n成为正数
  {
      n = -n;
  }
  while(n)    //以反序生成数字字符串
  {
      s[i] = n % 10 + '0';  //数字转换为字符，存入s
      n = n / 10;    //下一个数字
      i++;
  }
  if(number < 0)    //n为负数添加负号
  {
    s[i] = '-';
    i++;
  }
  s[i] = '\0';
  i = i - 1;
  int len,j = 0;
  char temp;
  len = i/2;
  while(i > len)    //倒置反序字符串
  {
      temp = s[i];
      s[i] = s[j];
      s[j] = temp;
      i--;
      j++;
  }

}
