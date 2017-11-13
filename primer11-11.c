/*
    编写一个程序。功能是读取输入，直到遇到EOF，并报告单词数、大写字母数、小写字母数、标
点符号数和数字字符数。使用ctype.h函数。
*/
#include <stdio.h>
#include <ctype.h>

int word_count();

int main(void)
{
    char ch;
    int flag = 0;
    int word = 0;
    int cwb = 0;
    int cwl = 0;
    int cn = 0;
    int cp = 0;
    
    //读取输入，知道遇到EOF
    while((ch = getchar()) != EOF)
    {
        //统计单词数
        if(!flag && isalpha(ch))
        {
              word++;
              flag = 1;
        }
        if(isspace(ch))
        {
            flag = 0;
        }

        //统计大写字母数，小写字母数，标点符号数和数字字符数
        if(isupper(ch))
            cwb++;
        else if(islower(ch))
            cwl++;
        else if(isdigit(ch))
            cn++;
        else if(ispunct(ch))
            cp++;
    }

    printf("word＝%d cwb=%d cwl=%d number=%d punctuation=%d\n"
    ,word,cwb,cwl,cn,cp);

    return 0;
}
