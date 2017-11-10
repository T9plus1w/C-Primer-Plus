/*
    编写一个函数string_in(),它接受两个字符串指针参数。如果第二个字符串被包含在第一个字符
串中，函数就返回被包含的字符串开始的地址。例如，string_in("hats","at")返回hats中a的地址，
否则，函数返回空指针。在一个使用循环语句为这个函数提供输入的完整程序中进行测试。
*/
#include <stdio.h>

char* string_in(char* s1,char* s2);

int main(void)
{
    char s1[50],s2[50];
    char *p;
    printf("please input char s1:\n");
    gets(s1);
    printf("please input char s2:\n");
    gets(s2);

    p = string_in(s1, s2);

    if(p == NULL)
        printf("not find\n");
    else
        puts(p);

    return 0;
}
/* 第二个字符串被包含在第一个字符串中，函数就返回被包含的字符串开始的地址 */
char* string_in(char* s1,char* s2)
{
    int i,j,p,pt;

    for(i = 0; s1[i]!='\0'; i++)
    {
        p = i;
        pt = i;
        j = 0;

        //比较是否存在连续相同的字符
        if(s1[i] == s2[j])
        {
            while(s1[++p] == s2[++j] && s2[j] != '\0')
                ;
            if(s2[j] == '\0')
                return &s1[pt];
        }
    }
    return NULL;
}
