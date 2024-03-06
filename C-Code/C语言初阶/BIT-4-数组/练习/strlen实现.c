#include<stdio.h>
int my_strlen(char* arr)
{
	int count = 0;
	while (*arr != '\0')
	{
		count++;
		arr++;
	}
	return count;
}


int main()
{
	char arr[] = "Hello World!";
	printf("%d", my_strlen(arr));
	return 0;
}