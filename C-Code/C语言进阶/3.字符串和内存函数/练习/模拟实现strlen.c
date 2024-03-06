#include<stdio.h>
#include<string.h>
size_t my_strlen(char* arr)
{
	size_t count = 0;
	while (*arr)
	{
		arr++;
		count++;
	}
	return count;
}


int main()
{
	char arr[] = "abc";
	printf("%zu\n", my_strlen(arr));
	return 0;
}