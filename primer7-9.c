/* title:编写一个程序，接受一个整数输入，然后显示所有小于或等于该数的素数。 */
#include <stdio.h>

int main(void)
{
    int number,i,j,flag;
    /* 接受一个整数 */
    printf("please input integer:");
    scanf("%d",&number);

    /* 显示所有小于或等于该数的素数 */
    for(i = 1;i <= number;i++)
    {
        flag = 1;
        for(j = 2; j < i;j++)
        {
            if(i%j == 0)
                flag = 0;
        }
        if((flag == 1) && (i != 1))
            printf("%d ",i);
    }
    printf("\n");

    return 0;
}
