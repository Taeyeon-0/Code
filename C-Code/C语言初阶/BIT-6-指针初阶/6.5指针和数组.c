#include<stdio.h>
/*
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
	printf("%p\n", arr);  //000000A27759FB68
	printf("%p\n", &arr[0]);   //000000A27759FB68
	//结论：数组名表示的是数组首元素的地址。
	return 0;
}
*/


//既然可以把数组名当成地址存放到一个指针中，我们使用指针来访问一个就成为可能。
/*
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
	int* p = arr; //指针存放数组首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("&arr[%d] = %p   <====> p+%d = %p\n", i, &arr[i], i, p + i);
	}
	return 0;
}
*/

//所以 p+i 其实计算的是数组 arr 下标为i的地址。
//那我们就可以直接通过指针来访问数组。


/*
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	int* p = arr; //指针存放数组首元素的地址
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(p + i));
	}
	return 0;
}
*/
