/*
    编写一个程序，该程序与我们在显示程序清单12.13的输出之后所讨论的修改版程序具有相同的表现。
也就是说，输出应像下面这样：
Enter the number of sets;enter q to stop.
18
How many sides and how many dice?
6 3
Here are 18 sets of 3 6-sided throws.
    12 10 6 9 8 14 8 15 9 14 12 17 11 7 10
    13 8 14
How many sets? Enter q to stop.
q
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_count = 0;    //外部变量

int rollem(int sides);
int roll_n_dice(int dice,int sides);

int main(void)
{
    int dice;
    int roll[100];
    int sides;
    int i,n;

    srand((unsigned int)time(0));    //随机化种子
    printf("Enter the number of sets;enter q to stop.\n");
    while(scanf("%d",&n) == 1 && n > 0)
    {
        printf("How many sides and how many dice?\n");
        printf("dice:");
        scanf("%d",&dice);
        printf("sides:");
        scanf("%d",&sides);

        for(i = 0; i < n; i++)
        {
            roll[i] = roll_n_dice(dice,sides);
        }
        
        printf("Here are %d sets of %d %d-sided throws.\n",
                n,dice,sides);

        for(i = 0;i < n;i++)
        {
            printf("%d ",roll[i]);
        }
        printf("\n");
        printf("How many sides?Enter 0 to stop.\n");
    }
    printf("The rollem() function was called %d times.\n",
          roll_count);    //使用外部变量
    printf("GOOD FORTUNE TO YOU!\n");

    return 0;
}

/* 掷骰子一次 */
int rollem(int sides)
{
    int roll;

    roll = rand() % sides + 1;
    ++roll_count;

    return roll;
}

/* 掷任意个骰子，返回点数总和 */
int roll_n_dice(int dice,int sides)
{
    int d;
    int total = 0;
    if(sides < 2)
    {
        printf("Need at least 2 sides.\n");
        return -2;
    }
    if(dice < 1)
    {
        printf("Need at least 1 die.\n");
        return -1;
    }
    for(d = 0;d < dice;d++)
        total += rollem(sides);

    return total;
}
