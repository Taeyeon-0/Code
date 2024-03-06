#include<stdio.h>
/*
int main()
{
	char ch = 'w';
	char* pc = &ch;

	const char* ps = "abcdef";  //把abcdef字符串中的a地址放到ps中
	//*ps = 'w';    //常量字符串不能修改

	printf("%c\n", *ps);  //a
	return 0;
}
*/


/*面试题
int main()
{
    char str1[] = "hello bit.";
    char str2[] = "hello bit.";
    const char* str3 = "hello bit.";
    const char* str4 = "hello bit.";
    if (str1 == str2)
        printf("str1 and str2 are same\n");
    else
        printf("str1 and str2 are not same\n");

    if (str3 == str4)    //str3 和 str4是常量字符串 常量字符同名的话地址相同
        printf("str3 and str4 are same\n");
    else
        printf("str3 and str4 are not same\n");
    //str1 and str2 are not same
    //str3 and str4 are same
    return 0;
}
这里str3和str4指向的是一个同一个常量字符串。C/C++会把常量字符串存储到单独的一个内存区域，当几个指针。
指向同一个字符串的时候，他们实际会指向同一块内存。但是用相同的常量字符串去初始化不同的数组的时候就会开辟出不同的内存块。
所以str1和str2不同，str3和str4不同。
*/
//如果要比较字符串的内容 要使用是strcmp函数