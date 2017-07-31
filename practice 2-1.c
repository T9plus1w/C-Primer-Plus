/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c
练习2-1 编写一个程序以确定分别由signed及unsigned限定的char、short、int与long
类型变量的取值范围。采用打印标准头文件中的相应值以及直接计算两种方式实现。
后一种方法的实现较困难一些，因为要确定各种浮点类型的取值范围。

这个程序采用两种打印出取值
打印头文件的值
添加<limits.h>头文件
找出头文件中的定义，进行打印

直接计算
利用按位运算符进行计算。
printf(signed char min = %d,(char)((unsigned char) ~0 >> 1));
printf(signed char max = %d,-(char)((unsigned char) ~0 >> 1));

printf(unsigned char max = %d,(char)((unsigned char) ~0));
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/

#include <stdio.h>
#include <limits.h>

int main()
{
    printf("char = %lu\n",sizeof(char));
    printf("int = %lu\n",sizeof(int));
    printf("singned char=%d~%d unsigned char=0~%d\n",SCHAR_MIN,SCHAR_MAX,UCHAR_MAX);
    printf("singned short=%d~%d unsigned short=0~%d\n",SHRT_MIN,SHRT_MAX,USHRT_MAX);
    printf("singned int=%d~%d unsigned int =0~%u\n",INT_MIN,INT_MAX,UINT_MAX);
    printf("singned long=%ld~%ld unsigned long =0~%lu\n",LONG_MIN,LONG_MAX,ULONG_MAX);
    return 0;
}
