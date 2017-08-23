/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c

描述：
  atof(s) 该函数把字符串s转换为相应的双精度浮点数。atof函数是atoi函数的扩展。
功能：
  输入字符串
  “123.123”
  输出
  123.123
作者：
时间：08／23／17
版本：
程序组织结构：
  该函数可分为3部分：

  for(处理整数部分)
  for(处理小数部分)

  return 返回整数部分与整数部分的和（double型）
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/
#include <stdio.h>

#define MAX 1000    //字符数组上限
double atof(char s[]);

int main(){
  char s[MAX];
  char c;
  double val;
  int i = 0;

  //输入一个字符串
  while((c = getchar()) != '\n')
  {
    s[i] = c;
    i++;
  }
  s[i] = '\0';

  val = atof(s);    //将字符串转换浮点数
  printf("%f\n",val);    //结果打印
  return 0;
}

/* atof函数：把字符串s转换为相应的双精度浮点数*/
double atof(char s[])
{
  int i = 0;
  double n = 0.0;    //整数部分的和
  double k = 0.1;
  double val = 0.0;    //小数部分的和

  //将字符串整数部分进行转换
  while(s[i] != '\0' && s[i] != '.')
  {
    n = 10 * n + (s[i] - '0');
    i++;
  }
  
  //跳过小数点
  if(s[i] == '.')
  {
    i++;
  }
  
  //将字符串小数部分进行转换
  while(s[i] != '\0')
  {
    val =val + k*(s[i] - '0');
    k = 0.1 * k;
    i++;
  }
  
  return val+n;    //返回整数部分和小数部分的总和
}
