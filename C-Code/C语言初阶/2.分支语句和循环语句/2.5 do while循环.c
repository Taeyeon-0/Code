#include<stdio.h>
//1.do语句的特点
//循环至少执行一次，使用的场景有限，所以不是经常使用。
//int main()
//{
//    int i = 1;
//    do
//    {
//        printf("%d ", i);
//        i++;
//    } while (i <= 10);
//    return 0;
//}


//2.do while循环中的break和continue
//int main()
//{
//    int i = 1;
//    do
//    {
//        if (5 == i)
//            break;
//        printf("%d ", i);   //1 2 3 4
//        i++;
//    } while (i <= 10);
//
//    return 0;
//}


//int main()
//{
//    int i = 1;
//    do
//    {
//        if (5 == i)
//            continue;
//        printf("%d ", i); // 1 2 3 4 + 死循环
//        i++;
//    } while (i <= 10);
//
//    return 0;
//}