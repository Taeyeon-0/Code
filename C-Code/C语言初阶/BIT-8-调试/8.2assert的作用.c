//模拟实现strcpy
#include<stdio.h>
#include<string.h>
#include<assert.h>
void my_strcpy1(char* dest, char* src)
{
	while (*src!='\0')
	{
		*dest++ = *src++;
	}
	*dest = *src;   //*src中放的是\0
}


//优化代码
void my_strcpy2(char* dest, char* src)
{
	while (*dest++ = *src++)  //当stc为\0时，表达式为0，循环结束
	{
		;
	}	
}


//继续优化
void my_strcpy3(char* dest, char* src)
{
	//程序不能由空指针，有的话就报错
	//assert(dest);   //dest！=NULL   NULL为0 所以可以省略 断言
	//assert(src);    //断言
	assert(dest && src); //dest和src都不为NULL
	while (*dest++ = *src++)  //当stc为\0时，表达式为0，循环结束
	{
		;
	}
}


//最终优化
char* my_strcpy(char* dest, const char* src)
{
	//加上const  下面代码会报错， 不加的话 不会
	/*while (*src++ = *dest++)  
	{
		;
	}*/
	char* ret = dest;   //函数返回的时起始数组的首地址 所以提前保存在ret里
	assert(dest && src); //dest和src都不为NULL
	while (*dest++ = *src++)  //当stc为\0时，表达式为0，循环结束
	{
		;
	}
	return ret;
}


int main()
{
	char arr1[20] = "xxxxxxxx";
	//xxxxxxxxxx为了观察是否覆盖\0
	char arr2[] = "hello";
	char* p = NULL;
	//strcpy(arr1, arr2);
	//my_strcpy1(arr1, arr2);
	//my_strcpy2(arr1, arr2);
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}



/*模拟实现strlen优化
int my_strlen(const char* str)
{
	assert(str);
	int count = 0;
	while (*str)
	{
		count++;
		str++;
	}
	return count;
}
*/
