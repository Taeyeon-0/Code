#include<stdio.h>
char* my_strcpy(char* arr1, const char* arr2)
{
	char* ret = arr1;
	while (*arr2 != '\0')
	{
		*arr1++ = *arr2++;
	}
	return ret;
}


int main()
{
	char arr1[20] = "xxxx";
	char arr2[] = "Hello World!";
	printf("%s", my_strcpy(arr1, arr2));
	return 0;
}