/*
下面是某程序的一部分：
// pe12-8.c
#include <stdio.h>
int *make_array(int elem,int val);
void show_array(const int ar[],int n);
int main(void)
{
    int *pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    scanf("%d",&size);
    while(size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d",&value);
        pa = make_array(size,value);
        if(pa)
        {
            show_array(pa,size);
                free(pa);
        }
        printf("Enter the number of elements(<1 to quit): ");
        scanf("%d",&size);
    }
    printf("Done.\n");
    return 0;
}
    给出函数make_array()和show_array()的定义以使程序完整。函数make_array()接受
两个参数。第一个是int数组的元素个数，第二个是要赋给每个元素的值。函数使用malloc()来
创建一个适当大小的数组，把每个元素设定为指定的值，并返回一个数组指针。函数show_array()
以8个数一行的格式显示数组内容。
*/
#include <stdio.h>
#include <stdlib.h>

int *make_array(int elem,int val);
void show_array(const int ar[],int n);

int main(void)
{
    int *pa;
    int size;
    int value;

    printf("Enter the number of elements: ");
    scanf("%d",&size);
    while(size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d",&value);
        pa = make_array(size,value);
        if(pa)
        {
            show_array(pa,size);
            printf("\n");
                free(pa);
        }
        printf("Enter the number of elements(<1 to quit): ");
        scanf("%d",&size);
    }
    printf("Done.\n");
    return 0;
}

int *make_array(int elem,int val)
{
    int *p;
    int i;

    p = (int *)malloc(elem * sizeof(int));    //使用malloc函数分配数组空间

    for(i = 0;i < elem;i++)
    {
        p[i] = val;
    }
    return p;
}

void show_array(const int ar[],int n)
{
    int i;
    for(i = 0;i < n;i++)
    {
        printf("%d ",ar[i]);
    }
}
