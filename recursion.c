/*************************************************
Copyright (C), 2017
File name: recursion.c
Author:
Version:
Date: // 
Description: 实现1-100的加法运算，使用递归
Others: 
Function List: 
int fun (int x);
*************************************************/

#include <stdio.h>
int fun (int x)
{
	if(x>1){
		return x+fun(x - 1);
	}
	else
	    return x;
}

int main(void)
{
	int sum;
	sum = fun(100);
	printf("sum = %d\n",sum);
	return 0;
}


/***********************************************************************
作为一个例子，我们可以在非负整数集上定义一个函数F，它满足F(0)=0且F(x) = 2F(x-1)+x2
当一个函数用它自己来定义时就称为是递归。
***********************************************************************/

int F(x)
{
    if(x == 0)
	    return 0;
    else
	    return 2*F(x-1)+x*x;
}
