/* alloc.h -- 内存分配函数的头文件 */
#ifndef _ALLOC_H_
#define _ALLOC_H_

#define ALLOCSIZE 1000  //可用空间大小

/* 操作：分配一块内存空间 */
/* 操作前：n为需要分配内存空间大小 */
/* 操作后：如果还有内存空间返回指向这个空间的指针，否则返回 0 */
char *alloc(int n);

/* 操作：释放内存空间 */
/* 操作前：*p 为指向需要释放空间的指针 */
/* 操作后：如果 *p 在这个空间内进行释放 */
void afree(char *p);

#endif
