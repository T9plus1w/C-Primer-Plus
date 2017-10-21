/* title:使用嵌套循环产生下列图案
F
FE
FED
FEDC
FEDCB
FEDCBA                   */                                                         
#include <stdio.h>

int main(void)
{
    int i,j;
    char ch = 'F',cp;

    for(i = 1;i <= 6;i++)
    {    cp = ch;
        for(j = 0;j < i;j++)
        {
            printf("%c",cp--);
        }
        printf("\n");
    }
    return 0;
}
