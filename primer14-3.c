/*
  修改程序清单14.2中的书目列表程序，使它首先按照输入的顺序输出图书的描述，然后按照标题
的字母升序输出图书的描述，最后按照value值的升序输出图书的描述。
*/
/* manybook.c -- 包含多本书的图书目录 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100    //最多可以容纳的图书册数

//建立book模版
struct book{
  char title[MAXTITL];
  char author[MAXAUTL];
  float value;
};

void sort_title(struct book *p,int count);
void sort_value(struct book *p,int count);

int main(void)
{
    struct book library[MAXBKS];  //book结构数组
    int count = 0;
    int index;

    printf("Please enter the book title.\n");
    printf("Press[enter] at the start of a line to stop.\n");
    while(count < MAXBKS && gets(library[count].title) != NULL
                         && library[count].title[0] != '\0')
    {
        printf("Now enter the author.\n");
        gets(library[count].author);
        printf("Now enter the value.\n");
        scanf("%f",&library[count++].value);
        while(getchar() != '\n')
            continue;
        if(count < MAXBKS)
        printf("Enter the next title.\n");
    }

    if(count > 0)
    {
      printf("Here is the list of your books:\n");
      for(index = 0;index < count;index++)
          printf("%s by %s: $%.2f\n",library[index].title,
                    library[index].author,library[index].value);

      sort_title(&library[0],count);
      for(index = 0;index < count;index++)
          printf("%s by %s: $%.2f\n",library[index].title,
                    library[index].author,library[index].value);

      sort_value(&library[0],count);
      for(index = 0;index < count;index++)
          printf("%s by %s: $%.2f\n",library[index].title,
                    library[index].author,library[index].value);
    }
    else
        printf("No books?Too bad.\n");

    return 0;
}

//按标题字母升序排序
void sort_title(struct book *p,int count)
{
    int i,j;
    struct book temp;
    for(i = 0; i < count-1;i++)
        for(j = i+1; j < count-1-i;j++)
            if(strcmp(p[i].title,p[j].title) > 0)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
}

//按value升序排序
void sort_value(struct book *p,int count)
{
  int i,j;
  struct book temp;
  for(i = 0; i < count-1;i++)
      for(j = i+1; j < count-1-i;j++)
          if(p[i].value > p[j].value)
          {
              temp = p[i];
              p[i] = p[j];
              p[j] = temp;
          }
}
