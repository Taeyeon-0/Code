#include<stdio.h>
//1.使用for循环在屏幕上打印1-10的数字
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		printf("%d ", i);
//	}
//	return 0;
//}


//2.break和continue在for循环中
//代码1
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			break;
//		printf("%d ", i);   //1 2 3 4
//	}
//	return 0;
//}

//代码2
//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 10; i++)
//	{
//		if (i == 5)
//			continue;
//		printf("%d ", i);   // 1 2 3 4 6 7 8 9 10
//	}
//	return 0;
//}


//3.for循环的的变种
//int main()
//{
//    //代码1
//    for (;;)
//    {
//        printf("hehe\n");
//    }
//    //for循环中的初始化部分，判断部分，调整部分是可以省略的，但是不建议初学时省略，容易导致问题。
//
//        //代码2
//    int i = 0;
//    int j = 0;
//    //这里打印多少个hehe?
//    for (i = 0; i < 10; i++)
//    {
//        for (j = 0; j < 10; j++)
//        {
//            printf("hehe\n");   //100次hhe
//        }
//    }
//
//    //代码3
//    int i = 0;
//    int j = 0;
//    //如果省略掉初始化部分，这里打印多少个hehe?
//    for (; i < 10; i++)
//    {
//        for (; j < 10; j++)
//        {
//            printf("hehe\n");    //10次hehe   j没有初始化
//        }
//    }
//
//    //代码4-使用多余一个变量控制循环
//    int x, y;
//    for (x = 0, y = 0; x < 2 && y < 5; ++x, y++)
//    {
//        printf("hehe\n");
//    }
//    return 0;
//}



//★笔试题
//int main()
//{
//    int i = 0;
//    int k = 0;
//    for (i = 0, k = 0; k = 0; i++, k++)    //0次  k=0 为假 不进行循环   如果k等于非零，则是死循环
//        k++;
//    return 0;
//}