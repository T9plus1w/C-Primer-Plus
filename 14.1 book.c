//这是一个关于struct结构体的程序，图书资料管理

#include <stdio.h>
#define MAXTITL 41  //书名的最大长度＋1
#define MAXAUTL 31  //作者名的最大长度＋1

struct book{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};   //定义结构体

int main(void)
{
    struct book library; //声明自定义类型变量
    printf("Please enter the book title.\n");
    gets(library.title); //输入书名 访问title部份
    printf("Now enter the value.\n");
    gets(library.author);//输入作者名
    printf("Now enter the value.\n");
    scanf("%f",&library.value); //输入书本价格
    printf("%s by %s:$%.2f\n",library.title,library.author,library.value);  //打印出书本信息
    printf("%s:\"%s\"($%.2f)\n",libray.author,libray.title,library.value);
    
    return 0;
}


//建立结构的格式或布局。
//声明遵循该布局的变量。
//获取对一个结构变量的各个部件的访问。

