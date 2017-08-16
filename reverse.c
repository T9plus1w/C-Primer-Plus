/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c

reverse函数，该函数用于倒置字符串s中各个字符的位置。
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/

#include <stdio.h>
#include <string.h>

void reverse(char s[]);

//测试reverse函数
int main()
{
    char a[100];
    char c;
    int i = 0;
    while( (c= getchar()) != '\n')
    {
        a[i] = c;
        i++;
    }
    reverse(a);
    printf("%s\n",a);
    return 0;
}

//reverse函数实现字符串倒置
void reverse(char s[])
{
    int i,len;
    char temp;
    len = strlen(s) - 1;  //strlen计算字符个数不包括'\0' 字符数组从0开始计数所以要减1
    for(i = 0;i < len; i++)
    {
        temp = s[i];
        s[i] = s[len];
        s[len] = temp;
        len--;
    }
}
