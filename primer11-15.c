/*
    编写一个程序，其功能是读取输入，直到遇到文件结尾，并把文件显示出来。要求程序可以
识别并执行下面的命令行参数：

-p    按照原样显示输入
-u    把输入全部转换为大写
-l    把输入全部转换为小写
*/
#include <stdio.h>
#include <ctype.h>

void word_put(void);
void islower_put(void);
void isupper_put(void);

int main(int argc ,char *argvp[])
{
    char a;
    a = argvp[1][1];    //记录命令行第二个功能字符

    switch(a)
    {
        case 'p':
            {
                word_put();
                break;
            }
        case 'u':
            {
                isupper_put();
                break;
            }
        case 'l':
            {
                islower_put();
                break;
            }
        default:
            {
                printf("您输入的命令有误！\n");
                printf("Bye!!\n");
                return 1;
            }
    }

    return 0;
}

/* -p    按照原样显示输入 */
void word_put(void)
{
    char ch;

    while((ch = getchar()) != EOF)
    {
        putchar(ch);
    }
}

/* -l    把输入全部转换为小写 */
void islower_put(void)
{
    char ch;

    while((ch = getchar()) != EOF)
    {
        if(islower(ch))
        {
            putchar(ch);
        }
        else{
            ch = tolower(ch);
            putchar(ch);
        }
    }
}

/* -u    把输入全部转换为大写 */
void isupper_put(void)
{
    char ch;

    while((ch = getchar()) != EOF)
    {
        if(isupper(ch))
        {
            putchar(ch);
        }
        else{
            ch = toupper(ch);
            putchar(ch);
        }
    }
}
