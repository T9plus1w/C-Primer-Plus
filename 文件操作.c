/*
    编写一段程序。它不读取任何命令行参数或者读取一个命令行参数。如果有一个参数，程序将
它作为一个输入文件名。如果没有参数，使用标准输入（stdin）作为输入。假设输入完全由浮点数
组成。让程序计算并且报告输入数字的算数平均数。
*/
#include <stdio.h>

int main(int argc, char const *argv[]) {

  FILE *fp;
  float total = 0.00,average = 0.00;
  float x;
  int n = 0;

  if(argc > 1)
  {
        fp = fopen(argv[1],"r");
        while(fscanf(fp,"%f",&x) == 1 && x > 0)
        {
            total += x;
            n++;
        }
        average = total/n;
        fprintf(stdout,"average = %.2f\n",average);
        fclose(fp);
  }
  else
  {
    printf("please input float(-1 to quit):");
    while(fscanf(stdin,"%f",&x) == 1 && x > 0)
    {
        total += x;
        n++;
        printf("please input float(-1 to quit):");
    }
    average = total/n;
    fprintf(stdout,"average = %.2f\n",average);
  }
  return 0;
}
