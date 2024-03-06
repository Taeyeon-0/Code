#include<stdio.h>
/*
struct S
{
	char name[20];
	int age;
};

int main()
{
	struct S s = { .age = 20,.name = "zhangsan" };
	printf("%s %d\n", s.name, s.age);   //zhangsan 20
	s.age = 30;  //可行
	//s.name = "zhangsanfeng";  //name是个数组 是首元素地址 不可以直接赋值
	strcpy(s.name, "zhangsanfeng");   //解决方法
	printf("%s %d\n", s.name, s.age);   //zhangsanfeng 30
	return 0;
}
*/


//结构体传参
/*
struct S
{
	int data[1000];
	char buf[100];
};

//结构体变量.结构体成员名
//结构体指针->结构体成员名
void print1(struct S s)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", s.data[i]);   // 1 2 3 0 0 0 0 0 0 0
	}
	printf("%s\n", s.buf);  // hehe
}

void print2(struct S* ps)
{
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->data[i]);  // 1 2 3 0 0 0 0 0 0 0
	}
	printf("%s\n",ps->buf);  // hehe
}

int main()
{
	struct S s = { {1,2,3},"hehe" };
	print1(s);   //传值调用
	print2(&s);  //传址调用
	return 0;
}
*/

//函数传参的时候，参数是需要压栈的。
//如果传递一个结构体对象的时候，结构体过大，参数压栈的的系统开销比较大，所以会导致性能的下降。
//结论：结构体传参的时候，要传结构体的地址。