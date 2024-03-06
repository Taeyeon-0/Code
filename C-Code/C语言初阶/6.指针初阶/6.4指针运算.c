#include<stdio.h>
#define N_VALUES 5
/*
·指针 + -整数
·指针 - 指针
·指针的关系运算
*/


//1.指针 + -整数
/*
int main()
{
	double arr[5] = { 0 };
	double* p = arr;
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%lf \n", *(p + i));
	}
	return 0;
}
*/


/*
int main()
{
	float values[N_VALUES];
	float* vp;
	//指针+-整数；指针的关系运算
	for (vp = &values[0]; vp < &values[N_VALUES];)
	{
		*vp++ = 0;
		//*vp++  == *(vp++)   这个是地址++
		//(*vp++)  不同这个是数值++
	}
	return 0;
}
*/


//2.指针-指针
/*
指针+指针？？？  不存在
日期-日期  = 天数     日期+日期？？
int main()
{
	//两个指针相减的前提是：指针指向的是同一块连续的空间
	int arr[10] = { 0 };
	printf("%d\n", &arr[9] - &arr[0]);  //9
	printf("%d\n", &arr[0] - &arr[9]);  //-9

	int a = 10;
	char c = 'w';
	printf("%d\n", &a - &c);   //错误，不同类型的地址
	return 0;
}
*/

//1.计数器
/*
int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
*/

//2.递归

//3.指针-指针
/*
int my_strlen(char* str)
{
	char* start = str;
	while (*str)     //*str != '\0' == *str     \0 ==0
	{
		str++;
	}
	return str - start;
}

int main()
{
	char arr[] = "abcdef";
	int len = my_strlen(arr);
	printf("%d\n", len);
	return 0;
}
*/


//3.指针的关系运算
/*
int main()
{
	float values[N_VALUES];
	float* vp;
	for (vp = &values[N_VALUES]; vp > &values[0];)
	{
		*--vp = 0;
	}
	//代码简化
	//for (vp = &values[N_VALUES - 1]; vp >= &values[0]; vp--)
	//{
	//	*vp = 0;
	//}

	//实际在绝大部分的编译器上是可以顺利完成任务的，然而我们还是应该避免这样写，因为标准并不保证它可行。
	//标准规定：
	//允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置的指针比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行比较。(向前越界)
	return 0;
}
*/
