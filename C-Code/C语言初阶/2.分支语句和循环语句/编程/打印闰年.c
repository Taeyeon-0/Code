/*
思路：
要求1000年到2000年之间的闰年，只需要知道求解闰年的方法即可。
闰年的条件：如果N能够被4整除，并且不能被100整除，则是闰年
		   或者：N能被400整除，也是闰年
	 即：4年一润并且百年不润，每400年再润一次
*/


#include <stdio.h>
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		//判断year是否为闰年
		if (year % 4 == 0)  // 如果year能够被4整除，year可能为闰年
		{
			if (year % 100 != 0) // 如果year不能内100整除，则一定是闰年
			{
				printf("%d ", year);
			}
		}
		if (year % 400 == 0)  // 每400年再润一次
		{
			printf("%d ", year);
		}
	}


	return 0;
}


//
//介绍一下这种的简单写法
//
int main()
{
	int year = 0;
	for (year = 1000; year <= 2000; year++)
	{
		if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		{
			printf("%d ", year);
		}
	}

	return 0;
}