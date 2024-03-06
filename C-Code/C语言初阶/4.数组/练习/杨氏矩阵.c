#include <stdio.h>
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
//要求：时间复杂度小于O(N);   不能简单的遍历数组

void find_num_in_young(int arr[3][3], int k, int *px, int *py)
{
    int i = 0;
    int j = *py - 1; // c=3  j=2
    int flag = 0;
    while (i <= *px - 1 && j >= 0)
    {
        //从一个矩阵中的最右边和k判断
        if (arr[i][j] < k) //右上角下标
        {
            i++;
        }
        else if (arr[i][j] > k)
        {
            j--;
        }
        else
        {
            flag = 1;
            *px = i;
            *py = j;
            break;
        }
    }
    if (flag == 0)
    {
        *px = -1;
        *py = -1;
    }
}

int main()
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int k = 0;
    scanf("%d", &k); //输入要查找的数字
    //遍历数组
    int x = 3;
    int y = 3;
    find_num_in_young(arr, k, &x, &y);
    if (x == -1 && y == -1)
        printf("找不到\n");
    else
        printf("找到了，下标是：%d %d", x, y);
    return 0;
}

/*
1 2 3
4 5 6
7 8 9
*/
//假设找7