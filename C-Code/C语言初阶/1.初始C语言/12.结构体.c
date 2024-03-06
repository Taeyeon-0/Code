#include<stdio.h>
struct Stu
{
	char name[20];
	int age;
	char sex[5];
	char id[12];
};


void print(struct Stu* ps)    //结构体指针
{
	//结构体指针变量解引用.结构体成员
	printf("%s %d %s %s\n", (*ps).name, (*ps).age, (*ps).sex, (*ps).id);
	//结构体指针变量->结构体成员
	printf("%s %d %s %s\n", ps->name, ps->age, ps->sex, ps->id);
}

//int main()
//{
//	struct Stu s = { "zhangsan",18,"nan","20220402"};
//	//结构体变量.结构体成员
//	printf("%s %d %s %s\n", s.name, s.age, s.sex, s.id);
//	print(&s);   //结构体指针
//	return 0;
//}


//输入结构体
int main()
{
	struct Stu s = { 0 };
	//输入
	scanf("%s %s %s %d", s.name, s.sex, s.id, &(s.age));
	//结构体变量.结构体成员
	printf("%s %d %s %s\n", s.name, s.age, s.sex, s.id);
	print(&s);   //结构体指针
	return 0;
}