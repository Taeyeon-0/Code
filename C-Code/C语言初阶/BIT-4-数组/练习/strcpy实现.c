#include<stdio.h>
void my_strcpy(char* arr1, char* arr2)
{
	while (*arr2 != '\0')
	{
		*arr1 = *arr2;
		arr1++;
		arr2++;
	}
	*arr1 = '\0';
}


int main()
{
	char arr1[99] = { 0 };
	char arr2[] = "Hello World!";
	my_strcpy(arr1, arr2);
	puts(arr1);
	return 0;
}