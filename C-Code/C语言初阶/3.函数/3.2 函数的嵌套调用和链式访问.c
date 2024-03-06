#include<stdio.h>
//3.2.1 嵌套调用
//void new_line()
//{
//    printf("hehe\n");
//}
//
//void three_line()
//{
//    int i = 0;
//    for (i = 0; i < 3; i++)
//    {
//        new_line();
//    }
//}
//
//int main()
//{
//    three_line();
//    return 0;
//}
//函数可以嵌套调用，但是不能嵌套定义。


//3.2.2 链式访问 - 
//把一个函数的返回值作为另外一个函数的参数。
//#include <string.h>
//int main()
//{
//    char arr[20] = "hello";
//    int ret = strlen(strcat(arr, "bit"));    //strcat连接   hellobit   8个字符
//    printf("%d\n", ret);
//    return 0;
//}


//int main()
//{
//    printf("%d", printf("%d", printf("%d", 43)));    //4321
//    //结果是啥？
//    //注：printf函数的返回值是打印在屏幕上字符的个数
//    return 0;
//}