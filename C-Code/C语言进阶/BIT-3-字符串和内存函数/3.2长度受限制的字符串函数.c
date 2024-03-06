#include<stdio.h>
#include<string.h>
//1.strncpy
/*
char * strncpy ( char * destination, const char * source, size_t num );
·拷贝num个字符从源字符串到目标空间。
·如果源字符串的长度小于num，则拷贝完源字符串之后，在目标的后边追加0，直到num个。
int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "xxxx";
	strncpy(arr1, arr2, 2);  //xxcdef  只拷贝2个字符
	//strncpy(arr1, arr2, 8);  //xxxx
	printf("%s\n", arr1);
	return 0;
}
*/


//2.strncat 
//char * strncat ( char * destination, const char * source, size_t num );
/*
int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "xyz";
	strncat(arr1, arr2, 2);  //2表示追加2个字符
	printf("%s\n", arr1);  //abcdefxy
	return 0;
}
*/

//自己追加自己
/*
int main()
{
	char arr1[20] = "abc";
	char arr2[] = "xyz";
	strncat(arr1, arr1, 3);  //2表示追加2个字符
	printf("%s\n", arr1);  //abcabc
	return 0;
}
*/


//strncmp
//int strncmp ( const char * str1, const char * str2, size_t num );
/*
int main()
{
	int ret = strncmp("abcdef", "abc", 3);  //3表示比较前三个
	printf("%d\n", ret);  //0

	ret = strncmp("abcdef", "abc", 4);
	printf("%d\n", ret);  //1
	return 0;
}
*/
