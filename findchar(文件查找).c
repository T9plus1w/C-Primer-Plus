/*
    编写一段程序。它接受两个命令行参数，第一个是一个字符，第二个是文件名。要求程序
只打印文件中包含给定字符的那些行。
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100
int main(int argc, char const *argv[]) {
  char ch;
  FILE *fp;
  char line[MAXLINE];
  int i,flag;

  if(argc == 3)    //命令行需要三个参数
  {
      ch = argv[1][0];
      fp = fopen(argv[2],"r");

      while(fgets(line,MAXLINE,fp) != NULL &&
            line[0] != '\n')
      {
          i = 0;
          while(line[i++] != '\0')    //查找ch是否在line当中
          {
              if(ch == line[i])    //在字符串中标记为真
              {
                  flag = 1;
                  break;
              }
              else    //否则为假
                  flag = 0;
          }
          if(flag)    //打印存在字符的字符串数组
              fputs(line,stdout);
      }
      fclose(fp);
  }
  else
  {
      fprintf(stderr, "error\n");
      exit(2);
  }
  return 0;
}
