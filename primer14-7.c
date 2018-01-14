/*
  修改程序清单14.14，在从文件中读出每个纪录并且显示它时，允许用户选择删除该记录或修改
该记录的内容。如果删除记录，把空出来的数组空间留给下一个要读入的记录。要能够改变现有的
文件内容，必须使用“r+b"模式，而不是”a+b"模式。要注意文件指针的定位，以便追加的记录不
会覆盖已有的记录。
最简单的方法是对存储在程序内存中的数据做所有的改变，然后再把最后的信息集写入文件中。
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10    //图书最多本数

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
  struct book library[MAXBKS];    //结构数组
  int count = 0;
  int index,filecount;
  FILE * pbooks;
  int size = sizeof(struct book);

  if((pbooks = fopen("book.dat","r+b")) == NULL)
  {
    fputs("Can't open book.dat file\n",stderr);
    exit(1);
  }
  rewind(pbooks);    //定位到文件开始处
  while(count < MAXBKS && fread(&library[count],size,1,pbooks) == 1)
  {
    if(count == 0)
        puts("Current contents of book.dat: ");
    printf("%s by %s:$%.2f\n",library[count].title,
          library[count].author,library[count].value);
    count++;
  }
  filecount = count;
  if(count == MAXBKS)
  {
    fputs("The book.dat file is full.",stderr);
    exit(2);
  }
  puts("Please add new book titles.");
  puts("Press [enter] at the start of a line to stop.");
  while(count < MAXBKS && gets(library[count].title) != NULL
                       && library[count].title[0] != '\0')
  {
    puts("Now enter the author.");
    gets(library[count].author);
    puts("Now enter the value.");
    scanf("%f",&library[count++].value);
    while(getchar() != '\n')
        continue;
    if(count < MAXBKS)
        puts("Enter the next title.");
  }

  if(count > 0)
  {
    puts("Here is the list of your books: ");
    for(index = 0;index < count;index++)
        printf("%s by %s:$%.2f\n",library[index].title,
              library[index].author,library[index].value);
    fwrite(&library[filecount], size,count - filecount,pbooks);
  }
  else
      puts("No books? Too bad.\n");

  puts("Bye.\n");
  fclose(pbooks);

  return 0;
}
