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
