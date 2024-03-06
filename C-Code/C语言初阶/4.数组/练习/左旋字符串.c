#include <stdio.h>
#include <string.h>
#include <assert.h>
//字符串左旋
/*
实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB */
/*
void left_move(char *arr, int k)
{
    //每一次只旋转一个字符，把这个动作执行k次
    int i = 0;
    int len = strlen(arr);
    k %= len; //当k大于len的时候 也就是左旋了很多次 超过了字符串，就没有意义了，截断掉没有意义的
    for (i = 0; i < k; i++)
    {
        char tmp = arr[0]; // 1
        // 2.把后边的字符全部往前挪动一个位置
        int j = 0;
        for (j = 0; j < len - 1; j++)
        {
            arr[j] = arr[j + 1];
        }
        // 3.
        arr[len - 1] = tmp;
    }
} */

//代码优化 左边逆序 右边逆序  整体逆序 就达到了左旋
void reverse(char *left, char *right)
{
    assert(left && right);
    while (left < right)
    {
        char tmp = *left;
        *left = *right;
        *right = tmp;
        left++;
        right--;
    }
}

void left_move(char *arr, int k)
{
    int i = 0;
    int len = strlen(arr);
    k %= len;
    reverse(arr, arr + k - 1);       //左边逆序
    reverse(arr + k, arr + len - 1); //右边逆序
    reverse(arr, arr + len - 1);     //整体逆序
}

int main()
{
    char arr[] = "abcdefghi";
    int k = 0;
    scanf("%d", &k);
    left_move(arr, k);
    printf("%s", arr);
    return 0;
}