#include<stdio.h>
#include<windows.h>
int main()
{
    char arr1[] = "welcome to bit!!!";
    char arr2[] = "                 ";
    int left = 0;
    int right = strlen(arr1) - 1;       //字符串长度
    //int right = sizeof(arr1) / sizeof(arr1[0]) - 1;       //整个数组的长度，如果数组没有完全初始化，就错误
    printf("%s\n", arr2);
    //while循环实现
    while (left <= right)
    {
        Sleep(500);      //sleep函数的头文件windows.h
        arr2[left] = arr1[left];
        arr2[right] = arr1[right];
        left++;
        right--;
        printf("%s\n", arr2);
    }
    return 0;
}