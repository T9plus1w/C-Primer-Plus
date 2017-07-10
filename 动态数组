/*************************************************
Copyright (C), 2017
File name: array.c
Author:
Version:
Date: // 
Description: 动态数组分配
Others: 
Function List: 
Array array_create(int init_size);
void array_free(Array *a);
int array_size(const Array *a);
int* array_at(Array *a,int index);
int array_get(const Array *a,int index);
void array_set(Array *a,int index,int value);
void array_inflate(Array *a,int more_size);

*************************************************/

#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 20

typedef struct 
{
	int *array;
	int size;
} Array;

/************************************************
函数名：array_create()
作者：junwei_tang
日期：2017.07.10
功能：链表创建动态数组
输入参数：init_size 需要的数组大小
返回值：结构体Array a；
修改日期：
修改内容：
************************************************/
Array array_create(int init_size)
{
	Array a;
	a.array = (int*)malloc(sizeof(int)*init_size);
	a.size = init_size;
	return a;
}

/************************************************
函数名：array_free()
作者：junwei_tang
日期：2017.07.10
功能：释放数组内存
输入参数：Array *a 指向动态数组的指针
返回值：void
修改日期：
修改内容：
************************************************/
void array_free(Array *a)
{
	free(a->array);
	a->array = NULL;
	a->size = 0;
}

/************************************************
函数名：array_size
作者：junwei_tang
日期：2017.07.10
功能：输出动态数组大小
输入参数：Array *a 指向动态数组的指针
返回值：size 数组大小
修改日期：
修改内容：
************************************************/
int array_size(const Array *a)
{
	return a->size;
}

/************************************************
函数名：array_at
作者：junwei_tang
日期：2017.07.10
功能：输出动态数组的某位的值，也可作为赋值使用
输入参数：Array *a 指向动态数组的指针，index 某位
返回值：&(a->array[index]) 返回某位值的地址
修改日期：
修改内容：
************************************************/
int* array_at(Array *a,int index)
{
	if(index >= a->size)
	{
		array_inflate(a,(index/BLOCK_SIZE+1)*BLOCK_SIZE-a->size);
	}
	return &(a->array[index]);
}

/************************************************
函数名：array_get
作者：junwei_tang
日期：2017.07.10
功能：输出动态数组的某位的值  
与array_at函数功能重叠，一个返回地址，一个返回值
array_get作为单独使用
输入参数：Array *a 动态数组指针，index 某位
返回值：(a->array[index]) 返回某位值
修改日期：
修改内容：
************************************************/
int array_get(const Array *a,int index)
{
	return a->array[index];
}

/************************************************
函数名：array_set
作者：junwei_tang
日期：2017.07.10
功能：动态数组某位赋值
输入参数：Array *a 指向动态数组的指针，int index 某位,int value 值
返回值：void
修改日期：
修改内容：
************************************************/
void array_set(Array *a,int index,int value)
{
	a->array[index] = value;
}

/************************************************
函数名：array_inflate
作者：junwei_tang
日期：2017.07.10
功能：将动态数组扩大
核心方法创建一个新的数组，将旧数组赋值给新数组，释放旧数组
输入参数：Array *a 旧数组指针，more_size 增加的空间大小
返回值：void
修改日期：
修改内容：
************************************************/
void array_inflate(Array *a,int more_size)
{
    int *p = (int *)malloc(sizeof(int)(a->size + more_size));
    int i;
    for(i=0; i<a->size;i++)
    {
    	p[i] = a->array[i];
    }
    free(a->array);
    a->array = p;
    a->size += more_size;
}


int main(void)
{
	Array a = array_create(100);
	array_free(&a);
	printf("%d\n",array_size(&a));
	*array_at(&a,0) = 10;
	printf("%d\n",*array_at(&a,0));

	int number;
	int cnt = 0;
	while(number != -1){
		scanf("%d",&number);
		if(number != -1)
			*array_at(&a,cnt++) = number;
	}
	array_free(&a);

	return 0;
}
