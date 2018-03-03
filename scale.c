//十进制转换为二进制
#include <stdio.h>

#define N 16
int main(void)
{
    int n,r;
    int i; 
    int m[N] = {0};
    scanf("%d",&n);

    for(i = 0;n > 0;i++)
    {
        r =n%2;
        n /= 2;
        m[i] = r;
    }

    for(i = N-1;i >= 0;i--)
    {
        printf("%d",m[i]);
        if(!(i%4))
            printf(" ");
    }
    printf("\n");
    return 0;
}
