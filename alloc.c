/* 包含 alloc.h头文件 */
#include <stdio.h>
#include "alloc.h"

static char allocbuf[ALLOCSIZE];  //使用的存储分配空间
static char *allocp = allocbuf;  //下一个空闲位置

/* 操作：分配一块内存空间 */
char *alloc(int n)
{
    if(allocbuf + ALLOCSIZE - allocp >= n)  // 有足够的空闲空间
    {
          allocp += n;
        return allocp - n;  //  分配前的指针
    }else                 // 空闲空间不够
        return 0;
}

/* 操作：释放内存空间 */
void afree(char *p)
{
    if(p >= allocbuf && p < allocbuf+ALLOCSIZE)
        allocp = p;
}
