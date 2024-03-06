#include<stdio.h>
//1.冒泡排序函数的错误设计
//方法1：
//void bubble_sort(int arr[])
//{
//    int sz = sizeof(arr) / sizeof(arr[0]);//这样对吗？
//    int i = 0;
//    for (i = 0; i < sz - 1; i++)
//    {
//        int j = 0;
//        for (j = 0; j < sz - i - 1; j++)
//        {
//            if (arr[j] > arr[j + 1])
//            {
//                int tmp = arr[j];
//                arr[j] = arr[j + 1];
//                arr[j + 1] = tmp;
//            }
//        }
//    }
//}
// 
//int main()
//{
//    int arr[] = { 3,1,7,5,8,9,0,2,4,6 };
//    int i = 0;
//    bubble_sort(arr);//是否可以正常排序？
//    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
//    {
//        printf("%d ", arr[i]);
//    }
//    return 0;
//}
//方法1，出问题，那我们找一下问题，调试之后可以看到 bubble_sort 函数内部的 sz ，是1。
//难道数组作为函数参数的时候，不是把整个数组的传递过去？


//2.数组名是什么？
//int main()
//{
//    int arr[10] = { 1,2,3,4,5 };
//    printf("%p\n", arr);   //000000B2383BF8F8
//    printf("%p\n", &arr[0]);   //000000B2383BF8F8
//    printf("%d\n", *arr);   //1
//    return 0;
//}
//数组名是数组首元素的地址。


//int main()
//{
//    int arr[10] = { 0 };
//    printf("%zd\n", sizeof(arr));  //40
//    return 0;
//}
//补充：
//1. sizeof(数组名)，计算整个数组的大小，sizeof内部单独放一个数组名，数组名表示整个数组。
//2. &数组名，取出的是数组的地址。 &数组名，数组名表示整个数组。
//除此1, 2两种情况之外，所有的数组名都表示数组首元素的地址。


//冒泡排序的正确设计
//当数组传参的时候，实际上只是把数组的首元素的地址传递过去了。
//所以即使在函数参数部分写成数组的形式： int arr[] 表示的依然是一个指针： int* arr 。
//那么，函数内部的 sizeof(arr) 结果是4。
//如果 方法1 错了，该怎么设计？

//方法2
void bubble_sort(int arr[], int sz)
{
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        int j = 0;
        for (j = 0; j < sz - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int main()
{
    int arr[] = { 3,1,7,5,8,9,0,2,4,6 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    int i = 0;
    bubble_sort(arr, sz);//是否可以正常排序？
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}