#include<stdio.h>
//11.1指针
//int main()
//{
//    int num = 10;
//    &num;//取出num的地址
//    //注：这里num的4个字节，每个字节都有地址，取出的是第一个字节的地址（较小的地址）
//    printf("%p\n", &num);//打印地址，%p是以地址的形式打印
//    return 0;
//}


//定义指针变量
//int num = 10;
//int* p;   //p为一个整形指针变量
//p = &num;


//指针的使用
//int main()
//{
//    int num = 10;
//    int* p = &num;
//    *p = 20;    //p是地址   对地址解引用操作 可以操作p地址的数据  更改num的数据
//    printf("%d", num);
//    return 0;
//}


//其他指针类型
//int main()
//{
//    char ch = 'w';
//    char* pc = &ch;    //ch的地址 为字符指针类型
//    *pc = 'q';       //对字符指针pc解引用，改变ch的值
//    printf("%c\n", ch);
//    return 0;
//}


//11.2 指针变量的大小
//指针变量的大小取决于地址的大小
//32位平台下地址是32个bit位（即4个字节）
//64位平台下地址是64个bit位（即8个字节）
//int main()
//{
//    printf("%d\n", sizeof(char*));
//    printf("%d\n", sizeof(short*));
//    printf("%d\n", sizeof(int*));
//    printf("%d\n", sizeof(double*));
//    return 0;
//}