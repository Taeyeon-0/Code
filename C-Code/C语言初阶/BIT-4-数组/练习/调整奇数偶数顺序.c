#include<stdio.h>
/*
Adjust(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		if (arr[i] % 2 == 0)
		{
			int j = i + 1;
			while (arr[j] % 2 == 0)
			{
				j++;
			}

			if (j < sz)
			{
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}

		}
	}
}


int main()
{
	int arr[10] = { 0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	Adjust(arr, sz);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}
*/

//优化
#include<stdio.h>
void print(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}

void move_even_odd(int* arr, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		//从前找到一个偶数停下来
		while ((left < right) && arr[left] % 2 == 1)
		{
			left++;
		}
		//从后往前找到一个奇数停下来
		while ((left < right) && arr[right] % 2 == 0)
		{
			right--;
		}


		if (left < right)
		{
			int tmp = arr[right];
			arr[right] = arr[left];
			arr[left] = tmp;
			left++;
			right--;
		}
	}
}

int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print(arr, sz);
	move_even_odd(arr, sz);
	print(arr, sz);
	return 0;
}