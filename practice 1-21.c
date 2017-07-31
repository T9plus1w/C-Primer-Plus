/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c
练习1-21 编写程序entab,将空格串替换为最少数量的制表符和空格，但要保持单词之前的
间隔不变。假设制表符终止位的位置与练习1-20的detab程序的情况相同。当使用一个制表
符或者一个空格都可以到达下一个制表符终止位时，选用哪一种替换字符比较好？

1、当一个“非空格字符”和该字符的下一个制表符终止位之间全部都是空格的时候，就可以用
一个制表符‘\t’替换这些字符

例如：（用 _ 代表一个空格，用 | 表示制表符终止位，注意 | 并不是字符串的一部分）
_ _ _ a b c _ _ | _ b c d f t q u r | _ d

能够用制表符替换的空格只有： （用 * 号表示用制表符替换掉的空格）
_ _ _ a b c * * | _ b c d f t q u r | _ d

2、当两个制表符终止位之间全部都是空格的时候。这些空格就可以用'\t'替换。

例如：
_ _ _ _ _ a b c | _ _ _ _ _ _ _ _ | a b c

替换之后：
_ _ _ _ _ a b c | * * * * * * * * | a b c
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/

#include <stdio.h>

#define TABSTOP 8  //在console中，制表符终止位一般是8，16，24，32......

int main(){
  int total = 0;   //已经读到的字符数
  int spaces = 0;  //已经都到的空格数
  char c;          //当前都到的字符

  while((c = getchar()) != EOF)
  {
      if(c != ' ')  //c不是一个空格
      {
          if(spaces == 0)  //如果已经读到 0 个空格
          {
              putchar(c);
              ++total;
          }
          else    //c不是一个空格，但是读到的空格数 不等于 0
          {
              for(; spaces > 0; --spaces)
              {
                putchar(' ');
              }
              spaces = 0;
              ++total;
              putchar(c);
          }
          if(c == '\n')
          {
            total = 0;
            spaces = 0;
          }
      }
      else          //c是一个空格
      {
          ++total;
          ++spaces;

          int temp = (total - spaces) / TABSTOP;
          int nextLocation = (++temp) * TABSTOP; //下一个制表符终止位

          if(total < nextLocation)
            ;
          else //用‘\t’填充空格
          {
              for(int i = 0;i < (nextLocation - (total - spaces)); i++)
                  putchar('*'); //使用＊号替代制表符
              spaces = 0;      // 读到的空格数重新置为 0
          }
      }
  }
  return 0;
}
