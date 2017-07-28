/*******************************************
描述：这是一个闹钟程序
功能：实现定时响铃功能
版本：v1.00
作者：汤俊伟
时间：2017.05.20
学习点：<stdbool.h><Windows.h>库函数的使用，系统时间
循环判断的基础功能实用，并利用函数进行封装，较为综合
********************************************/

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>
  
void Alarm()
{
    for(int i = 0; i < 10; ++i)
    {
        // 输出计算机响铃
        printf("%s","\a");
    }
}
int main()
{
    while(true)
    {
        // 获取系统时间
        SYSTEMTIME stLocal;
        GetLocalTime(&stLocal);
         
        // 是否到达设定时间
        if(11 == stLocal.wHour)
        {
            Alarm();
            break;
        }
          
        // 休眠1秒，开始下次检查
        Sleep(1000);
    }
 
    return 0;
}
