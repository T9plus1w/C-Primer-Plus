/*
    编写一个程序，读取输入，直到读入了10个字符串或遇到EOF，由二者中最先被满足的那个终止
读取过程。这个程序可以为用户提供一个有5个选项的菜单：输出初始字符串列表、按ASCII顺序输出
字符串、按长度递增顺序输出字符串、按字符串中第一个单词的长度输出字符串和退出。菜单可以循环，
直到用户输入退出请求。当然，程序要能真正完成菜单中的各项功能。
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define LIM 10
#define SIZE 81

int getstring(char *str[LIM],char input[LIM][SIZE]);    //获取10个字符串
void showmenu(void);    //显示菜单
void string_put(char *str[LIM]);    //输出初始字符串列表
void ascii_put(char *str[LIM],int num);    //按ASCII顺序输出字符串
void increas_put(char *str[LIM],int num);    //按长度递增顺序输出字符串
void length_put(char *str[LIM],int num);    //按字符串中第一个单词的长度输出字符串
int first_word_length(char *st);    //字符串第一个单词长度

int main(void)
{
    char *arr[LIM];
    char input[LIM][SIZE];
    char a;

    getstring(arr,input);

    while(1)
    {
        showmenu();
        a = getchar();
        switch(a)
        {
            case '1':
                string_put(arr);
                break;
            case '2':
                ascii_put(arr, LIM);
                string_put(arr);
                break;
            case '3':
                increas_put(arr, LIM);
                string_put(arr);
                break;
            case '4':
                length_put(arr,LIM);
                string_put(arr);
                break;
            case '5':
                printf("Bye bye!\n");
                return 0;
            default :
                printf("输入有误，请从新输入。\n");
                break;
        }
        while(getchar() != '\n')
            continue;
    }

    return 0;
}

/* 读取输入，直到读入了10个字符串或遇到EOF */
int getstring(char *str[LIM],char input[LIM][SIZE])
{
    int ct = 0;

    printf("please input 10 string:\n");
    while(ct < LIM && gets(input[ct]) != NULL&&input[ct][0] != EOF)
    {
        str[ct] = input[ct];
        ct++;
    }

    return ct;
}

/* 显示菜单 */
void showmenu(void)
{
    printf("                      功能菜单        \n");
    printf("1、输出字符串列表                2、按ASCII顺序输出字符串\n");
    printf("3、按长度递增顺序输出字符串    4、按字符串中第一个单词的长度输出字符串\n");
    printf("5、退出\n");
    printf("请输入1-5:");
}

/* 输出初始字符串列表 */
void string_put(char *str[LIM])
{
      int i;

      for(i = 0; i<LIM;i++)
      {
          puts(str[i]);
      }
}

/* 按ASCII顺序输出字符串 */
void ascii_put(char *str[LIM],int num)
{
    char *temp;
    int top,seek;

    for(top = 0;top < num-1;top++)        //遍历字符串指针
        for(seek = top+1;seek < num;seek++)
            if(strcmp(str[top], str[seek]) > 0)  //按ascii码strcmp返回值大于0则交换
            {
                temp = str[top];
                str[top] = str[seek];
                str[seek] = temp;
            }
}

/* 按长度递增顺序输出字符串 */
void increas_put(char *str[LIM],int num)
{
    char *temp;
    int top,seek;

    //冒泡排序
    for(top = 0;top < num-1;top++)
        for(seek = top+1;seek < num;seek++)
            if(strlen(str[top]) > strlen(str[seek]))
            {
                temp = str[top];
                str[top] = str[seek];
                str[seek] = temp;
            }
}

/* 按字符串中第一个单词的长度输出字符串 */
void length_put(char *str[LIM],int num)
{
  char *temp;
  int top,seek;

  //冒泡排序
  for(top = 0;top < num-1;top++)
      for(seek = top+1;seek < num;seek++)
          if(first_word_length(str[top]) > first_word_length(str[seek]))
          {
              temp = str[top];
              str[top] = str[seek];
              str[seek] = temp;
          }
}

/* 计算字符串第一个单词长度 */
int first_word_length(char *st)
{
    int i = 0;

    //处理空字符串
    for(;!isalpha(*st);st++)
        if(*st == '\0')
            return 0;
            
    //计算首单词长度
    while(isalpha(st[i]))
    {
        i++;
    }
    return i;
}
