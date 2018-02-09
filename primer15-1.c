/*
  编写一个将二进制字符串转化为数字值的函数。也就是说，如果您有以下语句：
    char * pbin = "01001001";
  那么您可以将pbin作为一个参数传送给该函数，使该函数返回一个int值.
*/
#include <stdio.h>
#include <math.h>

int parseInt(char *str);
int main(void)
{
  int number;
  char * pbin = "01001001";

  number = parseInt(pbin);
  printf("%d\n",number);

  return 0;
}

//字符串转换为int整数
int parseInt(char *str)
{
    int number = 0,i ,n =0;
    while(str[n] != '\0')
        n++;
    for(i=n-1; i >= 0; i--)
    {
        number = number + (str[i] - '0') * pow(2,n-1-i);
    }

    return number;
}
