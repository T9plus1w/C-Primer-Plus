/*
  编写一个函数，该函数接受两个int参数：一个值和一个位的位置。如果指定的位上的值是1，则
该函数返回1，否则返回0。在程序中测试该函数。
*/
#include <stdio.h>

int check_bit(unsigned int number,unsigned int bit);

int main(void)
{
  unsigned int number,bit;
  scanf("%d%d",&number,&bit);
  printf("bit %d of %d is %d\n",bit,number,check_bit(number,bit));
  
  return 0;
}

int check_bit(unsigned int number,unsigned int bit)
{
    return (number >> bit) & 1;
}
