#include<stdio.h>
//1.结构的基础知识
//结构是一些值的集合，这些值称为成员变量。结构的每个成员可以是不同类型的变量。
/*
复杂对象  人：名字+年龄+电话+住址     
结构体struct-描述复杂对象
*/


//2.结构的声明
//描述一个学生  名字+年龄+性别+身高
/*
struct Stu
{
	char name[20];  //名字
	int age;       //年龄
	char sex[5];  //性别
	float hight;   //身高
}s1,s2,s3;   //全局变量
struct Stu s5;    //全局变量

int main()
{
	struct Stu s4;   //局部变量
	return 0;
}

*/


//3.结构成员的类型 
// 结构的成员可以是标量、数组、指针，甚至是其他结构体。


//4 结构体变量的定义和初始化
/*
struct Point
{
	int x;
	int y;
};

struct S
{
	char c;
	struct Point p;   //结构体嵌套
	double d;
	char str[20];
};

struct Stu
{
	char name[20];  //名字
	int age;       //年龄
	char sex[5];  //性别
	float hight;   //身高
};

int main()
{
	struct Point p = { 10,20 };
	printf("x=%d y=%d\n", p.x, p.y);

	struct Stu s = { "zhangsan",20,"男",180 };
	printf("%s %d %s %f\n", s.name, s.age, s.sex, s.hight);

	struct S ss = { 'x',{100,200},3.14,"hehe" };
	printf("%c %d %d %lf %s\n", ss.c, ss.p.x, ss.p.y, ss.d, ss.str);
	struct S ss = { .d = 3.14,.c = 'x',.p.x = 100 };  //乱序初始化需要.加变量名
	return 0;
}
*/
