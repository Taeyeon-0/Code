#include<stdio.h>
char* my_strcat(char* arr1, char* arr2)
{
	char* ret = arr1;
	while (*arr1)
	{
		arr1++;
	}
	while (*arr2)
	{
		*arr1++ = *arr2++;
	}
	return ret;
}


int main()
{
	char arr1[99] = "Hello ";
	char arr2[] = "World!";
	printf("%s\n", my_strcat(arr1, arr2));
}