#include<stdio.h>
//2.3.1 while循环

//在屏幕上打印1-10的数字
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		printf("%d ", i);
//		i++;
//	}
//	return 0;
//}


//while循环中的break
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)
//			break;     //i等于5的时候，直接跳出循环
//		printf("%d ", i);    //1 2 3 4
//		i++;
//	}
//	return 0;
//}
//总结☆
//while中的break是用于永久终止循环的。


//while循环中的continue介绍
//continue 代码实例1
//int main()
//{
//	int i = 1;
//	while (i <= 10)
//	{
//		if (i == 5)     //当i等于5时，continue直接跳过后面的语句，i永远等于5，无限循环
//			continue;
//		printf("%d ", i);     //1 2 3 4 + 死循环不打印
//		i++;
//	}
//	return 0;
//}

//continue 代码实例2
//int main()
//{
//    int i = 1;
//    while (i <= 10)
//    {
//        i++;
//        if (i == 5)
//            continue;
//        printf("%d ", i);  //2 3 4 6 7 8 9 10
//    }
//    return 0;
//}
//结论☆ 
//continue是用于终止本次循环的，也就是本次循环中continue后边的代码不会再执行
//而是直接跳转到while语句的判断部分。进行下一次循环的入口判断。