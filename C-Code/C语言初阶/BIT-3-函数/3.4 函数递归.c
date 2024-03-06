#include<stdio.h>
//1.什么是递归？
//程序调用自身的编程技巧称为递归（ recursion）。
//只需少量的程序就可描述出解题过程所需要的多次重复计算，大大地减少了程序的代码量。
//递归的主要思考方式在于：把大事化小


//2.递归的两个必要条件
//存在限制条件，当满足这个限制条件的时候，递归便不再继续。
//每次递归调用之后越来越接近这个限制条件。


//练习1
//接受一个整型值（无符号），按照顺序打印它的每一位。
//输入：1234，输出 1 2 3 4
//void print(int num)
//{
//	if (num > 9)
//	{
//		print(num / 10);     //1234 递归123 12  1
//	}
//	printf("%d", num % 10);   
//}
//
//
//int main()
//{
//	int num = 1234;
//	print(num);
//	return 0;
//}


//练习2
//编写函数不允许创建临时变量，求字符串的长度。
//int Strlen(char* arr)
//{
//	if (*arr != '\0')
//	{
//		return Strlen(arr + 1) + 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//
//int main()
//{
//	char arr[] = "bit";    
//	int len = Strlen(arr);
//	printf("%d", len);
//	return 0;
//}


//练习3
//求n的阶乘。（不考虑溢出）
//int factorial(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return n * factorial(n - 1);
//	
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = factorial(n);
//	return 0;
//}



//练习4 求第n个斐波那契数。（不考虑溢出）
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = Fib(n);
//	printf("%d", ret);
//	return 0;
//}

//提示：
//1. 许多问题是以递归的形式进行解释的，这只是因为它比非递归的形式更为清晰。
//2. 但是这些问题的迭代实现往往比递归实现效率更高，虽然代码的可读性稍微差些。
//3. 当一个问题相当复杂，难以用迭代实现时，此时递归实现的简洁性便可以补偿它所带来的运行时开销。