#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void qsort(void* base, size_t num, size_t size, int (*cmp)(const void*, const void*));
//base是待排序数据的起始地址
//num待排序数据的元素个数
//size是待排序数据元素的大小(字节)
//int (*cmp)(const void*, const void*) 比较2个元素大小的函数指针
int cmp_int(const void* e1, const void* e2)
{
	return (*(int*)e1 - *(int*)e2); 
}


void print(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}


void test1()
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


int cmp_struct_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
	//strcmp的返回值和qsort函数的返回值一样
}

int cmp_struct_age(const void* e1, const void* e2)
{
	return (((struct Stu*)e1)->age - ((struct Stu*)e2)->age);
}

void print_stu(struct Stu *s, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%s %d\n", s->name, s->age);
	}
}

void test2()
{
	struct Stu s[] = { {"zhangsan",20},{"list",20},{"wangyu",40} };
	//按照名字比较
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_struct_name);
	//按照年龄比较
	qsort(s, sz, sizeof(s[0]), cmp_struct_age);
	print_stu(s, sz);
}


int main()
{
	//整型使用方法
	test1();
	//结构体使用方法
	test2();
	return 0;
}