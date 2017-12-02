/*
  编写一段程序，将一个字符、零个或多个文件名作为命令行参数。如果字符后没有参数跟随，
程序读取标准输入文件。否则，程序依次打开每个文件，然后报告每个文件中该字符的出现次数。
文件名和字符本身也与计数值一起报告。程序中包括错误检查，以确定参数数目是否正确和是否
能打开文件。如果不能打开文件，程序要报告这一情况然后继续处理下一文件。
*/
#include <stdio.h>
#include <stdlib.h>

#define LEN 80

int totalchar(char str[LEN],char ch);

int main(int argc,char *argv[])
{
    char ch;
    FILE *fp;
    int E1,wd,sum = 0;
    char line[LEN];
    int i = 2;
    ch = argv[1][0];

    if((fp = fopen(argv[i],"r")) == NULL)
    {
        printf("Can't open %s\n",argv[1]);
        while((E1 = fscanf(stdin,"%s",line)) == 1 && line[0] != '\0')
        {
            wd = totalchar(line,ch);
            sum += wd;
        }
        printf("stdin,%d,%c\n",sum,ch);
    }
    else
    {

        while((E1 = fscanf(fp,"%s",line)) == 1 && line[0] != '\0')
        {
            wd = totalchar(line,ch);
            sum += wd;
        }
        printf("%s,%d,%c\n",argv[2],sum,ch);
        for(i = 3; ;i++)
        {
            if((fp = fopen(argv[i],"r")) == NULL)
            {
                printf("Can't open %s\n",argv[i]);
                exit(1);
            }
            else
            {
                while((E1 = fscanf(fp,"%s",line)) == 1 && line[0] != '\0')
                {
                    wd = totalchar(line,ch);
                    sum += wd;
                }
                printf("%s,%d,%c\n",argv[i],sum,ch);
            }
        }
    }

    return 0;
}
int totalchar(char str[LEN],char ch)
{
    int wd = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] == ch)
        {
          wd++;
        }
        i++;
    }
    return wd;
}
