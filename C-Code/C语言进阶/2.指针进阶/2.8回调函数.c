#include<stdio.h>
#include<stdlib.h>
/*
回调函数就是一个通过函数指针调用的函数。如果你把函数的指针（地址）作为参数传递给另一个
函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。回调函数不是由该函数
的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进
行响应。
*/


/*
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("                          \n");
	printf("       1.add  2.sub       \n");
	printf("       3.mul  4.div       \n");
	printf("       0.exit             \n");
	printf("                          \n");
}

//存放函数地址的函数
void calc(int (*p)(int, int))
{
	int x = 0;
	int y = 0;
	int ret = 0;
	printf("请输入两个操作数;>");
	scanf_s("%d %d", &x, &y);
	ret = p(x, y);   //p为函数指针
	printf("%d\n", ret);
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			calc(Add);   //将Add传给别的函数作为函数参数，Add为回调函数
			break;
		case 2:
			calc(Sub);
			break;
		case 3:
			calc(Mul);
			break;
		case 4:
			calc(Div);
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	} while (input);
	return 0;
}
*/


//1.演示一下qsort函数的使用：
//qsort - c语言标准库提供的排序函数~    快速排序的思想
//bubble_sort 只能排序整型的数组
//qsort可以排序任意类型的数据
/*
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2);  //升序
	//return (*(int*)e2 - *(int*)e1);  //降序
}

void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

//测试qsort函数排序整型数据
void test()
{
	int arr[] = { 2,1,3,7,5,9,6,8,0,4 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);
}

struct Stu
{
	char name[20];
	int age;
};

int cmp_stu_by_name(const void* e1,const void* e2)   //结构体
{
	//按照名字来排序
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name); //strcmp返回值为>0 ==0  <0
}

int cmp_stu_by_age(const void* e1, const void* e2)
{
	//按照年龄来排
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}

//测试qsort排序结构体数据
void test1()
{
	struct Stu s[] = { {"zhangsan",20},{"lisi",55},{"wangwu",40} };
	//假设按照名字比较
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_name);
	//按照年龄来排
	qsort(s, sz, sizeof(s[0]), cmp_stu_by_age);
}
//void qsort(void* base, size_t num, size_t size, int (*cmp)(const void*, const void*));

//base是待排序数据的起始地址
//num待排序数据的元素个数
//size是待排序数据元素的大小(字节)
//int (*cmp)(const void*, const void*) 比较2个元素大小的函数指针
//2个整型使用关系运算符比较大小
//2个字符串，使用strcmp比较大小
//2个结构体，也得制定比较方式


int main()
{
	test();
	test1();
	char ch = 'w';
	int i = 20;
	float* pf = &i;   //类型不兼容
	void* p = &ch;    //没有问题 - 但是void* 的指针没法解引用  可以强制类型转换成整型指针 *(int *)p
	p = &i;           //void* 指针也不能++ --
	//void* 可以接收任何类型的地址  这也是他的唯一优点
	return 0;
}
*/


//2.改写冒泡排序，使得冒泡排序可以适用于任何类型变量
/*
void Swap(char* buf1, char* buf2, int width)   //交换的地址中的内容
{
	int i = 0;
	for (i = 0; i < width; i++)   //width代表字节数  每循环一次 交换一次字节数 这样不同类型都能交换
	{
		//交换一个字节的值
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
{
	int i = 0;
	//趟数
	for (i = 0; i < sz - 1; i++)
	{
		//一趟冒泡排序的过程
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (cmp((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
			}
		}
	}
}
*/
