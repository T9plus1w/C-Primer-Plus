/*
    编写一段程序，依次在屏幕上显示命令行中列出的全部文件。使用argc控制循环。
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {

  FILE *fp;
  int i;
  char ch;

  //命令行小于2个 退出
  if(argc < 2)
  {
      printf("error\n");
      exit(1);
  }

  for(i = 1;i < argc;i++)
  {
      if((fp = fopen(argv[i],"r")) == NULL)    //打开文件
      {
         printf("Can't open %s\n",argv[i]);
         exit(2);
      }
      while ((ch = getc(fp)) != EOF)    //打印文件内容
      {
          putc(ch,stdout);
      }
  }

  return 0;
}
