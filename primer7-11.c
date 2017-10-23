/*
title:
ABC Mail Order Grocery朝鲜蓟的售价是1.25美元/磅，甜菜的售价是0.65美元/磅，胡萝卜的售价
是0.89美元/磅。在添加运输费用之前，他们为100美元的订单提供5%的打折优惠。对5磅或以下的定单收
取3.50美元的运输和装卸费用；超过5磅而不足20磅的定单收取1O.OO美元的运输和装卸费用：20磅或以
上的运输，在8美元基础上每磅加收0.1美元。编写程序，在循环中使用switch语句，以便对输入a的响应
是让用户输入所需的朝鲜蓟磅数，b为甜菜的磅数，c为胡萝卜的磅数，而q允许用户退出订购过程。
然后程序计算总费用、折扣和运输费用（如果有运输费的话），以及总数。随后程序应该显示所有的
购买信息：每磅的费用、订购的磅数、该订单每种蔬菜的费用、订单的总费用、折扣，如果有的话加上运
输费用，以及所有费用的总数。
*/
#include <stdio.h>

/* 菜品单价 */
#define ARTICHOKE 1.25
#define BEET 0.65
#define CARROT 0.89

#define DISCOUNT 0.05

float money(float price,int pound);
float freighted(int pound);

int main(void)
{
    int pound,a;
    float freight,price,total,discount = 0.00;


    while(1)
    {
        printf("                menu        \n");
        printf("1、artichoke            2、beet   \n");
        printf("3、carrot               4、quit\n");
        printf("please input 1~4(4 quit):");
        scanf("%d",&a);    //选择产品
        switch(a)
        {
          case 1:
                price = ARTICHOKE;
                break;
          case 2:
                price = BEET;
                break;
          case 3:
                price = CARROT;
                break;
          case 4:
                printf("Bye!\n");
                return 0;
          default:
                printf("You input error!\n");
                return 104;
        }
        printf("please input pound:");
        scanf("%d",&pound);

        total = money(price,pound);    //总费用
        printf("this is total = %.2f\n",total);
        freight = freighted(pound);    //运费

        if(total > 100)
            discount = total * DISCOUNT;    //超过一百美元的折扣

        printf("pound = %d,freight = %.2f,discount = %.2f,total = %.2f\n",
              pound,freight,discount,total-discount+freight);
        getchar();
        getchar();
    }
}

//计算总金额
float money(float price,int pound)
{
    return price * pound;
}

//计算运费
float freighted(int pound)
{
    if(pound == 0 || pound < 0)
        return 0;
    else if(pound > 0 && pound <= 5)
        return 3.5;
    else if(pound > 5 && pound <= 20)
        return 10;
    else
        return 8+(pound-20)*0.1;
}
