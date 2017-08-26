/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c

描述：
  十进制数通过转换成字符串进行打印，改写3.6版本通过递归函数进行功能实现。
功能：
  十进制数：123

  打印字符串：“123”
作者：
时间：08／26／17
版本：
程序组织结构：
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/
#include <stdio.h>

void printd(int n);

int main(){
    int n;
    scanf("%d",&n);
    printf("输入的数位：%d",n);
    printf("\n");
    printd(n);
    printf("\n");
    return 0;
}

/*printd函数：打印十进制数n*/
void printd(int n)
{
  int c;
  if(n < 0)    //n是负数，取负号 将n变正
  {
    putchar('-');
    n = -n;
  }
  if(n/10)    //递归跳出判断
  {
    printd(n/10);    //递归调用函数本身
  }
  c = n%10 +'0';
  putchar(c);    //打印数字
}
