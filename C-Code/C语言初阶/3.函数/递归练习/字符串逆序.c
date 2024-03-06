#include<stdio.h>
int my_strlen(char* str)
{
	int count = 0;
	while (*str != '\0')
	{
		count++;
	}
	return count;
}


void reverse_string(char* str)
{
	int len = my_strlen(str);
	//1.a和f交换
	char tmp = *str;
	*str = *(str + len - 1);    //-1是因为数组的下标从0开始
	//2.将bcde后面的一个字符置为\0 否则无法进行下一次递归
	*(str + len - 1) = '\0';
	//3.进行bcde的递归
	if (*(str + 1) != '\0')
	{
		reverse_string(str + 1);
	}
	//最后进行交换
	*(str + len - 1) = tmp;   //最后交换的原因是怕*(str+len-1)被置换成\0
}


int main()
{
	char arr[] = "abcdef";   //a和f交换 +bcde的递归
	reverse_string(arr);
	puts(arr);
	return 0;
}