/*＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
K.R c
练习3-3 编写函数expand(s1,s2),将字符串s1中类似于a-z一类的速记符号在字符串s2中
扩展为等价的完整列表abc...xyz。该函数可以处理大小写字母和数字，并可以处理a-b-c、
a-z0-9与-a-z等类似的情况。作为前导和尾随的－字符原样打印。

遇到字符直接打印，遇到‘－’打印速记字符之间的列表。 
s1 = abccbaa-zb
s2 = abccbaabcdef...xyzb
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊*/
#include <stdio.h>

#define max 1000

void expand(char s1[],char s2[]);

int main(void){
    int i;
    char c;
    char s1[max];
    char s2[max];

    i = 0;
    //获取字符串s1
    while ((c = getchar()) != '\n')
    {
          s1[i] = c;
          i++;
    }
    expand(s1,s2);
    //打印字符串
    printf("%s\n",s2);
}

//函数将字符串s1中类似于a-z一类的速记符号进行扩展
void expand(char s1[],char s2[])
{
    int i;    //记录s[1] 字符位置
    int j;    //记录s[2] 字符位置
    
    char temp;    //进行标记‘－’
    char result;  
    j = 0;
    for(i = 0; s1[i] != '\0'; i++)
    {
        if(s1[i] >= 'a' && s1[i] <= 'z' )   //先判断当前的字符是否是字母
        {
            if(temp == '-')    //temp为 ‘－’ 时赋值 － 前一个字符到后一个字符之间的字母
            {
              result = s1[i-2];
              result = result + 1;
              while(result <= s1[i])
              {
                  s2[j] = result;
                  result = result + 1;
                  j++;
              }
              temp = s1[i];
            }
            else              //否则直接进行赋值
            {
              s2[j] = s1[i];
              j++;
            }
        }
        else if(s1[i] == '-')    //如遇到 ‘－’ 进行标记
        {
            temp = s1[i];
        }

    }
}
