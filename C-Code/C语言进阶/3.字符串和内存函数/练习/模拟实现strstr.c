#include<stdio.h>
char* my_strstr(char* str1, char* str2)
{
	const char* s1 = str1;
	const char* s2 = str2;
	char* p = str1;
	while (*p != '\0')  //p是str1数组中的位置 只要位置没有到\0 就继续寻找
	{
		s1 = p;   //每次匹配不到新的字符串就p++ 找下一个地址 放到s1中
		s2 = str2;  //str2每次匹配不到相同的字符串 就回到初始位置 放到s2中
		while (*s1 != '\0' && *s2 != '\0' && (*s1 == *s2))  //当s1和s2相等时就 s1和s2加加 继续判断字符相等
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')  //如果s2等于\0 说明s2中的字符和s1中的字符都相等  就找到了 而地址就是p p保存了s1中字符串的起始地址
		{
			return p;    //找到了
		}
		p++;  //每次循环判断结束后，就p++开始从下一个地址开始找
	}
	return NULL;  //找不到字符串
}

int main()
{
	char arr1[] = "HelloWorld";    //
	char arr2[] = "orl";
	char*p = my_strstr(arr1, arr2);
	if (p = NULL)
		printf("不存在\n");
	else
		printf("存在\n");
	return 0;
}