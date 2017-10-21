/* title:编写一个程序，首先要求用户输入名字，然后要求用户输入姓氏。
   在一行打印输入的姓名，在下一行打印每个名字中字母的个数。把字母个
   数与相应名字的结尾对齐，如下所示：
   Melissa Honeybee
         7        8
   然后打印相同的信息，但是字母个数与相应单词的开始对齐。
   Melissa Honeybee
   7       8                                           */
#include <stdio.h>
#include <string.h>

int main(void)
{
    char surname[20];
    char firstname[20];
    int width1,width2;
    printf("Please input surname:");
    scanf("%s",surname);    //输入姓
    printf("Please input firstname:");
    scanf("%s",firstname);    //输入名

    width1 = strlen(surname);    //计算姓名长度
    width2 = strlen(firstname);

    //进行打印
    printf("you name:%s %s\n",surname,firstname);
    printf("         %*d %*d\n",width1,width1,width2,width2);
    printf("and\n\n");
    printf("you name:%s %s\n",surname,firstname);
    printf("         %-d%*d\n",width1,width1+1,width2);

    return 0;
}
