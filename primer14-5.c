/*
  写一个程序，满足下列要求：
  a.外部定义一个name结构模板，它含有2个成员：一个字符串用于存放名字，另一个字符串
  用于存放姓氏。
  b.外部定义一个student结构模板，它含有3个成员：一个name结构，一个存放3个浮点数
  分数的grade数组，以及一个存放这3个分数的平均分的变量。
  c.使main()函数声明一个具有CSIZE(CSIZE=4)个student结构的数组，并随意初始化
  这些结构的名字部分。使用函数来执行d、e、f以及g部分所描述的任务。
  d.请求用户输入学生姓名和分数，以交互地获取每个学生的成绩。将分数放到相应结构的
  grade数组成员中。您可以自主选择在main()或一个函数中实现这个循环。
  e.为每个结构计算平均分，并把这个值赋给适合的成员。
  f.输出每个结构中的信息。
  g.输出结构的每个数值成员的班级平均分。
*/
#include <stdio.h>

#define CSIZE 4

struct name{
  char firstName[20];
  char lastName[20];
};

struct student{
  struct name name;
  double grade[3];
  double average;
};

void inputStudent(struct student student[CSIZE]);
void printStudent(struct student student[CSIZE]);
double average(struct student student[CSIZE]);

int main(void)
{
  struct student student[CSIZE];

  inputStudent(student);  //输入学生姓名，成绩
  printStudent(student);  //打印学生姓名，成绩
  printf("Class average score = %.2lf\n",average(student));
  return 0;
}

/* 输入学生数据 */
void inputStudent(struct student student[CSIZE])
{
    int i;
    for(i = 0; i < CSIZE;i++)
    {
      printf("input student firstname:");
      scanf("%s",student[i].name.firstName);
      printf("input student lasttname:");
      scanf("%s",student[i].name.lastName);

      printf("input student grade（include 1、2、3）:");
      scanf("%lf %lf %lf",&student[i].grade[0]
                         ,&student[i].grade[1]
                         ,&student[i].grade[2]);
      student[i].average = (student[i].grade[0]+student[i].grade[1]
                           +student[i].grade[2])/3;
    }
}

/* 打印学生数据 */
void printStudent(struct student student[CSIZE])
{
    int i;
    for(i = 0; i < CSIZE;i++)
    {
        printf("student name:%s %s\n",
              student[i].name.firstName,student[i].name.lastName);
        printf("grade(1~3):%.2lf %.2lf %.2lf\n",
              student[i].grade[0],student[i].grade[1],student[i].grade[2]);
        printf("average:%.2lf\n",student[i].average);
    }
}

/* 计算班级平均分 */
double average(struct student student[CSIZE])
{
    double temp = 0;
    int i;
    for(i = 0;i < CSIZE;i++)
    {
        temp = temp + student[i].average;
    }

    return temp/CSIZE;
}
