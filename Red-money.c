/*******************************************
描述：这是一个红包分配程序
功能：实现抢红包，红包分配
版本：v1.00
作者：汤俊伟
时间：2017.05.20
学习点：time库的使用，基本循环加上分配算法
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    float total = 10;//红包总额
    int num = 8; //分成8个红包,支持8人随机领取
    float low = 0.01;//每个人最少能收到0.01元
    float money;
    float safe_total = 0.00;
    int i;

    srand((unsigned)time(NULL));
    for(i = 0; i < num; i++)
    {
        safe_total = (total - (num - i)*low) / (num - i);
        money = (rand()%(int)(safe_total * 100 - low * 100 + 1)+ safe_total * 100) / 100;
        total = total - money;
        printf("第%d个红包%.2f元，余额：%.2f\n",i,money,total);
    }
    return 0;
}
