/*
title:
  修改程序清单8.4中的猜测程序，使其使用更智能的猜测策略。例如，程序最初猜50，让其询问用户
该猜测值是大、小还是正确。如果该猜测值小，则令下一次猜测值为50和100的中值，也就是75。如果
75大，则下一次猜测值为75和50的中值，等等。使用这种二分搜索（binary search）策略，起码
如果用户没有欺骗，该程序很快会获得正确答案。
*/
#include <stdio.h>

int main(void)
{
    int guess = 1;
    int low = 0,high = 100;
    char ch;

    printf("Pick an intteger from 1 to 100.I will try to guees");
    printf("it\nRespond with a y if my guess is right and with");
    printf("\nan n if it is wrong.\n");
    guess = (low + high)/2;
    printf("Uh...is your number %d?\n",guess);

    while(1)
    {

        printf("Is it big、small or equal?\n");
        printf("please input b、s or e.\n");

        ch = getchar();
        while(getchar() != '\n')
            continue;

        if(ch =='b')    //用户猜的数字比guess更大
        {
            low = guess+1;
            guess = (low + high)/2;
            printf("Well,then,is it %d?\n",guess);
            continue;
        }
        else if(ch =='s')    //用户猜的数字比guess更小
        {
            high = guess-1;
            guess = (low + high)/2;
            printf("Well,then,is it %d?\n",guess);
            continue;
        }
        else if(ch == 'e')    //猜对了
        {
            printf("you number:%d\n",guess);
            printf("I knew I could do it!\n");
            printf("bye!\n");
            return 0;
        }
        else
            continue;
    }

    return 0;
}
