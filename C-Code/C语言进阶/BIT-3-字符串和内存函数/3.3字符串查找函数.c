#include <stdio.h>
#include <string.h>
// 1.strstr
//在一个字符串找另一个字符串是否存在
//存在：返回的字串所在的第一次出现的起始地址(一个字符串str1可能出现2次以上的str2)
//不存在：返回NULL
//在abcdefabcdef 寻找fab
// char * strstr ( const char *str1, const char * str2);
/*
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "bcd";
	char* p = strstr(arr1, arr2);
	if (p == NULL)
		printf("不存在\n");
	else
		printf("存在位置：%s\n", p);
	return 0;
}
*/

//模拟实现strstr 这个较难
/*
char* my_strstr(const char* str1, const char* str2)
{
	const char* s1 = str1;
	const char* s2 = str2;
	char* p = str1;
	while (*p!='\0')  //p是str1数组中的位置 只要位置没有到\0 就继续寻找
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

//还有别的算法 KMP算法 难度较大
int main()
{
	char arr1[] = "abcdef";
	char arr2[] = "bcd";
	char* p = my_strstr(arr1, arr2);
	if (p == NULL)
		printf("不存在\n");
	else
		printf("存在位置：%s\n", p);
	return 0;
}
*/

// 2.strtok
// char * strtok ( char * str, const char * sep );
/*
sep参数是个字符串，定义了用作分隔符的字符集合  sep指向了分隔符
第一个参数指定一个字符串，它包含了0个或者多个由sep字符串中一个或者多个分隔符分割的标记。
strtok函数找到str中的下一个标记，并将其用 \0 结尾，返回一个指向这个标记的指针。
（注：strtok函数会改变被操作的字符串，所以在使用strtok函数切分的字符串一般都是临时拷贝的内容并且可修改。）
strtok函数的第一个参数不为 NULL ，函数将找到str中第一个标记，strtok函数将保存它在字符串中的位置。
strtok函数的第一个参数为 NULL ，函数将在同一个字符串中被保存的位置开始，查找下一个标记。
如果字符串中不存在更多的标记，则返回 NULL 指针。
*/

/* 一般不怎么写
int main()
{
	char arr[] = "zpengwei@bitedu.com"; //@ 和. 是分隔符
	char buf[200] = {0};  //zpengwei@bitedu.com
	strcpy(buf, arr);
	// zpengwei   bitedu  com  提取出这三个字符串 使用strtok
	const char *p = "@.";
	char* str = strtok(buf, p);
	puts(str);

	str = strtok(NULL,p);
	puts(str);

	str = strtok(NULL,p);
	puts(str);
	return 0;
}
*/

/*改写代码
int main()
{
	char arr[] = "zpengwei@bitedu.com";
	char buf[200] = {0};
	strcpy(buf, arr);
	const char *p = "@.";
	char *str = NULL;
	for (str = strtok(buf, p); str != NULL; str = strtok(NULL, p))
	{
		puts(str);
	}
	return 0;
}
*/
