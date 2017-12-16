/*
  编写一个程序。按照下列要求，创建一个含有两个成员的结构模板：
  a.第一个成员是社会保障号；第二个成员是一个含三个成员的结构。它的第一个成员是名，第二个
成员是名和姓中间的数字，最后一个成员是姓。创建并初始化一个含有5个此类结构的数组。程序以下
列形式输出数据：
  Dribble,Flossie M, - 302039823
  名和姓中间的名字只输出了它的第一个字母，后面加了一个句点。如果姓名中间的名字为空，那么它
的第一个字母和句点都不会输出（当然喽）。写一个函数来实现输出，把数据数组传递给这个函数。
  b.修改a部分，传递结构的值而不是结构地址。
*/
#include <stdio.h>

#define MAX 20



//结构模版
struct names{
  char firstname[MAX];
  char middlename[MAX];
  char lastname[MAX];
};

//结构模版
struct persons{
    int number;
    struct names name;
};

void display(struct persons *p);

//声明并初始化结构体
struct persons person[5] = {
  {302039823,{"Dribble","Mackede","Flossie"}},
  {345345345,{"gadenfs","Kasdfas","Pszajkh"}},
  {302039823,{"Kazsdfj","Aasdfaf","Mjasdfh"}},
  {302039824,{"Qaadsef","","Yjsjdsh"}},
  {302039825,{"Bsdsdfs","Fsjdsdd","Rshdsdf"}}
};

int main(void)
{
    display(person);

    return 0;
}

/* 打印结构体数组中的数据 */
void display(struct persons *p)
{
    int i;
    for(i = 0;i < 5;i++)
      if(p[i].name.middlename[0] != '\0')
        printf("%s,    %s    %c.    -    %d\n",p[i].name.firstname,
        p[i].name.lastname,p[i].name.middlename[0],p[i].number);
      else
        printf("%s,%s    -    %d\n",p[i].name.firstname,
        p[i].name.lastname,p[i].number);
}
