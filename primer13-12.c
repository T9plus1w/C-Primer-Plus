/*
    创建一个包含20行，每行30个整数的文本文件。整数在0-9之间，用空格分开。该文件是一个
图片的数字表示，从0到9的值代表逐渐增加的灰度。编写一个程序，将文件的内容读入到一个20*30
的int数组中。一种将这种数字表示转化成图片的粗略方法就是让程序使用数组中的数值来初始化一个
20*31的字符阵列。0对应空格字符，1对应句号字符，依此类推，较大的值对应占用空间较多的字符。
比如，可以使用＃代表9.每行的最后一个字符（第31个）为空字符，这样数组将包含20个字符串。然后
程序显示结果图片（即打印这些字符串），并将结果存入一个文本文件中。例如，如果开始的数据为：
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  int num[20][30],row,column;
  FILE *fp;
  char photo[20][31],table[] = " .':~*=&%@";

  if((fp = fopen(argv[1],"r")) == NULL)
  {
      fprintf(stderr, "Can't open %s\n",argv[1]);
      exit(1);
  }

  //将数据从文件读入数组中
  for(row = 0;row < 20;row++)
      for(column = 0;column < 30;column++)
          fscanf(fp,"%d",&num[row][column]);

  fclose(fp);

  //将数字转换成字符号
  for(row = 0;row < 20; row++)
  {
      for(column = 0;column < 30;column++)
          photo[row][column] = table[num[row][column]];
      photo[row][column] = '\0';
  }

  //打印字符号
  for(row = 0;row < 20;row++)
      puts(photo[row]);

  //打开写入文件
  if((fp = fopen(argv[2],"w")) == NULL)
  {
      fprintf(stderr, "Can't open %s\n",argv[2]);
      exit(1);
  }

  //将字符打印到文件当中
  for(row = 0;row < 20;row++)
  {
      fprintf(fp, "%s\n",photo[row]);
  }

  return 0;
}
