#include<stdio.h>
/*
int main()
{
	//整型数组-存放整型的数组
	int arr[10];
	//字符数组-存放字符的数组
	char arr2[5];
	//指针数组-存放指针的数组
	int* arr3[5];   //存放整型指针的数组
	char* arr4[6];   //存放字符指针的数组
	return 0;
}
*/


/*
int main()
{
	int a = 10;
	int b = 20;
	int c = 30;
	int d = 40;
	int e = 50;
	int* arr3[5] = { &a,&b,&c,&d,&e };  //存放整型指针的数组
	int i = 0;
	for (i = 0; i < 5; i++)
	{
		printf("%d ", *(arr3[i]));  //10 20 30 40 50
	}
	return 0;
}

*/


/*
int main()
{
	//用一维数组模拟一个二维数组
	int arr1[] = { 1,2,3,4,5 };
	int arr2[] = { 2,3,4,5,6 };
	int arr3[] = { 3,4,5,6,7 };
	int arr4[] = { 4,5,6,7,8 };
	int* arr[4] = { arr1, arr2, arr3, arr4 };  //指针、
	int i = 0;
	for (i = 0; i < 4; i++)
	{
		int j = 0;
		for (j = 0; j < 5; j++)
		{
			printf("%d ", arr[i][j]);
			//printf("%d ", *(*(arr+i)+j));
			//*(arr+i)找到arr1 arr2 arr3 arr4  *（arr1+j）找到列的值
		}
		printf("\n");
	}
	return 0;
}
*/
