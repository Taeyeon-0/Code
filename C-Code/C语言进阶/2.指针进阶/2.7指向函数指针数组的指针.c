#include<stdio.h>
/*
指向函数指针数组的指针是一个 指针
指针指向一个 数组 ，数组的元素都是 函数指针;
*/

void test(const char* str)
{
	printf("%s\n", str);
}
int main()
{
	//函数指针pfun
	void (*pfun)(const char*) = test;
	//函数指针的数组pfunArr
	void (*pfunArr[5])(const char* str);
	pfunArr[0] = test;
	//指向函数指针数组pfunArr的指针ppfunArr
	void (*(*ppfunArr)[5])(const char*) = &pfunArr;
	return 0;
}