/*
  编写一个程序，该程序用命令行参数读取两个二进制字符串，并打印对每个数使用～运算符的结果，
以及对这两个数使用& | 和 ^ 运算符的结果。使用二进制字符串形式显示结果。
*/
#include <stdio.h>
#include <math.h>

int parseInt(char *str);
char * itobs(int n,char *);
void show_bstr(const char *);

int main(int argc,char *argv[])
{
  int n1;
  int n2;
  int temp;
  char bin_str[2*sizeof(int) + 1];

  n1 = parseInt(argv[1]);
  n2 = parseInt(argv[2]);

  temp = ~n1;
  itobs(temp, bin_str);
  show_bstr(bin_str);
  putchar('\n');

  temp = ~n2;
  itobs(temp, bin_str);
  show_bstr(bin_str);
  putchar('\n');

  temp = n1 & n2;
  itobs(temp, bin_str);
  show_bstr(bin_str);
  putchar('\n');
  temp = n1 | n2;
  itobs(temp, bin_str);
  show_bstr(bin_str);
  putchar('\n');
  temp = n1 ^ n2;
  itobs(temp, bin_str);
  show_bstr(bin_str);
  putchar('\n');
  return 0;
}

//数字转换为二进制表示形式
char * itobs(int n,char * ps)
{
    int i;
    static int size = 2 * sizeof(int);

    for(i = size - 1;i >= 0;i--,n >>= 1)
    {
        ps[i] = (01 & n) + '0';
    }
    ps[size] = '\0';

    return ps;
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

void show_bstr(const char * str)
{
    int i = 0;
    while(str[i] != '\0')
    {
      putchar(str[i]);
      i++;
    }
}
