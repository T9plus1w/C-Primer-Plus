/*
  编写一个函数，该函数将一个unsigned int中的所有位向左旋转指定数量的位。例如，rotate_1(x,4)
将x中的所有位向左移动4个位置，而且从左端丢失的位会重新出现在右端。也就是说，把从高位移出的位放入
低位。在程序中测试该函数。
*/
#include <stdio.h>

int rotate_1(unsigned int number,unsigned int bit);

int main(void)
{
  unsigned int i = 8;
  printf("%u\n",i);
  i = rotate_1(i,4);
  printf("%u\n",i);
  return 0;
}

//向左旋转指定数量的位
int rotate_1(unsigned int number,unsigned int bit)
{
    unsigned int i;
    unsigned int hign = 8 * sizeof(unsigned int);//最高位
    for(i = 0;i < bit;i++)
    {
        if(number & (1 << (hign - 1)))
            number = (number << 1) | 1;
        else
            number = number << 1;
    }

    return number;
}
