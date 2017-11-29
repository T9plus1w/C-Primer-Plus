/*
  修改程序清单13.6中的程序，使用命令行参数（而不是交互式界面）获得文件名。
*/
/* 13.6 append.c -- 把多个文件的内容追加到一个文件中 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define SLEN 81
void append(FILE *source,FILE *dest);

int main(int argc, char *argv[])
{
    FILE *fa,*fs;
    int files = 0;

    if((fa = fopen(argv[1],"a")) == NULL)
    {
        fprintf(stderr,"Can't open %s\n",argv[1]);
        exit(2);
    }
    if(setvbuf(fa,NULL,_IOFBF,BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n",stderr);
        exit(3);
    }

    while(gets(argv[2]) && argv[2][0] != '\0')
    {
        if(strcmp(argv[1],argv[2]) == 0)
            fputs("Can't append file to itself\n" ,stderr);
        else if((fs = fopen(argv[2],"r")) == NULL)
            fprintf(stderr, "Can't open %s\n",argv[2]);
        else
        {
            if(setvbuf(fs,NULL,_IOFBF,BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n",stderr);
                continue;
            }
            append(fs,fa);
            if(ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n",argv[2]);
            if(ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n",argv[1]);
            fclose(fs);
            files++;
            printf("File %s appended.\n",argv[2]);
            puts("Next file (empty line to quit): ");
        }
    }
    printf("Done.%d files appended.\n",files);
    fclose(fa);

    return 0;
}

void append(FILE *source,FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];    //分配一次

    while((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
        fwrite(temp,sizeof(char),bytes,dest);
}
