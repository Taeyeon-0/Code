#include<stdio.h>
//9.1 关键字typedef
//将unsigned int 重命名为uint_32, 所以uint_32也是一个类型名
//typedef unsigned int uint_32;
//int main()
//{
//    //观察num1和num2,这两个变量的类型是一样的
//    unsigned int num1 = 0;
//    uint_32 num2 = 0;
//    return 0;
//}


//9.2 关键字static
//static是用来修饰变量和函数的
//1. 修饰局部变量 - 称为静态局部变量
//2. 修饰全局变量 - 称为静态全局变量
//3. 修饰函数 - 称为静态函数

//9.2.1 static修饰局部变量
//void test1()
//{
//    int i = 0;
//    i++;
//    printf("%d ", i);
//}
//
//void test2()
//{
//    static int i = 0;  //static修饰的局部变量
//    i++;
//    printf("%d ", i);
//}
//
//
//int main()
//{
//    int i = 0;
//    for (i = 0; i < 10; i++)
//    {
//        test1();
//    }
//
//    printf("\n");
//
//    for (i = 0; i < 10; i++)
//    {
//        test2();
//    }
//    return 0;
//}
//结论：
//static修饰局部变量改变了变量的生命周期
//让静态局部变量出了作用域依然存在，到程序结束，生命周期才结束。


//9.2.2 static修饰全局变量
//代码1
//add.c
//int g_val = 2018;
////test.c
//int main()
//{
//    printf("%d\n", g_val);
//    return 0;
//}
//
////代码2
////add.c
//static int g_val = 2018;   //static修饰全局变量
////test.c
//int main()
//{
//    printf("%d\n", g_val);
//    return 0;
//}
//代码1正常，代码2在编译的时候会出现连接性错误。
//★一个全局变量被static修饰，使得这个全局变量只能在本源文件内使用，不能在其他源文件内使用。


//9.2.3 static修饰函数
//代码1
//add.c
//int Add(int x, int y)
//{
//    return x + y;
//}
////test.c
//int main()
//{
//    printf("%d\n", Add(2, 3));
//    return 0;
//}

//代码2
//add.c
//static int Add(int x, int y)   //static修饰函数
//{
//    return x + y;
//}
////test.c
//int main()
//{
//    printf("%d\n", Add(2, 3));
//    return 0;
//}
//代码1正常，代码2在编译的时候会出现连接性错误.
//★一个函数被static修饰，使得这个函数只能在本源文件内使用，不能在其他源文件内使用。