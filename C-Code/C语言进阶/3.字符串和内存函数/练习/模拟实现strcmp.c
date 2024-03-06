#include<stdio.h>
int my_strcmp(char* arr1, char* arr2)
{
	while (*arr1 == *arr2)
	{
		arr1++;
		arr2++;
		if (*arr1 == '\0')
			return 0;
	}
	
	return *arr1 - *arr2;
}


int main()
{
	char arr1[] = "abcd";
	char arr2[] = "abce";
	int ret = my_strcmp(arr1, arr2);
	if (ret > 0)
		printf("arr1>arr2\n");
	else if (ret < 0)
		printf("arr1<arr2\n");
	else
		printf("arr1==arr2\n");
	return 0;
}