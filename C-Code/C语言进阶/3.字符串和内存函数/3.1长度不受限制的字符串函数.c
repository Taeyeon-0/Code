#include<stdio.h>
#include<string.h>
#include<assert.h>
//C语言中对字符和字符串的处理很是频繁，但是C语言本身是没有字符串类型的，
//字符串通常放在常量字符串 中或者 字符数组 中。
//字符串常量 适用于那些对它不做修改的字符串函数.
//1.strlen - strint lenth - 求字符串长度的，统计的是字符串中\0之前的字符个数
//参数指向的字符串必须要以 '\0' 结束。
//注意函数的返回值为size_t，是无符号的（ 易错 ）
//size_t strlen ( const char * str );
/*
int main()
{
	//a b c d e f \0
	char arr[] = "abcdef";
	//char arr[] = { 'a','b','c' };  //err  随机的数字
	printf("%d", strlen(arr)); //6
	return 0;
}
*/

/*
int main()
{
	if (strlen("abc") - strlen("abcdef") > 0)  //strlen返回的是无符号整型，不会出现负数
		printf(">");
	else
		printf("<");
	return 0;
}
*/


//模拟strlen 返回值size_t
/*
size_t my_strlen(const char* str)
{
	assert(str); //str!=NU;LL
	const char* start = str;
	const char* end = str;
	while (*end != '\0')
	{
		end++;
	}
	return end - start;
}


int main()
{
	char arr[] = "abcdef";
	size_t len = my_strlen(arr);
	printf("%zu\n", len);
	return 0;
}
*/


//2.strcpy
//char* strcpy(char * destination, const char * source );
/*
·源字符串必须以 '\0' 结束。
·会将源字符串中的 '\0' 拷贝到目标空间。
·目标空间必须足够大，以确保能存放源字符串。
·目标空间必须可变。
*/
/*
int main()
{
	char arr[10] = "xxxxxxxxxx";
	//char arr[3]={ 0 };  //数组空间太小
	//char* p = "hello world"; //err 常量字符串地址
	const char* p = "abcdef";
	strcpy(arr, p);
	printf("%s\n", arr);
	return 0;
}
*/

//模拟strcpy的实现
/*
char* my_strcpy(char* dest, const char* src)
{
	assert(dest);  //dest！=NULL
	assert(src);
	char* ret = dest;   //dest会在下面循环时候改变 所以地址存放在ret中
	while (*dest++ = *src++)   //直到\0 赋值过去 表达式为假
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[20] = "abc";
	char arr2[] = "hello bit";
	printf("%s\n", my_strcpy(arr1, arr2));
	return 0;
}
*/


//3.strcat - 字符串追加函数模拟
//char * strcat ( char * destination, const char * source );
/*
char* my_strcat(char* dest, const char* src)
{
	//1.找目标空间的\0
	char* cur = dest;
	while (*dest != '\0')
	{
		dest++;
	}
	//2.拷贝源头数据到\0之后的空间
	while (*dest++ = *src++);
	return cur;
}

int main()
{
	char arr1[20] = "hello \0xxxxx";
	char arr2[] = "world";
	printf("%s\n", my_strcat(arr1, arr2));
	return 0;
}
*/


//4.strcmp - 字符串比较
/* 标准规定
第一个字符串大于第二个字符串，则返回大于0的数字
第一个字符串等于第二个字符串，则返回0
第一个字符串小于第二个字符串，则返回小于0的数字
strcmp比较的是对应位置上字符的大小，而非长度
int strcmp ( const char * str1, const char * str2 );
*/
//模拟实现strcmp
/*
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1 - *str2;
}

int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "abcdef";
	int ret = my_strcmp(arr1, arr2);
	if (ret < 0)
		printf("arr1<arr2\n");
	else if (ret > 0)
		printf("arr1>arr2\n");
	else
		printf("arr1==arr2\n");
	return 0;
}
*/
