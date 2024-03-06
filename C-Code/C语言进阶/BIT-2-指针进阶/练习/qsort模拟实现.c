#include<stdio.h>
#include<stdlib.h>
//模仿qsort的功能实现一个通用的冒泡排序
void Swap(char* buf1, char* buf2, int width)   //交换的地址中的内容
{
	int i = 0;
	for (i = 0; i < width; i++)   //width代表字节数  每循环一次 交换一次字节数 这样不同类型都能交换
	{
		//交换一个字节的值  如果是整型 则width等于4  则交换4个字节的值
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

int cmp_int(const void* e1, const void* e2) 
{
	//如果e1>e2 的话 return 1  e1<e2的话return -1
	return (*(int*)e1) - (*(int*)e2); 
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

void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 3,6,9,7,4,1,2,5,8 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
	print(arr, sz);
	return 0;
}